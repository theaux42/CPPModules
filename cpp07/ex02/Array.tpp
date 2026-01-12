#include "Array.hpp"

template <typename T>
inline Array<T>::Array(unsigned int n)
{
    _size = n;
    _array = new T[n];
}

template <typename T>
inline Array<T>::~Array()
{
    if (this->_array != NULL)
        delete[] _array;
}

template <typename T>
inline Array<T>::Array(const Array &src)
{
    _size = src._size;
    _array = new T[_size];
    for (unsigned int i = 0; i < _size; i++)
        _array[i] = src._array[i];
}

template <typename T>
inline Array<T> &Array<T>::operator=(const Array &rhs)
{
    if (this != &rhs)
    {
        delete[] this->_array;
        this->_size = rhs._size;
        this->_array = new T[this->_size];
        for (unsigned int i = 0; i < this->_size; i++)
            this->_array[i] = rhs._array[i];
    }
    return *this;
}

template <typename T>
inline unsigned int Array<T>::size(void) const
{
    return _size;
}

template <typename T>
inline void Array<T>::printDebug(const std::string name)
{   
    std::cout << "The array named \"" << name << "\" have a size of : " << this->_size << std::endl;
    for (long int i = 0; i < this->_size; i++)
        std::cout << "n" << i << " -> " << this->_array[i] << std::endl;
}

template <typename T>
inline T &Array<T>::operator[](unsigned int index)
{
    if (index >= this->_size)
        throw Array::OOBException();
    return _array[index];
}
