/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivankozlov <ivankozlov@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 16:08:52 by ivankozlov        #+#    #+#             */
/*   Updated: 2019/05/01 17:35:08 by ivankozlov       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "HumanA.hpp"

# include <iostream>

/*
 * HumanA
*/

HumanA::HumanA() : _name("Ivan"), _weapon(defaultWeapon) { }

HumanA::HumanA(std::string name, Weapon &weapon) :
	_name(name),
	_weapon(weapon) { }

HumanA::HumanA(const HumanA &src) :
	_weapon(src._weapon)
{
	*this = src;
}

HumanA::~HumanA(void) { }

HumanA
&HumanA::operator=(const HumanA &obj)
{
	if (this != &obj) {
		this->_name = obj._name;
		this->_weapon = obj._weapon;
	}
	return (*this);
}

void
HumanA::attack(void)
{
	std::cout << this->_name << " attacks with "
		<< this->_weapon.getType() << std::endl;
}

Weapon defaultw = Weapon();
Weapon &HumanA::defaultWeapon = defaultw;
