/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivankozlov <ivankozlov@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/30 15:55:11 by ikozlov           #+#    #+#             */
/*   Updated: 2018/06/30 20:08:55 by ivankozlov       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <stdexcept>

#include "Form.hpp"
#include "Bureaucrat.hpp"

static void
checkForm(Bureaucrat bureaucrat, Form format)
{
	try
	{
		bureaucrat.signForm(format);
		std::cout << bureaucrat << std::endl;
		std::cout << format << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	return ;
}

int
main(void)
{
	Form        f1 = Form("A form", 42, 42);
	Form        f2 = Form("Another one...", 30, 50);
	Bureaucrat  b1 = Bureaucrat("Marvin", 42);
	Bureaucrat  b2 = Bureaucrat("Mr. Abraham", 1);

	checkForm(b1, f1);
	std::cout << std::endl;

	checkForm(b1, f2);
	std::cout << std::endl;

	checkForm(b2, f1);
	std::cout << std::endl;

	checkForm(b2, f2);
	std::cout << std::endl;
	return (0);
}
