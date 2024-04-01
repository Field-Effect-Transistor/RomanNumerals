#pragma once

#include <string>
#include <fstream>

#include "Roman.cpp"

enum price {pI = 1, pV = 5, pX = 10, pL = 50, pC = 100, pD = 500, pM = 1000};

inline short int getPrice(const char c);

class Roman
{
private:
//public:
    const char* letters = "IVXLCDM";
    int letterCounts[7] = {0, 0, 0, 0, 0, 0, 0};

    void normalize(void);

public:
    Roman(const char*  romanNumber);
    Roman(unsigned int integer);
    Roman(): Roman(nullptr) {};
    Roman(const Roman& parent);
    ~Roman() {};

    unsigned int getIntegerView();
    const char* getStringView();

    friend std::ostream& operator<<(std::ostream& os, const Roman& roman);
    friend std::istream& operator>>(std::istream& is, Roman& roman);
    const Roman operator=(const Roman& parent);
    friend Roman operator-(const Roman& decreasing, const Roman& denominator);
    friend Roman operator+(const Roman& summand1, const Roman& summand2);
};