#include "ScalarConverter.hpp"


/*
** Orthodox Canonical Form
*/
// Default constructor
ScalarConverter::ScalarConverter(){}
// Copy constructor
ScalarConverter::ScalarConverter(const ScalarConverter& to_copy){(void)to_copy;}
// Destructor
ScalarConverter::~ScalarConverter(){}
// Copy assignment operator
ScalarConverter& ScalarConverter::operator=(const ScalarConverter& to_asign){(void)to_asign;return (*this);}

static bool	isChar(const std::string	&literal)
{
	char	c;

	if (literal.length() != 1)
		return (false);
	c = literal[0];
	return (isprint(c) && !isdigit(c));	
}


static int whatType(std::string literal)
{
	if (isChar(literal))
		return (CHAR);
	else if ()
}

void	ScalarConverter::convert(std::string literal) {
	switch (whatType(literal))
	{
	case CHAR:
		/* code */
		break;
	case INT:
		/* code */
		break;
	case FLOAT:
		/* code */
		break;
	case DOUBLE:
		/* code */
		break;
	case INVALID:
		/* code */
		break;
	default:
		break;
	}
}