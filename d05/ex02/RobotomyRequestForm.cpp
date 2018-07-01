/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozlov <ikozlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/30 20:33:42 by ikozlov           #+#    #+#             */
/*   Updated: 2018/06/30 22:06:57 by ikozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

const int RobotomyRequestForm::_sign = 75;
const int RobotomyRequestForm::_exec = 45;
const std::string
RobotomyRequestForm::name = "Robotomy";

RobotomyRequestForm::RobotomyRequestForm(void) :
	Form("Anonymous", RobotomyRequestForm::name,\
	RobotomyRequestForm::_sign, RobotomyRequestForm::_exec)
{
	srand(time(NULL));
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) :
	Form(target, RobotomyRequestForm::name, \
	RobotomyRequestForm::_sign, RobotomyRequestForm::_exec) 
{
	srand(time(NULL));
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &src) :
	Form(src.getTarget(), RobotomyRequestForm::name,\
	RobotomyRequestForm::_sign, RobotomyRequestForm::_exec)
{
	*this = src;
	srand(time(NULL));
}

RobotomyRequestForm::~RobotomyRequestForm(void) { }

RobotomyRequestForm
&RobotomyRequestForm::operator= (const RobotomyRequestForm &obj)
{
	(void)obj;
	return (*this);
}

void
RobotomyRequestForm::execute(const Bureaucrat &executor) const
{
	Form::execute(executor);
	if (rand() % 100 + 1 > 50)
	{
		std::cout << "BZZZZZZZZZZ..."\
				<< getTarget() \
				<< " has been robotomized successfully !" << std::endl;
	}
	else
	{
		std::cout << "The " << getTarget() << "robotomization failed !" \
				<< std::endl;
	}
}
