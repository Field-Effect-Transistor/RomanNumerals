#pragma once

#include "Roman.hpp"

#define ABS(x) ((x) < 0 ? -(x) : (x))

inline short int getPrice(const char c){
    switch(c){
        case 'I': return pI;
        case 'V': return pV;
        case 'X': return pX;
        case 'L': return pL;
        case 'C': return pC;
        case 'D': return pD;
        case 'M': return pM;
        default: return 0;
    }
}

inline short int getLetterPosition(const char c){
    switch(c){
        case 'I': return 0;
        case 'V': return 1;
        case 'X': return 2;
        case 'L': return 3;
        case 'C': return 4;
        case 'D': return 5;
        case 'M': return 6;
        default:  return 7;
    }
}

Roman::Roman(const char*  romanNumber){
    if(romanNumber != nullptr){
        const char* ptr = romanNumber;
        if(*ptr == '-' && *ptr != '\0'){
            SF = true;
            ++ptr;
        } 
        for(; *ptr != '\0'; ++ptr){
            if(getPrice(*ptr) >= getPrice(*(ptr + 1)))
                ++letterCounts[getLetterPosition(*ptr)];
            else
                --letterCounts[getLetterPosition(*ptr)];
        }
    normalize();
    }
}

Roman::Roman(unsigned int integer){
    for(auto ptr = letters + 6; ptr >= letters; --ptr)
        if(integer >= getPrice(*ptr)){
            letterCounts[getLetterPosition(*ptr)] = integer / getPrice(*ptr);
            integer %= getPrice(*ptr);
        }
    normalize();
}

Roman::Roman(const Roman& parent){
    SF = parent.SF;
    for(int i = 0; i < 7; ++i)
        this->letterCounts[i] = parent.letterCounts[i];
}

unsigned int Roman::getIntegerView(){
    unsigned int result = 0;

    for(auto ptr = letters; *ptr != '\0'; ++ptr)
        result += letterCounts[getLetterPosition(*ptr)] * getPrice(*ptr);

    return result;
}

const char* Roman::getStringView(){
    Roman clone(*this);

    unsigned int size = 0;
    for(auto letterCount: clone.letterCounts)
        size += ABS(letterCount);
    if(clone.SF)
        size += 1;

    char* result = new char[size + 1];
    if(clone.SF)
        result[0] = '-';
    result[size] = '\0';
    
    unsigned int currPos = size - 1;
    for(auto ptr = clone.letters; *ptr != '\0'; ++ptr){
        if(clone.letterCounts[getLetterPosition(*ptr)] > 0)
            for(int i = 0; i < clone.letterCounts[getLetterPosition(*ptr)]; ++i)
                result[currPos--] = *ptr;
        if(clone.letterCounts[getLetterPosition(*ptr)] < 0){
            for(auto ptr1 = ptr + 1; *ptr1 != '\0'; ++ptr1)
                if(clone.letterCounts[getLetterPosition(*ptr1)] > 0){
                --clone.letterCounts[getLetterPosition(*ptr1)];
                result[currPos--] = *ptr1;
                break;
            }
            result[currPos--] = *ptr;
        }
    }

    return result;
}

std::ostream& operator<<(std::ostream& os, const Roman& roman){
    Roman temp(roman);
    return os << temp.getStringView();
}

std::istream& operator>>(std::istream& is, Roman& roman){
    std::string str;
    is >> str;
    roman = Roman(str.c_str());
    return is;
}


const Roman Roman::operator=(const Roman& parent){
    for(int i = 0; i < 7; ++i)
        this->letterCounts[i] = parent.letterCounts[i];
    return *this;
}

void Roman::normalize(){
    int temp;
    for(int i = 0; letters[i + 1] != '\0'; ++i){
        if(temp = (letterCounts[i] * getPrice(letters[i])) / getPrice(letters[i + 1])){
            letterCounts[i + 1] += temp;
            letterCounts[i] = (letterCounts[i] * getPrice(letters[i])) % getPrice(letters[i + 1]) / getPrice(letters[i]);
        }
        if(letterCounts[i] >= 4 - 2 * (i % 2)){
            letterCounts[i] = -1;
            letterCounts[i + 1] += 1;
        }
    }
}

Roman operator-(const Roman& decreasing, const Roman& denominator){
    Roman difference(decreasing);
    for(int i = 0; i < sizeof(difference.letterCounts) / sizeof(difference.letterCounts[0]); ++i)
        difference.letterCounts[i] -= denominator.letterCounts[i];
    difference.normalize();
    return difference;
}

Roman operator+(const Roman& summand1, const Roman& summand2){
//    if(summand1.SF == summand2.SF)

/*
    Roman sum(summand1);
    for(int i = 0; i < sizeof(sum.letterCounts) / sizeof(sum.letterCounts[0]); ++i)
        sum.letterCounts[i] += summand2.letterCounts[i];
    sum.normalize();
    return sum;
//*/
}