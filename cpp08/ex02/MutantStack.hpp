#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include <algorithm>
#include <iostream>
#include <stack>

template <class T >
class MutantStack : public std::stack<T>
{
  public:
    typedef typename std::stack<T>::container_type::iterator iterator;

    MutantStack(void) : std::stack<T>() {};
    MutantStack(const MutantStack &src) : std::stack<T>(src) {};
    ~MutantStack(void) {};

    MutantStack &operator=(const MutantStack &src) {
        if (this != &src) {
            std::stack<T>::operator=(src);
        }
        return (*this);
    }

    iterator begin() {
        return this->c.begin();
    }

    iterator end() {
        return this->c.end();
    }

};

#endif