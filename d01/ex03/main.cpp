/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivankozlov <ivankozlov@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 12:22:29 by ivankozlov        #+#    #+#             */
/*   Updated: 2019/05/01 15:56:02 by ivankozlov       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include "ZombieHorde.hpp"

# include "iostream"

int		main(int ac, char **av)
{
	int					size;

	size = ac >= 2 ? atoi(av[1]) : DEFAULT_N;
	ZombieHorde horde = ZombieHorde(size);
	horde.announce();
	return 0;
}
