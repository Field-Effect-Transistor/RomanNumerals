#include "iostream"
#include "Roman.cpp"

int main(void)
{

    const char* test = "XXI";
    Roman roman(test);
    
    Roman clone(roman);
    
    std::cout << roman.getIntegerView() << std::endl;
    std::cout << clone.getStringView() << std::endl;

    return 0;
}