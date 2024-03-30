#pragma once

#include <string>
#include <fstream>

#include "Roman.cpp"

enum price {pI = 1, pV = 5, pX = 10, pL = 50, pC = 100, pD = 500, pM = 1000};

inline short int getPrice(const char c);

class Roman
{
    public:
    Roman(const char*  romanNumber);
    Roman(): Roman(nullptr) {};
    Roman(const Roman& parent);
    ~Roman() {};

    unsigned int getIntegerView();
    const char* getStringView();

    public:
    private:
    const char* letters = "IVXLCDM";
    int letterCounts[7] = {0, 0, 0, 0, 0, 0, 0};

    protected:
    friend std::ostream& operator<<(std::ostream& os, const Roman& roman);
    friend std::istream& operator>>(std::istream& is, Roman& roman);
    const Roman& operator=(const Roman& parent);
};