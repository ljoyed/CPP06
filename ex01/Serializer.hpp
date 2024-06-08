/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loandrad <loandrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 12:26:58 by loandrad          #+#    #+#             */
/*   Updated: 2024/05/28 14:06:04 by loandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

struct Data
{
    int i;
};

class Serializer
{
    private:
        Serializer();
        ~Serializer();
        Serializer(const Serializer& origObj);
        Serializer& operator=(const Serializer& origObj);

    public:
        static uintptr_t serialize(Data* ptr);
        static Data* deserialize(uintptr_t raw);
};