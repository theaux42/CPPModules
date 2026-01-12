#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <algorithm>
#include <vector>
#include <iostream>

class TargetNotFoundException : public std::exception {
    const char * what() const throw() {
        return "[Error] The target has been not found.";
    }
};

template <typename T>
int easyfind(const T &vec, int target)
{
    typename T::const_iterator it = std::find(vec.begin(), vec.end(), target);
    if (it != vec.end())
        return static_cast<int>(std::distance(vec.begin(), it));
    throw TargetNotFoundException();
};

#endif