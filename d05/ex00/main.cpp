/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozlov <ikozlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/30 15:55:11 by ikozlov           #+#    #+#             */
/*   Updated: 2018/06/30 17:01:04 by ikozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Bureaucrat.hpp"

static void
checkBureaucrat(Bureaucrat test, int min, int max)
{
	try
	{
		for(int i = min; i <= max; i++)
		{
			// test.incGrade();
			test.decGrade();
			// std::cout << test << std::endl;
		}
	}
	catch (std::exception & e)
	{
		std::cout << test;
		std::cout << e.what() << std::endl;
	}
	return ;
}

int
main(void)
{
	Bureaucrat  asd("Asd", 10);

	std::cout << asd.getGrade() << std::endl;
	std::cout << asd.getName() << std::endl;
	checkBureaucrat(asd, 0, 150);
	return (0);
}
