/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivankozlov <ivankozlov@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 14:07:46 by ivankozlov        #+#    #+#             */
/*   Updated: 2019/05/01 15:51:34 by ivankozlov       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include "ZombieEvent.hpp"

#include <iostream>

/*
 * Zombie
*/

Zombie::Zombie(void)
{
	std::string ranNames[7] = { "Kamryn", "Hadley", "Gavin", "Karen", "Jan",
		"Laurel", "Sage" };
	std::string ranTypes[5] = {"NewBorn", "Old", "Runner", "Fire", "Invincible"};
	this->_name = (ranNames[rand() % 7]);
	this->_type = (ranTypes[rand() % 5]);
}

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
