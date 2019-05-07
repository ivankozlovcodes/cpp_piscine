/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozlov <ikozlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/02 22:34:07 by ikozlov           #+#    #+#             */
/*   Updated: 2019/05/07 15:22:42 by ikozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include "Base.hpp"

Base
*generate(void)
{
	Base	*res;
	int		x = rand() % 3;

	switch(x)
	{
		case 0:
			std::cout << "Making A class" << std::endl;
			res = new A;
			break;
		case 1:
			std::cout << "Making B class" << std::endl;
			res = new B;
			break;
		default:
			std::cout << "Making C class" << std::endl;
			res = new C;
	}
	return (res);
}

void
identify_from_pointer(Base *p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "C" << std::endl;
}

void
identify_from_reference( Base &p)
{
	if (dynamic_cast<A*>(&p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(&p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(&p))
		std::cout << "C" << std::endl;
}

int
main(void)
{
	srand(static_cast<unsigned int>(time(NULL)));

	Base	*ptr = generate();

	identify_from_pointer(ptr);
	identify_from_reference(*ptr);

	return (0);
}
