/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivankozlov <ivankozlov@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/30 19:14:44 by ivankozlov        #+#    #+#             */
/*   Updated: 2018/06/30 19:41:37 by ivankozlov       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(void) :
	_signed(false),
	_grade_to_sign(1),
	_grade_to_execute(1),
	_name("undefined") { }

Form::Form(const Form &src) :
	_signed(src._signed),
	_grade_to_sign(src._grade_to_sign),
	_grade_to_execute(src._grade_to_execute),
	_name(src._name)
{
	*this = src;
}

Form::Form(std::string name, int grade_to_sign, int grade_to_execute) :
	_signed(false),
	_grade_to_sign(grade_to_sign),
	_grade_to_execute(grade_to_execute)
{
	if (this->_grade_to_sign < 1 || this->_grade_to_execute < 1)
		throw Form::GradeTooHighException();
	if (this->_grade_to_sign > 150 || this->_grade_to_execute < 150)
		throw Form::GradeTooLowException();
}

Form::~Form(void) { }

Form
&Form::operator= (const Form &obj)
{
	this->_signed = obj._signed;
	return (*this);
}

void
Form::beSigned(Bureaucrat bureaucrat)
{
	if (bureaucrat.getGrade() > this->_grade_to_sign)
		throw Form::GradeTooLowException();
	this->_signed = true;
}

bool
Form::getSigned(void) const
{
	return (this->_signed);
}

int
Form::getGradeToSign(void) const
{
	return (this->_grade_to_sign);
}

int
Form::getGradeToExecute(void) const
{
	return (this->_grade_to_execute);
}

std::string
Form::getName(void) const
{
	return (this->_name);
}

std::ostream
&operator<< (std::ostream &out, const Form &obj)
{
	out << "The form: " << obj.getName() << " which is " \
		<< (obj.getSigned() ? "" : "not ") \
		<< " signed, which requires a grade " << obj.getGradeToSign() \
		<< " to sign, and " << obj.getGradeToExecute() << " to be executed." \
		<< std::endl;
	return (out);
}

/*
 * GradeTooHighException
 */

Form::
GradeTooHighException::GradeTooHighException(void) {}

Form::
GradeTooHighException::GradeTooHighException(const GradeTooHighException &src)
{
	*this = src;
}

Form::
GradeTooHighException::~GradeTooHighException(void) throw() {}

Form::GradeTooHighException
&Form::GradeTooHighException::operator= (const GradeTooHighException &rhs)
{
    (void)rhs;
    return (*this);
}

const char
*Form::GradeTooHighException::message = "Form cannot be signed as bureaucrat's grade is too high.";

const char
*Form::
GradeTooHighException::what() const throw()
{
	return (Form::GradeTooHighException::message);
}

/*
 *	GradeTooLowException
 */

const char
*Form::GradeTooLowException::message = "Form cannot be signed as bureaucrat's grade is too low.";

Form::
GradeTooLowException::GradeTooLowException(void) {}

Form::
GradeTooLowException::GradeTooLowException(const GradeTooLowException &src)
{
	*this = src;
}

Form::
GradeTooLowException::~GradeTooLowException(void) throw() {}

Form::GradeTooLowException
&Form::GradeTooLowException::operator= (const GradeTooLowException &rhs)
{
    (void)rhs;
    return (*this);
}

const char
*Form::
GradeTooLowException::what() const throw()
{
	return (Form::GradeTooLowException::message);
}
