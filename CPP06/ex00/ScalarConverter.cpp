/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melvin <melvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 13:12:14 by mcotonea          #+#    #+#             */
/*   Updated: 2025/07/18 19:56:27 by melvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

/* No need to define all functions to canonical form, because the class must not be instantiable */

/* 
#define CHAR 1
#define INT 2
#define FLOAT 3
#define DOUBLE 4
#define SPECIAL_F 5
#define SPECIAL_D 6
#define INVALID 7
 */

 /* 
	Pour une float: precision maximale de 9 chiffres.
	Pour un double: precision maximale de 17 chiffres.
 */
int getPrecision(const std::string& str){
	std::size_t dotPos = str.find('.');
	std::size_t end = str.length();
	int count = 0;

	if (str[str.length() - 1] == 'f')
		end--;
	for (std::size_t i = dotPos + 1; i < end; ++i){
		count++;
	}
	return count;
}

 
bool isPseudoLiteralFloat(const std::string& str){
	if (str == "nanf" || str == "-inff" || str == "+inff")
		return true;
	return false;
}

bool isPseudoLiteralDouble(const std::string& str){
	if (str == "nan" || str == "-inf" || str == "+inf")
		return true;
	return false;
}

bool isChar(const std::string& str){
	if (str.length() == 1 && !std::isdigit(str[0]))
		if (std::isprint(str[0])){
			return  true;
		}
	return false;
}

bool isInt(const std::string& str){
	
	
	if (str.empty())
		return false;
	
	if (str[0] == '+' || str[0] == '-'){
		if (str.length() == 1)
			return false;
	}
	for (size_t i = 1; i < str.length(); ++i){
		if (!std::isdigit(str[i]))
			return false;
	}
	return true;
}

bool isFloat(const std::string& str){
	if (str.length() < 2 || str[str.length() - 1] != 'f' || ((str.length() - 2) == '.' && (str.length() - 1) == 'f'))
		return false;
	
	std::string trimmedStr = str.substr(0, str.length() - 1);
	if (trimmedStr.empty())
		return false;
	
	size_t dotCount = 0;
	size_t i = 0;

	if (trimmedStr[i] == '-' || trimmedStr[i] == '+')
		i++;
	for (; i < trimmedStr.length(); ++i){
		if (trimmedStr[i] == '.')
			++dotCount;
		else if (!std::isdigit(trimmedStr[i]))
			return false;
	}
	if (dotCount > 1)
		return false;
	return true;
}

bool isDouble(const std::string& str){
	if (str.empty())
		return false;

	size_t i = 0;
	size_t dotCount = 0;

	if (str[0] == '-' || str[0] == '+')
		i++;
	for (; i < str.length(); ++i){
		if (str[i] == '.')
			++dotCount;
		else if (!std::isdigit(str[i]))
			return false;
	}
	if (dotCount != 1 || str[str.length() - 1] == '.')
		return false;
	return true;
}

void toChar(const std::string& str){
	char c = str[0];
	std::cout << "char: '" << c << "'" << std::endl;
	std::cout << "int: " << static_cast<int>(c) << std::endl;
	std::cout << "float: " << static_cast<float>(c) << ".0f" << std::endl;
	std::cout << "double: " << static_cast<double>(c) << ".0" << std::endl;
}

void toInt(const std::string& str){
	errno = 0;
	char *endptr;
	long value = std::strtol(str.c_str(), &endptr, 10);
	if (errno == ERANGE || value < INT_MIN || value > INT_MAX){
		std::cout << "int: overflow or underflow detected" << std::endl;
		return;
	}
	
	int i = static_cast<int>(value);
	if (i < 0 || i > 127)
		std::cout << "char: impossible" << std::endl;
	else if (!std::isprint(i))
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: '" << static_cast<char>(i) << "'" << std::endl;
	
	std::cout << "int: " << i << std::endl;
	std::cout << "float: " << static_cast<float>(i) << ".0f" << std::endl;
	std::cout << "double: " << static_cast<double>(i) << ".0" << std::endl;
}

void toFloat(const std::string& str){
	errno = 0;
	char* endptr;
	double d = std::strtod(str.c_str(), &endptr);
	if (errno == ERANGE || d > FLT_MAX || d < -FLT_MAX){
		std::cout << "float: overflow or underflow detected" << std::endl;
		return ;
	}
	if (d < 0 || d > 127)
		std::cout << "char: impossible" << std::endl;
	else if (!std::isprint(static_cast<char>(d)))
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: '" << static_cast<char>(d) << "'" << std::endl;

	if (d < MIN_INT|| d > MAX_INT)
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(d) << std::endl;
	int precision = getPrecision(str);
	if (precision == 0)
		precision = 1;
	float f = static_cast<float>(d);
	if (f > FLT_MAX || f < -FLT_MAX)
		std::cout << "float: overflow or underflow detected" << std::endl;
	else
		std::cout << std::fixed << std::setprecision(precision) << "float: " << f << "f" << std::endl;
	std::cout << std::fixed << std::setprecision(precision) << "double: " << d << std::endl;
 }
 
 void toDouble(const std::string& str){
	errno = 0;
	char *endptr;
	double d = std::strtod(str.c_str(), &endptr);
	if (errno == ERANGE || d > DBL_MAX || d < -DBL_MAX){
		std::cout << "double: overflow or underflow detected" << std::endl;
		return ;
	}

	if (d < 0 || d > 127)
		std::cout << "char: impossible" << std::endl;
	else if (!std::isprint(static_cast<char>(d)))
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: '" << static_cast<char>(d) << "'" << std::endl;

	if (d < MIN_INT || d > MAX_INT)
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(d) << std::endl;
	int precision = getPrecision(str);
	float f = static_cast<float>(d);
	if (f > FLT_MAX || f < -FLT_MAX)
		std::cout << "float: overflow or underflow detected" << std::endl;
	else
		std::cout << std::fixed << std::setprecision(precision) << "float: " << f << "f" << std::endl;
	std::cout << std::fixed << std::setprecision(precision) << "double: " << d << std::endl;
	
}

void toPseudoLiteral(const std::string& str){
	bool isFloat  = isPseudoLiteralFloat(str);
	bool isDouble = isPseudoLiteralDouble(str);

	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;

	if (isFloat){
		std::cout << "float: " << str << std::endl;
		std::string trimmedStr = str.substr(0, str.length() - 1);
		std::cout << "double: " << trimmedStr << std::endl;
	}
	if (isDouble){
		std::cout << "float: " << str << "f" << std::endl;
		std::cout << "double: " << str << std::endl;
	}

}

ScalarType detectType(const std::string& str){
	if (isPseudoLiteralDouble(str) || isPseudoLiteralFloat(str))
		return PSEUDO_LITERAL;
	else if (isChar(str))
		return CHAR;
	else if (isInt(str))
		return INT;
	else if (isFloat(str))
		return FLOAT;
	else if (isDouble(str))
		return DOUBLE;
	else
		return INVALID;
}

void ScalarConverter::convert(const std::string& str){
	switch (detectType(str)){
		case PSEUDO_LITERAL:
			toPseudoLiteral(str);
			break;
		case CHAR:
			toChar(str);
			break;
		case INT:
			toInt(str);
			break;
		case FLOAT:
			toFloat(str);
			break;
		case DOUBLE:
			toDouble(str);
			break;
		case INVALID:
			default:
				std::cout << str << " is not a valid input" << std::endl;
				break;
	}
}

/*
Utilisation des static_cast car on fait des conversions entre types numériques.
On peut aussi les utiliser pour des conversions entre types liés par hiérarchie d'héritage.
*/