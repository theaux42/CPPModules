#ifndef SPAN_HPP
# define SPAN_HPP

#include <algorithm>
#include <iostream>

class Span 
{
    private:
        unsigned int _size;

    public:
        Span(void) : _size(10) {};
        Span(unsigned int size) : _size(size) {};
        ~Span(void) {};  

        Span(const Span &src);
        Span &operator=(const Span &src);

        addNumber(int number);
        shortestSpan(void);
        longestSpan(void);
};

#endif