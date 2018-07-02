/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozlov <ikozlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/30 15:35:33 by ikozlov           #+#    #+#             */
/*   Updated: 2018/06/30 21:56:48 by ikozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void)
{
	this->_name = "Undefined";
	this->_grade = 1;
}

Bureaucrat::Bureaucrat(const Bureaucrat &src)
{
	*this = src;
}

Bureaucrat::Bureaucrat(std::string name, int grade) {
	this->setName(name);
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	this->_grade = grade;
}

Bureaucrat::~Bureaucrat(void) { return; }

Bureaucrat
&Bureaucrat::operator= (const Bureaucrat &rhs)
{
	this->_grade = rhs._grade;
	this->_name = rhs._name;
	return (*this);
}

std::ostream
&operator<< (std::ostream &out, const Bureaucrat &obj)
{
	out << obj.getName() << ", bureaucrat grade " << obj.getGrade();
	return (out);
}

void
Bureaucrat::incGrade(void)
{
	if (this->_grade == 1)
		throw Bureaucrat::GradeTooHighException();
	this->_grade--;
}

void
Bureaucrat::decGrade(void)
{
	if (this->_grade == 150)
		throw Bureaucrat::GradeTooLowException();
	this->_grade++;
}

void
Bureaucrat::setName(std::string name)
{
	this->_name = name;
}

int
Bureaucrat::getGrade(void) const
{
	return (this->_grade);
}

std::string
Bureaucrat::getName(void) const
{
	return (this->_name);
}

void
Bureaucrat::signForm(Form &form)
{
	try
	{
		form.beSigned(*this);
		std::cout << this->_name << " signs " << form.getName() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << this->_name << " cannot sign " << form.getName()\
				<< " because " << e.what() << std::endl;
	}
}

void
Bureaucrat::executeForm(const Form &form)
{
	try
	{
		form.execute(*this);
		std::cout << this->_name << " executes "\
				<< form.getName()\
				<< " on target " + form.getTarget() + " "\
				<< std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << this->_name << " has failed to execute " \
					<< form.getName() << " because " << e.what() << std::endl;
	}
}

/*
 * GradeTooHighException
 */

Bureaucrat::
GradeTooHighException::GradeTooHighException(void) {}

Bureaucrat::
GradeTooHighException::GradeTooHighException(const GradeTooHighException &src)
{
	*this = src;
}

Bureaucrat::
GradeTooHighException::~GradeTooHighException(void) throw() {}

Bureaucrat::GradeTooHighException
&Bureaucrat::GradeTooHighException::operator= (const GradeTooHighException &rhs)
{
    (void)rhs;
    return (*this);
}

const char
*Bureaucrat::
GradeTooHighException::what() const throw()
{
	return (TOO_HIGH_MSG);
}

/*
 *	GradeTooLowException
 */

Bureaucrat::
GradeTooLowException::GradeTooLowException(void) {}

Bureaucrat::
GradeTooLowException::GradeTooLowException(const GradeTooLowException &src)
{
	*this = src;
}

Bureaucrat::
GradeTooLowException::~GradeTooLowException(void) throw() {}

Bureaucrat::GradeTooLowException
&Bureaucrat::GradeTooLowException::operator= (const GradeTooLowException &rhs)
{
    (void)rhs;
    return (*this);
}

const char
*Bureaucrat::
GradeTooLowException::what() const throw()
{
	return (TOO_LOW_MSG);
}
