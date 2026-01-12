#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <iostream>

template <typename T> 
class Array
{
    private:
        T *_array;
        unsigned int _size;
    public:
        Array(void) : _array(NULL), _size(0) {}
        Array(unsigned int n);
        ~Array();

        Array(const Array &src);
        Array &operator=(const Array &rhs);

        unsigned int    size(void) const;
        void            printDebug(const std::string name);

        T &operator[](unsigned int index);

        class OOBException : public std::exception {
            const char * what() const throw()
            {
                return "[Error] Bounds violation detected!";
            }
        };
};

#include "Array.tpp"

#endif