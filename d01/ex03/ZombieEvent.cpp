/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieEvent.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivankozlov <ivankozlov@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 14:16:20 by ivankozlov        #+#    #+#             */
/*   Updated: 2019/05/01 14:26:22 by ivankozlov       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ZombieEvent.hpp"

#include <cstdlib>

/*
 * ZombieEvent
*/

ZombieEvent::ZombieEvent(void)
{
	std::srand(std::time(NULL));
}

ZombieEvent::ZombieEvent(const ZombieEvent &src)
{
	*this = src;
}

ZombieEvent::~ZombieEvent(void) { }

ZombieEvent
&ZombieEvent::operator=(const ZombieEvent &obj)
{
	if (this == &obj)
		return *this;
	this->_type = obj.getZombieType();
	return *this;
}

void 		ZombieEvent::setZombieType(std::string newType)
{
	this->_type = newType;
}

std::string 	ZombieEvent::getZombieType(void) const
{
	return (this->_type);
}

Zombie 		*ZombieEvent::newZombie(std::string const name)
{
	Zombie 	*z = new Zombie(name, _type);
	return z;
}

Zombie 		*ZombieEvent::randomChump(void)
{
	std::string ranNames[7] = { "Kamryn", "Hadley", "Gavin", "Karen", "Jan",
		"Laurel", "Sage" };

	Zombie *z = new Zombie(ranNames[rand() % 6], this->_type);
	return (z);
}
