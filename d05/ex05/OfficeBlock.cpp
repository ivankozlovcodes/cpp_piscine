/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OfficeBlock.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozlov <ikozlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/01 17:34:10 by ikozlov           #+#    #+#             */
/*   Updated: 2018/07/01 18:54:42 by ikozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "OfficeBlock.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

OfficeBlock::OfficeBlock(void) :
	_intern(NULL),
	_signer(NULL),
	_executer(NULL) { }

OfficeBlock::OfficeBlock(Intern &intern, Bureaucrat &signer, Bureaucrat &executer) :
	_intern(&intern),
	_signer(&signer),
	_executer(&executer) { }

OfficeBlock::~OfficeBlock(void) { }

void
OfficeBlock::doBureaucracy(std::string form_name, std::string target)
{
	Form		*form = NULL;
	
	if (!this->_intern)
		throw OfficeBlock::NoInternException();
	form = this->_intern->makeForm(form_name, target);
	if (!form)
		return ;
	if (!this->_signer)
		throw OfficeBlock::NoSignerException();
	this->_signer->signForm(*form);
	if (!this->_executer)
		throw OfficeBlock::NoExecuterException();
	this->_executer->executeForm(*form);
}

void
OfficeBlock::setIntern(Intern &obj)
{
	std::cout << "Set intern to an office block" << std::endl;
	this->_intern = &obj;
}

void
OfficeBlock::setSigner(Bureaucrat &obj)
{
	std::cout << "Set signer " << obj << " to an office block" << std::endl;
	this->_signer = &obj;
}

void
OfficeBlock::setExecutor(Bureaucrat &obj)
{
	std::cout << "Set executor " << obj << " to an office block" << std::endl;
	this->_executer = &obj;
}

Bureaucrat
*OfficeBlock::getSigner(void)
{
	return (this->_signer);
}

Bureaucrat
*OfficeBlock::getExecutor(void)
{
	return (this->_executer);
}

/*
** NoInternException Nested Class
*/

const char
*OfficeBlock::NoInternException::message = "OfficeBlock Error: No Intern Present";


OfficeBlock::NoInternException::NoInternException(void) { }

OfficeBlock::NoInternException::NoInternException(NoInternException const &obj)
{
	*this = obj;
}

OfficeBlock::NoInternException::~NoInternException(void) throw() { }

OfficeBlock::NoInternException
&OfficeBlock::NoInternException::operator=(NoInternException const &r) 
{
	(void)r;
	return (*this);
}

const char*
OfficeBlock::NoInternException::what() const throw()
{
	return (OfficeBlock::NoInternException::message);
}

/*
** NoSignerException Nested Class
*/

const char
*OfficeBlock::NoSignerException::message = "OfficeBlock Error: No Signer Present";

OfficeBlock::NoSignerException::NoSignerException(void) { }

OfficeBlock::NoSignerException::NoSignerException(NoSignerException const &obj)
{
	*this = obj;
	return;
}

OfficeBlock::NoSignerException::~NoSignerException(void) throw() { }

OfficeBlock::NoSignerException
&OfficeBlock::NoSignerException::operator=(NoSignerException const &r) 
{
	(void)r;
	return (*this);
}

const char*
OfficeBlock::NoSignerException::what() const throw()
{
	return (OfficeBlock::NoSignerException::message);
}

/*
** NoExecuterException Nested Class
*/

const char
*OfficeBlock::NoExecuterException::message = "OfficeBlock Error: No Interns Present";

OfficeBlock::NoExecuterException::NoExecuterException(void) { }

OfficeBlock::NoExecuterException::NoExecuterException(NoExecuterException const &obj)
{
	*this = obj;
	return;
}

OfficeBlock::NoExecuterException::~NoExecuterException(void) throw() { }

OfficeBlock::NoExecuterException
&OfficeBlock::NoExecuterException::operator=(NoExecuterException const &r) 
{
	(void)r;
	return (*this);
}

const char*
OfficeBlock::NoExecuterException::what() const throw()
{
	return (OfficeBlock::NoExecuterException::message);
}
