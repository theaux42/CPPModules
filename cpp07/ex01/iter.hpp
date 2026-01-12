#ifndef ITER_HPP
# define ITER_HPP

#include <iostream>

template <typename T1, typename T2, typename F>
void iter(T1 *array, const T2 len, F func)
{
    for (T2 i = 0; i < len; i++)
        func(array[i]);
}

#endif