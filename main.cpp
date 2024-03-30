#include <iostream>

#include "Roman.cpp"

int main(void)
{

    //const char* test = "XIV";
    Roman roman;

    std::cin >> roman;
    
    Roman clone = roman;
    
    std::cout << roman << std::endl;
    std::cout << clone.getStringView() << std::endl;

    return 0;
}