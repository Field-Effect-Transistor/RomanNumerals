#include "iostream"
#include "Roman.cpp"

int main(void)
{

    const char* test = "XIX";
    Roman roman(test);
    std::cout << roman.roman['I'] << std::endl;
    std::cout << roman.roman['V'] << std::endl;
    std::cout << roman.roman['X'] << std::endl;
    std::cout << roman.roman['L'] << std::endl;
    std::cout << roman.roman['C'] << std::endl;
    std::cout << roman.roman['D'] << std::endl;
    std::cout << roman.roman['M'] << std::endl;
    return 0;
}