/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivankozlov <ivankozlov@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 16:48:29 by ivankozlov        #+#    #+#             */
/*   Updated: 2019/05/01 18:06:16 by ivankozlov       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

#include <iostream>

/*
 * Weapon
*/

Weapon::Weapon(void) : _type("Bazuka") { }

Weapon::Weapon(std::string type) : _type(type) { }

Weapon::Weapon(const Weapon &src)
{
	*this = src;
}

Weapon::~Weapon(void) { }

Weapon
&Weapon::operator=(const Weapon &rhs)
{
	if (this != &rhs)
		this->setType(rhs._type);
	return *this;
}

std::string&
Weapon::getType(void)
{
	return this->_type;
}

void
Weapon::setType(std::string type)
{
	this->_type = type;
}