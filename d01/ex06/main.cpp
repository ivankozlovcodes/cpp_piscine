/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivankozlov <ivankozlov@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 16:10:31 by ivankozlov        #+#    #+#             */
/*   Updated: 2019/05/01 18:07:08 by ivankozlov       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include "HumanB.hpp"

#include <iostream>

int 			main(void)
{
	{
		Weapon		club = Weapon("crude spiked club");
		HumanA		bob("Bob", club);

		bob.attack();
		club.setType("some other type of club");
		bob.attack();
	}

	{
		Weapon		club = Weapon("crude spiked club");
		HumanB		jim("Jim");
		jim.attack();
		jim.setWeapon(club);
		jim.attack();
		club.setType("some other type of club");
		jim.attack();
	}

	return (0);
}
