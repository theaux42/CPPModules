/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbabou <tbabou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 15:34:50 by tbabou            #+#    #+#             */
/*   Updated: 2025/08/27 15:51:57 by tbabou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

void ScalarConverter::convert(const char *literal)
{
    std::string strLiteral(literal);

    // Check for special floating-point values
    if (strLiteral == "nan" || strLiteral == "nanf") {
        std::cout << "char: impossible\n";
        std::cout << "int: impossible\n";
        std::cout << "float: nanf\n";
        std::cout << "double: nan\n";
        return;
    }
    if (strLiteral == "+inf" || strLiteral == "+inff" || strLiteral == "inf" || strLiteral == "inff") {
        std::cout << "char: impossible\n";
        std::cout << "int: impossible\n";
        std::cout << "float: +inff\n";
        std::cout << "double: +inf\n";
        return;
    }
    if (strLiteral == "-inf" || strLiteral == "-inff") {
        std::cout << "char: impossible\n";
        std::cout << "int: impossible\n";
        std::cout << "float: -inff\n";
        std::cout << "double: -inf\n";
        return;
    }

    char *endPtr = nullptr;
    double value = strtod(literal, &endPtr);

    // Check if the entire string was converted
    if (*endPtr != '\0' && !(*endPtr == 'f' && *(endPtr + 1) == '\0')) {
        std::cerr << "Error: Invalid literal format.\n";
        return;
    }

    // Convert to char
    if (value < 0 || value > 127 || isnan(value)) {
        std::cout << "char: impossible\n";
    } else if (!isprint(static_cast<char>(value))) {
        std::cout << "char: Non displayable\n";
    } else {
        std::cout << "char: '" << static_cast<char>(value) << "'\n";
    }

    // Convert to int
    if (value < static_cast<double>(INT_MIN) || value > static_cast<double>(INT_MAX) || isnan(value)) {
        std::cout << "int: impossible\n";
    } else {
        std::cout << "int: " << static_cast<int>(value) << "\n";
    }

    // Convert to float
    float fValue = static_cast<float>(value);
}

ScalarConverter::ScalarConverter() {};
ScalarConverter::~ScalarConverter() {};
ScalarConverter::ScalarConverter(ScalarConverter const & src) {};
ScalarConverter & ScalarConverter::operator=(ScalarConverter const & rhs) {};
