/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivankozlov <ivankozlov@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 16:08:52 by ivankozlov        #+#    #+#             */
/*   Updated: 2019/05/01 18:06:42 by ivankozlov       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "HumanB.hpp"

# include <iostream>

/*
 * HumanB
*/

HumanB::HumanB() : _name("Ivan"), _weapon(&defaultWeapon) { }

HumanB::HumanB(std::string name) :
	_name(name),
	_weapon(&defaultWeapon) { }

HumanB::HumanB(const HumanB &src) :
	_weapon(src._weapon)
{
	*this = src;
}

HumanB::~HumanB(void) { }

HumanB
&HumanB::operator=(const HumanB &obj)
{
	if (this != &obj) {
		this->_name = obj._name;
		this->_weapon = obj._weapon;
	}
	return (*this);
}

void
HumanB::setWeapon(Weapon &weapon)
{
	this->_weapon = &weapon;
}

void
HumanB::attack(void)
{
	std::cout << this->_name << " attacks with "
		<< this->_weapon->getType() << std::endl;
}

Weapon weapon = Weapon();
Weapon &HumanB::defaultWeapon = weapon;
