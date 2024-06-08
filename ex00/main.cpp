/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loandrad <loandrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 15:53:54 by loandrad          #+#    #+#             */
/*   Updated: 2024/05/27 16:08:05 by loandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#define USAGE "\nTo run program : ./converter <INPUT>\nINPUT is a string representing either an int, a float or a double.\n"

int main(int argc, char** argv)
{
    if (argc == 2)
        ScalarConverter::convert(argv[1]);
    else
        std::cout << USAGE << std::endl;
    return 0;
}