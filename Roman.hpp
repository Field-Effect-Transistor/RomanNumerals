#pragma once

#include <string>
#include <fstream>

#include "Roman.cpp"

#define ABS(x) ((x) < 0 ? -(x) : (x))
#define SIGN(x) ((x) < 0 ? true : false)

enum price {pI = 1, pV = 5, pX = 10, pL = 50, pC = 100, pD = 500, pM = 1000};

inline short int getPrice(const char c);

class Roman
{
private:
public:
    const char* letters = "IVXLCDM";
    int letterCounts[7] = {0, 0, 0, 0, 0, 0, 0};
    bool SF = false;
    void normalize(void);

public:
    Roman(const char*  romanNumber);
    Roman(unsigned int integer, bool SF = false);
    Roman(int integer): Roman(ABS(integer), SIGN(integer)) {};
    Roman(): Roman(nullptr) {};
    Roman(const Roman& parent);
    ~Roman() {};

    unsigned int getIntegerView();
    const char* getStringView();

    //streams
    friend std::ostream& operator<<(std::ostream& os, const Roman& roman);
    friend std::istream& operator>>(std::istream& is, Roman& roman);
    
    //operators
    const Roman operator=(const Roman& parent);
    friend Roman operator-(const Roman& decreasing, const Roman& denominator);
    friend Roman operator+(const Roman& summand1, const Roman& summand2);

    //bool
    friend const bool operator==(const Roman& expression1, const Roman& expression2);
    friend const bool operator!=(const Roman& expression1, const Roman& expression2);
    friend const bool operator<(const Roman& expression1, const Roman& expression2);
    friend const bool operator<=(const Roman& expression1, const Roman& expression2);
    friend const bool operator>(const Roman& expression1, const Roman& expression2);
    friend const bool operator>=(const Roman& expression1, const Roman& expression2);
};