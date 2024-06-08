/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loandrad <loandrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 15:43:56 by loandrad          #+#    #+#             */
/*   Updated: 2024/05/27 17:19:58 by loandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{}

ScalarConverter::ScalarConverter(const ScalarConverter& origObj)
{
    *this = origObj;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& origObj)
{
    (void) origObj;
    return (*this);
}

ScalarConverter::~ScalarConverter()
{}

void ScalarConverter::convert(const std::string input)
{
    // Single character that's printable but not a digit
    if (input.size() == 1 && isprint(input[0]) && !isdigit(input[0]))
    {
        char c = input[0];
        std::cout << "char   : '" << c << "'" << std::endl;
        std::cout << "int    : " << static_cast<int>(c) << std::endl;
        std::cout << "float  : " << static_cast<float>(c) << "f" << std::endl;
        std::cout << "double : " << static_cast<double>(c) << std::endl;
        return;
    }
    else
    {
        // Handle the conversion of a string representation of a number
        char* end;
        errno = 0; // Reset errno before conversion
        double value = std::strtod(input.c_str(), &end);

        if (*end != '\0' || errno == ERANGE) // Not a valid number or out of range
        {
            std::cout << "Invalid input" << std::endl;
            return;
        }

        std::cout << "char   : ";
        if (value < CHAR_MIN || value > CHAR_MAX || std::isnan(value) || std::isinf(value))
            std::cout << "impossible" << std::endl;
        else if (isprint(static_cast<int>(value)))
            std::cout << "'" << static_cast<char>(value) << "'" << std::endl;
        else
            std::cout << "Non displayable" << std::endl;

        std::cout << "int    : ";
        if (value < INT_MIN || value > INT_MAX || std::isnan(value) || std::isinf(value))
            std::cout << "impossible" << std::endl;
        else
            std::cout << static_cast<int>(value) << std::endl;

        std::cout << "float  : ";
        if (std::isnan(value))
            std::cout << "nanf" << std::endl;
        else if (std::isinf(value))
            std::cout << ((value < 0) ? "-inff" : "inff") << std::endl;
        else
            std::cout << static_cast<float>(value) << "f" << std::endl;

        std::cout << "double : ";
        if (std::isnan(value))
            std::cout << "nan" << std::endl;
        else if (std::isinf(value))
            std::cout << ((value < 0) ? "-inf" : "inf") << std::endl;
        else
            std::cout << value << std::endl;
    }
}