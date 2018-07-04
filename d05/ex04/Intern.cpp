/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozlov <ikozlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/01 14:42:50 by ikozlov           #+#    #+#             */
/*   Updated: 2018/07/03 16:54:12 by ikozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

#include <iostream>

Intern::Intern(void)
{
	_functions[PP] = &Intern::_newPresidentialPardonForm;
	_functions[RR] = &Intern::_newRobotomyRequestForm;
	_functions[SC] = &Intern::_newShrubberyCreationForm;
}

Intern::Intern(const Intern &src)
{
	*this = src;
}

Intern::~Intern(void) { }

Intern
&Intern::operator= (const Intern &obj)
{
	(void)obj;
	return (*this);
}

Form*
Intern::makeForm(std::string name, std::string target)
{
	// std::map<std::string, Intern::InternFPointer>::iterator it;
	try
	{
		if (name == PP)
			return (_newPresidentialPardonForm(target));
		else if (name == SC)
			return (_newShrubberyCreationForm(target));
		else if (name == RR)
			return (_newRobotomyRequestForm(target));
		// it = _functions.find(name);
		// if (it != _functions.end())
		// 	return ((this)->*(it->second))(target);
		else
			throw RobotomyRequestForm::GradeTooLowException();
	}
	catch (std::exception &e)
	{
		std::cout << name << " : form not found... :(" << std::endl;
		return (NULL);
	}
}

Form*
Intern::_newPresidentialPardonForm(std::string target)
{
	return (new PresidentialPardonForm(target));
}

Form*
Intern::_newRobotomyRequestForm(std::string target)
{
	return (new RobotomyRequestForm(target));
}

Form*
Intern::_newShrubberyCreationForm(std::string target)
{
	return (new ShrubberyCreationForm(target));
}
