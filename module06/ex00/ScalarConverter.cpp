#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(){}
ScalarConverter::ScalarConverter(const ScalarConverter& to_copy){(void)to_copy;}
ScalarConverter::~ScalarConverter(){}
ScalarConverter& ScalarConverter::operator=(const ScalarConverter& to_asign){(void)to_asign;return (*this);}

static bool	isChar(const std::string	&literal)
{
	char	c;

	if (literal.length() != 1)
		return (false);
	c = literal[0];
	return (std::isprint(c) && !std::isdigit(c));	
}

static bool	isInt(const std::string	&literal)
{
	size_t	i = 0;

	if (literal[0] == '+' || literal[0] == '-')
		i++;
	while (literal[i])
	{
		if (!std::isdigit(literal[i]))
			return (false);
		i++;
	}
	return (true);	
}

static bool	isFloat(const std::string	&str)
{
	if (str == "nanf" || str == "inff" || str == "-inff" || str == "+inff" ||
		str == "nan"  || str == "inf"  || str == "-inf"  || str == "+inf") {
		return true;
	}
	char* endPtr = NULL;
	std::string temp = str;
	if (temp[temp.size() - 1] == 'f' && temp.size() > 1) {
		temp.erase(temp.size() - 1);
	}
	std::strtof(temp.c_str(), &endPtr);
	if (endPtr == temp.c_str() || *endPtr != '\0') {
		return false;
	}
	return true;
}

static bool	isDouble(const std::string	&str)
{
	if (str == "nan" || str == "inf" || str == "-inf" || str == "+inf") {
		return true;
	}
	char* endPtr = NULL;
	std::string temp = str;
	if (temp[temp.size() - 1] == 'f' && temp.size() > 1) {
		temp.erase(temp.size() - 1);
	}
	std::strtod(temp.c_str(), &endPtr);
	if (endPtr == temp.c_str() || *endPtr != '\0') {
		return false;
	}
	return true;
}

static int whatType(std::string literal)
{
	if (isChar(literal))
		return (CHAR);
	if (isInt(literal))
		return (INT);
	if (isFloat(literal))
		return (FLOAT);
	if (isDouble(literal))
		return (DOUBLE);
	return 42;
}

static void	printChar(double value) {
	std::cout << "char: ";
    if (std::isnan(value) || value < 0 || value > 255) {
        std::cout << "impossible" << std::endl;
    } else if (!std::isprint(static_cast<char>(value))) {
        std::cout << "Non displayable" << std::endl;
    } else {
        std::cout << "'" << static_cast<char>(value) << "'" << std::endl;
    }
}

static void	printInt(double value) {
	std::cout << "int: ";
	if (std::isnan(value) || value > std::numeric_limits<int>::max() || value < std::numeric_limits<int>::min()) {
        std::cout << "impossible" << std::endl;
    } else {
        std::cout << static_cast<int>(value) << std::endl;
    }
}

static void	printFloat(double value) {
	std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(value) << "f" << std::endl;
}

static void	printDouble(double value) {
	std::cout << "double: " << std::fixed << std::setprecision(1) << value << std::endl;
}

void	ScalarConverter::convert(std::string literal) {
	double value;

	switch (whatType(literal))
	{
	case CHAR:
		value = static_cast<double>(literal[0]);
		break;
	case INT:
		value = static_cast<double>(std::atoi(literal.c_str()));
		break;
	case FLOAT:
		value = static_cast<double>(std::strtof(literal.c_str(), NULL));
		break;
	case DOUBLE:
		value = static_cast<double>(std::atof(literal.c_str()));
		break;
	default:
		std::cout << "Invalid input" << std::endl;
		break;
	}

	printChar(value);
	printInt(value);
	printFloat(value);
	printDouble(value);
}
