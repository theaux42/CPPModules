#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP 

#include <iostream>
#include <stdint.h>

struct Data
{
    std::string s1;
    std::string s2;
    int         i1;
    bool        b1;
};

class Serializer
{
    private:
        Serializer(void) {}; 
        Serializer(const Serializer &src) { *this = src; };
        Serializer &operator=(const Serializer &rhs) { (void)rhs; return *this; }
        ~Serializer(void) {};
        
    public:
        static uintptr_t serialize(Data* ptr);
        static Data* deserialize(uintptr_t raw);
};

#endif