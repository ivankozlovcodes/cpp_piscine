/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhernand <lhernand@student.42.us.or>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 01:40:43 by lhernand          #+#    #+#             */
/*   Updated: 2019/01/25 01:40:46 by lhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int 			main(void)
{
	srand (time(NULL));

	FragTrap  f1("Leo");
	FragTrap  f2;
	FragTrap  f3 = f2;
	f1.printStats();
	f2.printStats();
	f3.printStats();
	f2.meleeAttack("Leo");
	f3.rangedAttack("Leo");
	f1.takeDamage(30);
	f1.takeDamage(20);
	f1.beRepaired(25);
	f1.beRepaired(25);
	f1.vaulthunter_dot_exe("FragTrap1");
	f2.takeDamage(150);
	f1.vaulthunter_dot_exe("FragTrap2");
	f3.takeDamage(150);
	std::cout << BRED << "Overview after battle: " << RESET << std::endl;
	f1.printStats();
	f2.printStats();
	f3.printStats();


	ScavTrap  s1("Eol");
	ScavTrap  s2;
	ScavTrap  s3 = s2;
	s1.printStats();
	s2.printStats();
	s3.printStats();
	s2.meleeAttack("Eol");
	s3.rangedAttack("Eol");
	s1.takeDamage(20);
	s1.takeDamage(15);
	s1.beRepaired(30);
	s1.beRepaired(30);
	s1.challengeNewcomer("ScavTrap1");
	s2.takeDamage(150);
	s1.challengeNewcomer("ScavTrap2");
	s3.takeDamage(150);
	std::cout << BRED << "Overview after battle: " << RESET << std::endl;
	s1.printStats();
	s2.printStats();
	s3.printStats();

	return (0);
}
