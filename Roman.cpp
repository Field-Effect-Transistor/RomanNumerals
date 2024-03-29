#pragma once
#include "Roman.hpp"
#define ABS(x) ((x) < 0 ? -(x) : (x))
/**
 * Returns the price associated with the given Roman numeral character.
 * @param c the Roman numeral character
 * @return the price associated with the Roman numeral character
 */
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
    if(romanNumber == nullptr)
        return;
   for(auto ptr = romanNumber; *ptr != '\0'; ++ptr){
        if(getPrice(*ptr) >= getPrice(*(ptr + 1)))
            ++letterCounts[getLetterPosition(*ptr)];
        else
            --letterCounts[getLetterPosition(*ptr)];
   }
}

Roman::Roman(const Roman& parent){
    letterCounts[0] = parent.letterCounts[0];
    letterCounts[1] = parent.letterCounts[1];
    letterCounts[2] = parent.letterCounts[2];
    letterCounts[3] = parent.letterCounts[3];
    letterCounts[4] = parent.letterCounts[4];
    letterCounts[5] = parent.letterCounts[5];
    letterCounts[6] = parent.letterCounts[6];
}

unsigned int Roman::getIntegerView(){
    unsigned int result = 0;

    for(auto ptr = letters; *ptr != '\0'; ++ptr)
        result += letterCounts[getLetterPosition(*ptr)] * getPrice(*ptr);

    return result;
}

const char* Roman::getStringView(){
    unsigned int size = 0;
    for(auto letterCount: letterCounts)
        size += ABS(letterCount);
    
    char* result = new char[size + 1];
    result[size] = '\0';
    
    return result;
}

std::ostream& operator<<(std::ostream& os, const Roman& roman){
    for(int i = 6; i >= 0; --i)
        for(int j = 0; j < roman.letterCounts[i]; ++j)
            os << roman.letters[i];

    return os;
}