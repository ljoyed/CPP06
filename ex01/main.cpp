/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loandrad <loandrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 15:53:54 by loandrad          #+#    #+#             */
/*   Updated: 2024/05/28 14:27:59 by loandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#define USAGE "\nTo run program : ./converter <INPUT>\nINPUT is a string representing an int.\n"

int main(int argc, char** argv)
{
    if (argc == 2)
    {
        int input = atoi(argv[1]);
        Data d = {input};
        Data* ptr = &d;
        Data* deserialized = 0;
        
        std::cout << std::endl;
        std::cout << "Test 1 : Serialization" << std::endl;
        std::cout << "ptr to Data struct : " << ptr << std::endl;
        uintptr_t serialized = Serializer::serialize(ptr);
        std::cout << "serialized ptr     : " << serialized << std::endl;
        
        std::cout << std::endl;
        std::cout << "Test 2 : Deserialization" << std::endl;
        std::cout << "ptr to hold result : " << deserialized << std::endl;
        deserialized = Serializer::deserialize(serialized);
        std::cout << "deserialized ptr   : " << deserialized << std::endl;
        std::cout << std::endl;
    }
    else
        std::cout << USAGE << std::endl;
    return 0;
}