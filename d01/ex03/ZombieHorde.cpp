/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivankozlov <ivankozlov@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 14:37:01 by ivankozlov        #+#    #+#             */
/*   Updated: 2019/05/01 15:54:11 by ivankozlov       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ZombieHorde.hpp"

#include <iostream>

/*
 * ZombieHorde
*/

ZombieHorde::ZombieHorde(void) { }

ZombieHorde::ZombieHorde(int N) :
	_N(N)
{
	std::cout << _N << " Zombies created" << std::endl;
	this->_horde = new Zombie[N];
}

ZombieHorde::ZombieHorde(const ZombieHorde &src)
{
	*this = src;
}

ZombieHorde::~ZombieHorde(void)
{
	delete [] _horde;
	std::cout << "Zombie horde deleted" << std::endl;
}

ZombieHorde
&ZombieHorde::operator=(const ZombieHorde &obj)
{
	if (this != &obj)
		this->_horde = obj._horde;
	return *this;
}

void
ZombieHorde::announce(void)
{
	for (int i = 0; i < _N; i++)
		_horde[i].announce();
}