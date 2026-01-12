#include "iter.hpp"

void multiply(int &a)
{
    a = a * 2;
}

void    to_upper(char &c)
{
    if (c >= 'a' && c <= 'z')
        c = c - 32;
}

void    print_char(const char c)
{
    std::cout << c << std::endl;
}

int main(void)
{
    int numbers[5] = {2, 4, 6, 8, 16};
    char string[13] = "Hello World!";

    for (int i = 0; i < 5; i++)
        std::cout << numbers[i] << " ";
    std::cout << std::endl;
    
    std::cout << string << std::endl;
    
    iter(numbers, 5, multiply);
    iter(string, 13, to_upper);

    std::cout << string << std::endl;
    
    for (int i = 0; i < 5; i++)
        std::cout << numbers[i] << " ";
    
    std::cout << std::endl;
    
    iter(string, 13, print_char);
    
    return (0);
}