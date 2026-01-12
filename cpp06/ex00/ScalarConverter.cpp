#include "ScalarConverter.hpp"

static void convertChar(std::string str, Input_Type type)
{
    double value;

    if ((type >= PLUS_PL && type <= NAN_PL))  { std::cout << "char: impossible" << std::endl; return; }
    if (type == CHAR)  { std::cout << "char: '" << str[0] << "'" << std::endl; return; }
    if (type == DOUBLE)
        ;
    else if (type == FLOAT)
        value = 0.0f;
    else
        value = 0;
    std::istringstream str_stream(str);
    str_stream >> value;
    if (value < -1 || value > 255)
        std::cout << "char: impossible" << std::endl;
    else if (value < 32 || value > 126)
        std::cout << "char: Non displayable" << std::endl;
    else
        std::cout << "char: '" << static_cast<char>(value) << "'" << std::endl;
}

// Impossible on PL
static void convertInt(std::string str, int isPseudo)
{
    if (isPseudo >= PLUS_PL && isPseudo <= NAN_PL) std::cout << "int: impossible" << std::endl;
    else
    {
        long int value;
        std::string number_as_text(str);
        std::istringstream number_stream(number_as_text);
        number_stream >> value;
        if (number_stream.fail())
            std::cout << "int: impossible" << std::endl;
        else
            std::cout << "int: " << std::setprecision(1) << std::fixed << value << std::endl;
    }
}

static void convertDouble(std::string str, int isPseudo)
{
    if (isPseudo == PLUS_PL) std::cout << "double: +inf" << std::endl;
    else if (isPseudo == MINUS_PL) std::cout << "double: -inf" << std::endl;
    else if (isPseudo == NAN_PL) std::cout << "double: nan" << std::endl;
    else
    {
        double value;
        std::string number_as_text(str);
        std::istringstream number_stream(number_as_text);
        number_stream >> value;
        if (number_stream.fail())
            std::cout << "double: impossible" << std::endl;
        else
            std::cout << "double: " << std::setprecision(1) << std::fixed << value << std::endl;
    }
}

static void convertFloat(std::string str, int isPseudo)
{
    if (isPseudo == PLUS_PL) std::cout << "float: +inff" << std::endl;
    else if (isPseudo == MINUS_PL) std::cout << "float: -inff" << std::endl;
    else if (isPseudo == NAN_PL) std::cout << "float: nanf" << std::endl;
    else
    {
        float value;
        std::string number_as_text(str);
        std::istringstream number_stream(number_as_text);
        number_stream >> value;
        if (number_stream.fail())
            std::cout << "float: impossible" << std::endl;
        else
            std::cout << "float: " << std::setprecision(1) << std::fixed << value << "f" << std::endl;
    }
}

static Input_Type     parseInput(std::string str, Input_Type isPseudo)
{
    int     strlen = str.length();
    bool    isDecimal = false;
    if (isPseudo) return isPseudo;
    if ((str[0] >= 32 && str[0] <= 126) && strlen == 1) {
        if ((str[0] >= '0'&& str[0] <= '9'))
            return INT;
        return CHAR;
    }
    if (!((str[0] >= '0'&& str[0] <= '9') || str[0] == '-' || str[0] == '+') && strlen > 1)
        return NONE;
    for (int i = 0; i < strlen; i++) {
        if (i == 0 && (str[i] == '-' || str[i] == '+'))
            continue;
        if (!(str[i] >= '0'&& str[i] <= '9')) {
            if (str[i] == '.') {
                if (!isDecimal)
                    isDecimal = true;
                else
                    return NONE;
            }
            else if (str[i] == 'f' && i == strlen - 1)
                continue;
            else
                return NONE;
        }
    }
    if (isDecimal)
        return str[strlen - 1] == 'f' ? FLOAT : DOUBLE;
    return INT;
}

static Input_Type    isPseudoLiteral(std::string str)
{
    if (str.compare("-inf") == 0 || str.compare("-inff") == 0)  return MINUS_PL;
    if (str.compare("+inf") == 0 || str.compare("+inff") == 0)  return PLUS_PL;
    if (str.compare("nan") == 0 || str.compare("nanf") == 0)    return NAN_PL;
    return NONE;
}

int ScalarConverter::convert(std::string str)
{
    Input_Type input_type = NONE;
    input_type = parseInput(str, isPseudoLiteral(str));
    if (input_type == NONE)
        { std::cerr << IMPOSSIBLE_INPUT << std::endl; return 1; }
    convertChar(str, input_type);
    convertInt(str, input_type);
    convertFloat(str, input_type);
    convertDouble(str, input_type);

    return 0;
}