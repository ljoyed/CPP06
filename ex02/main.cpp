/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loandrad <loandrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 15:53:54 by loandrad          #+#    #+#             */
/*   Updated: 2024/05/28 19:00:09 by loandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base* generate(void)
{
    switch (rand() % 3)
    {
        case 0: 
            std::cout << "Object A created." << std::endl;
            return new A;
        case 1:
            std::cout << "Object B created." << std::endl;
            return new B;
        case 2:
            std::cout << "Object C created." << std::endl;
            return new C;
        default:
            std::cout << "NULL object created." << std::endl;
            return NULL;
    }
    return NULL;
}

void identify(Base* ptr)
{
    std::cout << "ptr value before dynamic cast : " << ptr << std::endl;
    if (dynamic_cast<A*>(ptr))
    {
        std::cout << "Pointer type A" << std::endl;
        std::cout << "ptr value after dynamic cast : " << ptr << std::endl;
    }
    else if (dynamic_cast<B*>(ptr))
    {
        std::cout << "Pointer type B" << std::endl;
        std::cout << "ptr value after dynamic cast : " << ptr << std::endl;
    }
    else if (dynamic_cast<C*>(ptr))
    {
        std::cout<< "Pointer type C" << std::endl;
        std::cout << "ptr value after dynamic cast : " << ptr << std::endl;
    }
	else
		std::cout << "Unkown Pointer..." << std::endl;
}

void identify(Base& ref)
{
    std::cout << "address of reference before dynamic cast : " << &ref << std::endl;
    try
    {
		A& a = dynamic_cast<A&>(ref);
		std::cout << "Ref type A" << std::endl;
        std::cout << "address of A after dynamic cast of it's reference : " << &a << std::endl;
    }
    catch(std::exception&) {}
    try
    {
		B &b  = dynamic_cast<B&>(ref); 
		std::cout << "Ref type B" << std::endl;
        std::cout << "address of B after dynamic cast of it's reference : " << &b << std::endl;
    }
    catch(std::exception&) {}
    try
    {
		C &c = dynamic_cast<C&>(ref); 
		std::cout << "Ref type C" << std::endl;
        std::cout << "address of C after dynamic cast of it's reference : " << &c << std::endl;
    }
    catch(std::exception&) {}
}

int main()
{
    srand(time(0));
    Base *ptr = generate();

    std::cout << std::endl;
    std::cout << "Identifying via pointer..." << std::endl;
    identify(ptr);

    std::cout << std::endl;
    std::cout << "Identifying via reference... " << std::endl;
    identify(*ptr);
    
    delete (ptr);
    return (0);
}