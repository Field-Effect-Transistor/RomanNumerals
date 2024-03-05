#pragma once
#include "Roman.hpp"

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

Roman::Roman(const char*  RomanNumber){
    if(RomanNumber == nullptr)
        return;
    for(auto ptr = RomanNumber; *ptr != '\0'; ++ptr)
    
        if(getPrice(*ptr) >= getPrice(*(ptr + 1)))
            ++roman[*ptr];
        else
            --roman[*ptr];

}

    Roman::Roman(std::string RomanNumber): Roman(RomanNumber.c_str());
    Roman::Roman(): Roman(nullptr);
