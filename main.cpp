#include <iostream>

#include "Roman.cpp"

int main(void)
{

    //const char* test = "XIV";
    Roman roman(1);
    Roman roman1(9);
    //std::cin >> roman;
    
    Roman clone = roman;
    
    std::cout << roman - roman1 << std::endl;

    return 0;
}