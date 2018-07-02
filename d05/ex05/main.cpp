/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozlov <ikozlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/30 15:55:11 by ikozlov           #+#    #+#             */
/*   Updated: 2018/07/01 18:17:33 by ikozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"
#include "OfficeBlock.hpp"

int	main()
{

	Bureaucrat  Arta("Arta Rose", 20);
	Bureaucrat  Lydeka("Lydeka White", 100);

	std::cout << Arta << std::endl;
	std::cout << Lydeka << std::endl;

	Intern	whocares;
	OfficeBlock ob;
	std::cout << "** Created new Intern and new OfficeBlock **" << std::endl
		<< "** Setting Signer (Arta), and Executor (Lydeka) **" << std::endl;

	ob.setSigner(Arta);
	ob.setExecutor(Lydeka);

	try
	{
		std::cout << std::endl << "** DoBureaucracy on Shrubbery Creation target Bushes, no interns present, should catch error" << std::endl;
		ob.doBureaucracy(PP, "Bushes");
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	ob.setIntern(whocares);
	try
	{
		std::cout << std::endl << "** DoBureaucracy on Shrubbery Creation target Bushes **" << std::endl;
		ob.doBureaucracy(PP, "Bushes");
		ob.doBureaucracy("asd", "Bushes");
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	return (0);
}
