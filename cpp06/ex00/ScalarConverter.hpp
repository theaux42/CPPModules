#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include <iostream>
#include <sstream>
#include <iomanip>
#include <climits>

# define IMPOSSIBLE_INPUT "Error: This input cannot be converted!"
# define WRONG_USAGE "Error: Wrong usage: ./ScalarConverter <value>"

enum Input_Type
{
    NONE,
    PLUS_PL,
    MINUS_PL,
    NAN_PL,
    CHAR,
    INT,
    FLOAT,
    DOUBLE,
};


class ScalarConverter 
{
    private:
	~ScalarConverter(void) {};
        ScalarConverter(void) {};
        ScalarConverter(const ScalarConverter &src) {*this = src;};
        ScalarConverter &operator=(const ScalarConverter &rhs) {(void)rhs; return *this;};
    public:
        static int convert(std::string str);
};

#endif
