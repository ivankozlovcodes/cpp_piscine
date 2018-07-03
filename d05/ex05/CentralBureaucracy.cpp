/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CentralBureaucracy.cpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozlov <ikozlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/01 18:30:47 by ikozlov           #+#    #+#             */
/*   Updated: 2018/07/02 20:40:11 by ikozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "CentralBureaucracy.hpp"
#include "CentralBureaucracy.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"

CentralBureaucracy::CentralBureaucracy(void)
{
	_generateInterns();
	return;
}

CentralBureaucracy::CentralBureaucracy(CentralBureaucracy &src)
{
	*this = src;
}

CentralBureaucracy::~CentralBureaucracy(void) { }

void
CentralBureaucracy::_generateInterns(void)
{
	Intern whocares;

	for (int i = 0; i < _blocks_num; i++)
		_blocks[i].setIntern(whocares);
}

CentralBureaucracy
&CentralBureaucracy::operator=(const CentralBureaucracy &src) 
{
	std::copy(src._targets,\
		src._targets + CentralBureaucracy::_targets_num, this->_targets);
	// std::copy(src._blocks,
	// src._blocks + CentralBureaucracy::_blocks_num, this->_blocks);
	return (*this);
}

void
CentralBureaucracy::doBureaucracy(void)
{
	int				x;
	std::string		forms[] = { PP, RR, SC };

	for (int i = 0; i < CentralBureaucracy::_targets_num; i++)
	{
		if (_targets[i] == "")
			break;
		std::cout << std::endl;
		while (_targets[i] != "")
		{
			x = rand() % 20;
			try
			{
				_blocks[x].doBureaucracy(forms[x % 3], _targets[i]);
			}
			catch (std::exception &e)
			{
				std::cout << "Can't execute form :(" << std::endl;
				std::cout << e.what() << std::endl;
				continue;
			}
			_targets[i] = "";
		}
	}
}

void
CentralBureaucracy::feedSigner(Bureaucrat &obj)
{
	for (int i = 0; i < CentralBureaucracy::_blocks_num; i++)
		if (_blocks[i].getSigner() == NULL)
		{
			_blocks[i].setSigner(obj);
			return ;
		}
	throw new CentralBureaucracy::TooManyEmployeesException();
}

void
CentralBureaucracy::feedExecuter(Bureaucrat &obj)
{
	for (int i = 0; i < CentralBureaucracy::_blocks_num; i++)
		if (_blocks[i].getExecutor() == NULL)
		{
			_blocks[i].setExecutor(obj);
			return ;
		}
	throw new CentralBureaucracy::TooManyEmployeesException();
}

void	CentralBureaucracy::queueUp(std::string obj)
{
	for (int i = 0; i < CentralBureaucracy::_targets_num; i++)
		if (_targets[i] == "")
		{
			_targets[i] = obj;
			return ;
		}
	throw new CentralBureaucracy::TooBusyException();
}

/*
** TooBusyException Nested Class
*/

const char
*CentralBureaucracy::TooBusyException::message = "CentralBureaucracy Error:\
		Too busy to accept new forms!";


CentralBureaucracy::TooBusyException::TooBusyException(void) { }

CentralBureaucracy::TooBusyException::TooBusyException(TooBusyException const &obj)
{
	*this = obj;
}

CentralBureaucracy::TooBusyException::~TooBusyException(void) throw() { }

CentralBureaucracy::TooBusyException
&CentralBureaucracy::TooBusyException::operator=(TooBusyException const &r) 
{
	(void)r;
	return (*this);
}

const char*
CentralBureaucracy::TooBusyException::what() const throw()
{
	return (CentralBureaucracy::TooBusyException::message);
}

/*
** TTooManyEmployeesException Nested Class
*/

const char
*CentralBureaucracy::TooManyEmployeesException::message = "CentralBureaucracy Error:\
		We are overstuffed already adding new employees won't help!";

CentralBureaucracy::TooManyEmployeesException::\
TooManyEmployeesException(void) { }

CentralBureaucracy::TooManyEmployeesException::\
TooManyEmployeesException(TooManyEmployeesException const &obj)
{
	*this = obj;
}

CentralBureaucracy::TooManyEmployeesException::~TooManyEmployeesException(void) throw() { }

CentralBureaucracy::TooManyEmployeesException
&CentralBureaucracy::TooManyEmployeesException::operator=(TooManyEmployeesException const &r) 
{
	(void)r;
	return (*this);
}

const char*
CentralBureaucracy::TooManyEmployeesException::what() const throw()
{
	return (CentralBureaucracy::TooManyEmployeesException::message);
}
