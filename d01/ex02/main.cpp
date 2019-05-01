/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivankozlov <ivankozlov@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 12:22:29 by ivankozlov        #+#    #+#             */
/*   Updated: 2019/05/01 14:27:37 by ivankozlov       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include "ZombieEvent.hpp"

int		main(void) {
	Zombie  *z1 = new Zombie("Ivan", "Russian");
	z1->announce();
	ZombieEvent apocalypse = ZombieEvent();

	apocalypse.setZombieType("French");
	Zombie 	*z2 = apocalypse.newZombie("Gaetan");
	z2->announce();

	ZombieEvent event1;
	ZombieEvent event2;

	event1.setZombieType("Crazy");
	event2.setZombieType("Even Crazier");

	Zombie *randomZom = event1.randomChump();
	Zombie *randomZom2 = event2.randomChump();

	randomZom->announce();
	randomZom2->announce();

	delete(z1);
	delete(z2);
	delete(randomZom);
	delete(randomZom2);
	return (0);
}