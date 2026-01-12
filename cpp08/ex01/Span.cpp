#include "Span.hpp"

Span::Span(const Span &src)
{
    this->_size = src._size;
}

Span &Span::operator=(const Span &src)
{
    if (this != &src)
    {
        this->_size = src._size;
    }
    return (*this);
}
