#pragma once
#include <string>
#include <map>
#include "Roman.cpp"

enum price {pI = 1, pV = 5, pX = 10, pL = 50, pC = 100, pD = 500, pM = 1000};

inline short int getPrice(const char c);

class Roman
{
    //private:
    public:
    std::map<char, int> roman = {
        {'I', 0}, 
        {'V', 0}, 
        {'X', 0}, 
        {'L', 0}, 
        {'C', 0}, 
        {'D', 0}, 
        {'M', 0}
    };    

    public:
    Roman(const char*  RomanNumber);
    Roman(): Roman(nullptr) {};

    ~Roman() {};

};