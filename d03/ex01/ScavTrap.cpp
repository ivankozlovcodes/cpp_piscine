/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhernand <lhernand@student.42.us.or>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 14:38:36 by lhernand          #+#    #+#             */
/*   Updated: 2019/01/25 14:38:38 by lhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


# include "ScavTrap.hpp"

ScavTrap::ScavTrap(void) :
_name("FR4G-TP"),
_hp(100),
_maxHp(100),
_ep(50),
_maxEp(50),
_level(1),
_meleeAttackDamage(20),
_rangedAttackDamage(15),
_armorDamageReduction(3)
{
	std::cout << BCYAN << _name <<  HYELLOW << " -- start bootup sequence.";
	std::cout << RESET << std::endl;
	return ;
}

ScavTrap::ScavTrap(std::string name) :
_name(name),
_hp(100),
_maxHp(100),
_ep(50),
_maxEp(50),
_level(1),
_meleeAttackDamage(20),
_rangedAttackDamage(15),
_armorDamageReduction(3)
{
	srand (time(NULL));
	std::cout << BCYAN << _name <<  HYELLOW << " -- start bootup sequence.";
	std::cout << RESET << std::endl;
	return ;
}

ScavTrap::~ScavTrap(void)
{
	std::cout << HRED << "<" << BCYAN << this->_name  << BRED <<  "> "
			<< HBLUE << "Robot Down, robot down!" RESET << std::endl;
  	sleep(1);
	return ;
}

ScavTrap::ScavTrap(ScavTrap const & src)
{
	std::cout << HYELLOW << "Copying..." << std::endl;
  	std::cout << HBLUE << "That guy looks an awful lot like a Badass !";
	std::cout << RESET << std::endl;
	(*this) = src;
}

ScavTrap 	&ScavTrap::operator=(ScavTrap const & rhs)
{
	std::cout << HBLUE << "Holy crap, that worked?" << std::endl;
	std::cout << HYELLOW << "ScavTrap " << BGREEN << ": " << BCYAN << rhs.getName()
			<< HYELLOW << " is being copied!" << RESET <<  std::endl;
	if (this == &rhs)
		return (*this);
	this->_name = rhs.getName();
	this->_hp = rhs.getHp();
	this->_maxHp = rhs.getMaxHp();
	this->_ep = rhs.getEp();
	this->_maxEp = rhs.getMaxEp();
	this->_level = rhs.getLevel();
	this->_meleeAttackDamage = rhs.getMeleeAttackDamage();
	this->_rangedAttackDamage = rhs.getRangedAttackDamage();
	this->_armorDamageReduction = rhs.getArmorDamageReduction();
	return (*this);
}
std::string 	ScavTrap::getName(void) const
{
	return (this->_name);
}
unsigned int			ScavTrap::getHp(void) const
{
	return (this->_hp);
}
unsigned int			ScavTrap::getMaxHp(void) const
{
	return (this->_maxHp);
}
unsigned int			ScavTrap::getEp(void) const
{
	return (this->_ep);
}
unsigned int			ScavTrap::getMaxEp(void) const
{
	return (this->_maxEp);
}
unsigned int			ScavTrap::getLevel(void) const
{
	return (this->_level);
}
unsigned int 			ScavTrap::getMeleeAttackDamage(void) const
{
	return (this->_meleeAttackDamage);
}
unsigned int			ScavTrap::getRangedAttackDamage(void) const
{
	return (this->_rangedAttackDamage);
}
unsigned int			ScavTrap::getArmorDamageReduction(void) const
{
	return (this->_armorDamageReduction);
}

void			ScavTrap::setName(std::string name)
{
	this->_name = name;
}
void			ScavTrap::setHp(unsigned int hp)
{
	this->_hp = hp;
}
void			ScavTrap::setMaxHp(unsigned int maxHp)
{
	this->_maxHp = maxHp;
}
void			ScavTrap::setEp(unsigned int ep)
{
	this->_ep = ep;
}
void			ScavTrap::setMaxEp(unsigned int maxEp)
{
	this->_maxEp = maxEp;
}
void			ScavTrap::setLevel(unsigned int level)
{
	this->_level = level;
}
void			ScavTrap::setMeleeAttackDamage(unsigned int meleeAttackDamage)
{
	this->_meleeAttackDamage = meleeAttackDamage;
}
void			ScavTrap::setRangedAttackDamage(unsigned int rangedAttackDamage)
{
	this->_rangedAttackDamage = rangedAttackDamage;
}
void			ScavTrap::setArmorDamageReduction(unsigned int armorDamageReduction)
{
	this->_armorDamageReduction = armorDamageReduction;
}
void 		ScavTrap::rangedAttack(std::string const & target)
{
	if (this->getEp() > RANGEDEPCOST)
	{
		std::cout << BRED << "<" << HCYAN << this->getName() << BRED << ">" << HYELLOW << " attacks " << HCYAN << target << HYELLOW " at range with : " << BRED
				<< this->getRangedAttackDamage() << HYELLOW << " points worth of damage" << RESET << std::endl;
		this->setEp(this->getEp() - RANGEDEPCOST);
	}
	else
	{
		std::cout << HBLUE << "Hey... Is this thing on!!! What's wrong with it why won't it shoot!!!!" << std::endl;
		std::cout << HYELLOW << "You've tried attacking with your ranged weapon but you only have " << HRED << this->getEp() << HYELLOW << " Energy points!" << RESET << std::endl;
	}
	sleep(1);
}
void 		ScavTrap::meleeAttack(std::string const & target)
{
	if (this->getEp() > MELEEEPCOST)
	{
		std::cout << BRED << "<" << HCYAN << this->getName() << BRED << "> " << HYELLOW << "punches " << HCYAN << target << HYELLOW << " with : " << BRED
				<< this->getMeleeAttackDamage() << HYELLOW << " points worth of damage" << RESET << std::endl;
		this->setEp(this->getEp() - MELEEEPCOST);
	}
	else
	{
		std::cout << HBLUE << "This is tiring... Let me catch my breath for a second... or a day" << std::endl;
		std::cout << HYELLOW << "You've tried attacking at short range but you simply won't move.  You only have " << HRED << this->getEp() << HYELLOW << " Energy points!" << RESET << std::endl;
	}
	sleep(1);
}
void 		ScavTrap::takeDamage(unsigned int amount)
{
	if (this->getHp() < amount)
	{
		std::cout << HBLUE << "dying dying..." << std::endl;
		std::cout << HYELLOW << "Armor Damage reduction activated: +" << this->getArmorDamageReduction() << std::endl;
		std::cout << BRED << "<" << HCYAN << this->getName() << BRED << ">" << HYELLOW << " took " << HRED << amount - this->getArmorDamageReduction() << HYELLOW << " points of damage!" << RESET << std::endl;
		this->setHp(ZERO);
	}
	else
	{
		std::cout << HBLUE << "Well that's inconvenient" << std::endl;
		std::cout << "Armor Damage reduction activated: +" << this->getArmorDamageReduction() << std::endl;
		std::cout << BRED << "<" << HCYAN << this->getName() << BRED << ">" << HYELLOW <<  " took " << HRED << amount - this->getArmorDamageReduction() << HYELLOW << " points of damage!" << RESET << std::endl;
		this->setHp(this->getHp() - (amount - this->getArmorDamageReduction()));
	}
	printStats();
	sleep(1);
}
void 		ScavTrap::beRepaired(unsigned int amount)
{
	if (this->getHp() + amount > this->getMaxHp())
	{
		std::cout << HBLUE << "No more" << std::endl;
		std::cout << HYELLOW << "You've tried healing by : " << HRED << amount << HYELLOW << " but You're already at your limit" << RESET << std::endl;
		this->setHp(this->getMaxHp());
	}
	else
	{
		std::cout << HBLUE << "Was that close or what?" << std::endl;
		std::cout << HYELLOW "You've healed by " << amount << " HP." << RESET <<  std::endl;
		this->setHp(this->getHp() + amount);
	}
	if (this->getEp() + amount > this->getMaxEp())
	{
		std::cout << HBLUE << "It's spilling!" << std::endl;
		std::cout << HYELLOW << "You've tried healing by : " HRED << amount << HYELLOW << " but you're already at your limit" << RESET << std::endl;
		this->setEp(this->getMaxEp());
	}
	else
	{
		std::cout << HBLUE << "Much obliged!" << std::endl;
		std::cout << HYELLOW << "You've recovered by " << amount << " EP." << RESET << std::endl;
		this->setEp(this->getEp() + amount);
	}
	printStats();
	sleep(1);
}

void 		ScavTrap::challengeNewcomer(std::string const & target)
{
	std::string attacks[5] = {
		"Dance for me monkey, DANCE!!!! ",
		"Go To a dark circular room. Find the corner and sit there... ",
		"Make your nose and elbow touch... without disassmebling any parts of yourself",
		"Take a cold shower with your circuit board's door ajar",
		"Turn off your own power supply and turn in it back on afterwards... Bwahahahah!"
	};
	if (this->getEp() > SPECIALEPCOST)
	{
		std::cout << BRED << "<" << HCYAN << this->getName() << BRED << "> " << HYELLOW << "attacks " << HCYAN << target << HYELLOW << " with : "
				<< HBGREEN <<  attacks[rand() % 5] << HYELLOW <<  " for " << BRED << "50 " << HYELLOW << "points worth of damage" << RESET << std::endl;
		this->setEp(this->getEp() - SPECIALEPCOST);
	}
	else
	{
		std::cout << HBLUE << "This is tiring... Let me catch my breath for a second... or a day" << std::endl;
		std::cout << HYELLOW << "You've tried attacking at short range but you simply won't move.  You only have " << BRED  << this->getEp() << HYELLOW << " Energy points!" << RESET <<  std::endl;
	}
	printStats();
	sleep(1);
}

void     		ScavTrap::printStats( void )
{
	std::cout << HRED << "<" << BCYAN << this->_name <<  HRED << ">" << BGREEN << ": " << std::endl;
	std::cout << HYELLOW << "  Health        " << BGREEN << " : " << HGREEN << this->getHp() << std::endl;
	std::cout << HYELLOW << "  Energy Points " << BGREEN << " : " << HGREEN << this->getEp() << std::endl;
	std::cout << HYELLOW << "  Level         " << BGREEN << " : " << HGREEN << this->getLevel() << std::endl;
	std::cout << HYELLOW << "  Armor         " << BGREEN << " : " << HGREEN << this->getArmorDamageReduction();
	std::cout << RESET << std::endl;
}
