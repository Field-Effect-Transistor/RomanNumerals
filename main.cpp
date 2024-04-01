#include <iostream>

#include "Roman.cpp"

int main(void)
{

    //const char* test = "";

    //std::cin >> roman;
    
    //Roman clone = roman;
    
    for(int i = -2; i < 3; ++i)
        for(int j = -2; j < 3; ++j)
            std::cout << i << " , " << j <<':'<< std::endl
                    << "==\t" << (Roman(i) == Roman(j)) << std::endl
                    << "!=\t" << (Roman(i) != Roman(j)) << std::endl
                    << ">\t" << (Roman(i) > Roman(j)) << std::endl
                    << "<\t" << (Roman(i) < Roman(j)) << std::endl
                    << std::endl;

    return 0;
}