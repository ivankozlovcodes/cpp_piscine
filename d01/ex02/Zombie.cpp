/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivankozlov <ivankozlov@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 14:07:46 by ivankozlov        #+#    #+#             */
/*   Updated: 2019/05/01 14:22:47 by ivankozlov       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include "ZombieEvent.hpp"

#include <iostream>

/*
 * Zombie
*/

Zombie::Zombie(void) :
	_name("asd"),
	_type("default") { }

Zombie::Zombie(std::string name, std::string type) :
	_name(name),
	_type(type) { }

Zombie::Zombie(const Zombie &src)
{
	*this = src;
}

Zombie::~Zombie(void) { }

Zombie
&Zombie::operator=(const Zombie &obj)
{
	if (this == &obj)
		return *this;
	this->_type = obj.getType();
	this->_name = obj.getName();
	return *this;
}

void 		Zombie::setName(std::string const name)
{
	this->_name = name;
}
void 		Zombie::setType(std::string const type)
{
	this->_type = type;
}
std::string	Zombie::getType(void) const
{
	return this->_type;
}
std::string 	Zombie::getName(void) const
{
	return this->_name;
}

void 				Zombie::announce(void) const
{
	std::cout << "<" << this->_name;
	std::cout << " (" << this->_type << ")";
	std::cout << "> ";
	std::cout << "Braiiiiiiinnnssss..." << std::endl;
}
