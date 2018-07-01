/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozlov <ikozlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/30 15:55:11 by ikozlov           #+#    #+#             */
/*   Updated: 2018/07/01 16:15:09 by ikozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <stdexcept>

#include "Form.hpp"
#include "Intern.hpp"
#include "Bureaucrat.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"

static void
signAndExecuteForms(Bureaucrat b, ShrubberyCreationForm f1, \
		RobotomyRequestForm f2, PresidentialPardonForm f3)
{
	try
	{
		b.signForm(f1);
		b.signForm(f2);
		b.signForm(f3);

		b.executeForm(f1);
		b.executeForm(f2);
		b.executeForm(f3);
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
	Form *f1;
	Form *f2;
	Form *f3;
	Form *f4;
	Intern i1;
	Bureaucrat b1 = Bureaucrat("Mr. Abraham", 42);

	f1 = i1.makeForm("robotomy request", "Marvin");
	f2 = i1.makeForm("presidential pardon", "Marvin");
	f3 = i1.makeForm("shrubbery creation", "Marvin");
	std::cout << *f1 << std::endl;
	std::cout << *f2 << std::endl;
	std::cout << *f3 << std::endl;

	signAndExecuteForms(b1, *(ShrubberyCreationForm *)f3,\
			*(RobotomyRequestForm *)f1, *(PresidentialPardonForm *)f2);

	f4 = i1.makeForm("TEST", "Marvin");

	return (0);
}
