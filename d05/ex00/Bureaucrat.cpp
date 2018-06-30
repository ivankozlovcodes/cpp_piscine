/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozlov <ikozlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/30 15:35:33 by ikozlov           #+#    #+#             */
/*   Updated: 2018/06/30 16:11:23 by ikozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(std::string name, int grade) {
	this->_grade = 0;
	this->setName(name);
	this->incGrade(grade);
}

Bureaucrat::~Bureaucrat(void) { return ;}

void
Bureaucrat::incGrade(int value)
{
	int tmp = this->_grade + value;

	if (this->_grade + value > 150)
		throw Bureaucrat::GradeTooHighException();
	this->_grade += value;
}

void
Bureaucrat::decGrade(int value)
{
}

void
Bureaucrat::setName(std::string name)
{
	this->_name = name;
}

int
Bureaucrat::getGrade(void)
{
	return (this->_grade);
}

std::string
Bureaucrat::getName(void)
{
	return (this->_name);
}

/*
 * GradeTooHighException
 */

Bureaucrat::
GradeTooHighException::GradeTooHighException(void) {}

Bureaucrat::
GradeTooHighException::~GradeTooHighException(void) throw() {}

const char
*Bureaucrat::
GradeTooHighException::what() const throw()
{
	return (TOO_HIGH_MSG);
}
