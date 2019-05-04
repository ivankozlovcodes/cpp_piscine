/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivankozlov <ivankozlov@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 01:40:26 by lhernand          #+#    #+#             */
/*   Updated: 2019/05/03 19:04:06 by ivankozlov       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "FragTrap.hpp"

FragTrap::FragTrap(void) :
_name("FR4G-TP"),
_hp(100),
_maxHp(100),
_ep(100),
_maxEp(100),
_level(1),
_meleeAttackDamage(30),
_rangedAttackDamage(20),
_armorDamageReduction(5)
{
	std::cout << BCYAN << _name <<  HYELLOW << " -- start bootup sequence.";
	std::cout << RESET << std::endl;
	return ;
}

FragTrap::FragTrap(std::string name) :
_name(name),
_hp(100),
_maxHp(100),
_ep(100),
_maxEp(100),
_level(1),
_meleeAttackDamage(30),
_rangedAttackDamage(20),
_armorDamageReduction(5)
{
	srand (time(NULL));
	std::cout << BCYAN << _name <<  HYELLOW << " -- start bootup sequence.";
	std::cout << RESET << std::endl;
	return ;
}

FragTrap::~FragTrap(void)
{
	std::cout << HRED << "<" << BCYAN << this->_name  << BRED <<  "> "
			<< HPURPLE << "Dang it. I'm out !" RESET << std::endl;
  	sleep(1);
	return ;
}

FragTrap::FragTrap(FragTrap const & src)
{
	std::cout << HYELLOW << "Copying..." << std::endl;
  	std::cout << HPURPLE << "Yeahyeahyeah, just -- wait, you can actually do that?";
	std::cout << RESET << std::endl;
	(*this) = src;
}

FragTrap 	&FragTrap::operator=(FragTrap const & rhs)
{
	std::cout << HPURPLE << "What? No, nooo, you are so STUPID! Whatever. You're welcome." << std::endl;
	std::cout << HYELLOW << "FragTrap " << BGREEN << ": " << BCYAN << rhs.getName()
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
std::string 	FragTrap::getName(void) const
{
	return (this->_name);
}
unsigned int			FragTrap::getHp(void) const
{
	return (this->_hp);
}
unsigned int			FragTrap::getMaxHp(void) const
{
	return (this->_maxHp);
}
unsigned int			FragTrap::getEp(void) const
{
	return (this->_ep);
}
unsigned int			FragTrap::getMaxEp(void) const
{
	return (this->_maxEp);
}
unsigned int			FragTrap::getLevel(void) const
{
	return (this->_level);
}
unsigned int 			FragTrap::getMeleeAttackDamage(void) const
{
	return (this->_meleeAttackDamage);
}
unsigned int			FragTrap::getRangedAttackDamage(void) const
{
	return (this->_rangedAttackDamage);
}
unsigned int			FragTrap::getArmorDamageReduction(void) const
{
	return (this->_armorDamageReduction);
}

void			FragTrap::setName(std::string name)
{
	this->_name = name;
}
void			FragTrap::setHp(unsigned int hp)
{
	this->_hp = hp;
}
void			FragTrap::setMaxHp(unsigned int maxHp)
{
	this->_maxHp = maxHp;
}
void			FragTrap::setEp(unsigned int ep)
{
	this->_ep = ep;
}
void			FragTrap::setMaxEp(unsigned int maxEp)
{
	this->_maxEp = maxEp;
}
void			FragTrap::setLevel(unsigned int level)
{
	this->_level = level;
}
void			FragTrap::setMeleeAttackDamage(unsigned int meleeAttackDamage)
{
	this->_meleeAttackDamage = meleeAttackDamage;
}
void			FragTrap::setRangedAttackDamage(unsigned int rangedAttackDamage)
{
	this->_rangedAttackDamage = rangedAttackDamage;
}
void			FragTrap::setArmorDamageReduction(unsigned int armorDamageReduction)
{
	this->_armorDamageReduction = armorDamageReduction;
}
void 		FragTrap::rangedAttack(std::string const & target)
{
	if (this->getEp() > RANGEDEPCOST)
	{
		std::cout << BRED << "<" << HCYAN << this->getName() << BRED << ">" << HYELLOW << " attacks " << HCYAN << target << HYELLOW " at range with : " << BRED
				<< this->getRangedAttackDamage() << HYELLOW << " points worth of damage" << RESET << std::endl;
		this->setEp(this->getEp() - RANGEDEPCOST);
	}
	else
	{
		std::cout << HPURPLE << "Hey... Is this thing on!!! What's wrong with it why won't it shoot!!!!" << std::endl;
		std::cout << HYELLOW << "You've tried attacking with your ranged weapon but you only have " << HRED << this->getEp() << HYELLOW << " Energy points!" << RESET << std::endl;
	}
	sleep(1);
}
void 		FragTrap::meleeAttack(std::string const & target)
{
	if (this->getEp() > MELEEEPCOST)
	{
		std::cout << BRED << "<" << HCYAN << this->getName() << BRED << "> " << HYELLOW << "punches " << HCYAN << target << HYELLOW << " with : " << BRED
				<< this->getMeleeAttackDamage() << HYELLOW << " points worth of damage" << RESET << std::endl;
		this->setEp(this->getEp() - MELEEEPCOST);
	}
	else
	{
		std::cout << HPURPLE << "This is tiring... Let me catch my breath for a second... or a day" << std::endl;
		std::cout << HYELLOW << "You've tried attacking at short range but you simply won't move.  You only have " << HRED << this->getEp() << HYELLOW << " Energy points!" << RESET << std::endl;
	}
	sleep(1);
}
void 		FragTrap::takeDamage(unsigned int amount)
{
	if (this->getHp() < amount)
	{
		std::cout << HPURPLE << "I'm almost already dead..." << std::endl;
		std::cout << HYELLOW << "Armor Damage reduction activated: +" << this->getArmorDamageReduction() << std::endl;
		std::cout << BRED << "<" << HCYAN << this->getName() << BRED << ">" << HYELLOW << " took " << HRED << amount - this->getArmorDamageReduction() << HYELLOW << " points of damage!" << RESET << std::endl;
		this->setHp(ZERO);
	}
	else
	{
		std::cout << HPURPLE << "Oouchhh!!!! that hurts!" << std::endl;
		std::cout << "Armor Damage reduction activated: +" << this->getArmorDamageReduction() << std::endl;
		std::cout << BRED << "<" << HCYAN << this->getName() << BRED << ">" << HYELLOW <<  " took " << HRED << amount - this->getArmorDamageReduction() << HYELLOW << " points of damage!" << RESET << std::endl;
		this->setHp(this->getHp() - (amount - this->getArmorDamageReduction()));
	}
	printStats();
	sleep(1);
}
void 		FragTrap::beRepaired(unsigned int amount)
{
	if (this->getHp() + amount > this->getMaxHp())
	{
		std::cout << HPURPLE << "I've had enough" << std::endl;
		std::cout << HYELLOW << "You've tried healing by : " << HRED << amount << HYELLOW << " but You're already at your limit" << RESET << std::endl;
		this->setHp(this->getMaxHp());
	}
	else
	{
		std::cout << HPURPLE << "I thought I was a goner!" << std::endl;
		std::cout << HYELLOW "You've healed by " << amount << " HP." << RESET <<  std::endl;
		this->setHp(this->getHp() + amount);
	}
	if (this->getEp() + amount > this->getMaxEp())
	{
		std::cout << HPURPLE << "That's too much!" << std::endl;
		std::cout << HYELLOW << "You've tried healing by : " HRED << amount << HYELLOW << " but you're already at your limit" << RESET << std::endl;
		this->setEp(this->getMaxEp());
	}
	else
	{
		std::cout << HPURPLE << "Much obliged!" << std::endl;
		std::cout << HYELLOW << "You've recovered by " << amount << " EP." << RESET << std::endl;
		this->setEp(this->getEp() + amount);
	}
	printStats();
	sleep(1);
}

void 		FragTrap::vaulthunter_dot_exe(std::string const & target)
{
	std::string attacks[5] = {
		"Miniontrap",
		"Meat Unicycle",
		"Funzerker",
		"Mechromagician",
		"Rubber Ducky",
	};
	if (this->getEp() > SPECIALEPCOST)
	{
		std::cout << BRED << "<" << HCYAN << this->getName() << BRED << "> " << HYELLOW << "attacks " << HCYAN << target << HYELLOW << " with : "
				<< HBGREEN <<  attacks[rand() % 5] << HYELLOW <<  " for " << BRED << "50 " << HYELLOW << "points worth of damage" << RESET << std::endl;
		this->setEp(this->getEp() - SPECIALEPCOST);
	}
	else
	{
		std::cout << HPURPLE << "This is tiring... Let me catch my breath for a second... or a day" << std::endl;
		std::cout << HYELLOW << "You've tried attacking at short range but you simply won't move.  You only have " << BRED  << this->getEp() << HYELLOW << " Energy points!" << RESET <<  std::endl;
	}
	printStats();
	sleep(1);
}

void     		FragTrap::printStats( void )
{
	std::cout << HRED << "<" << BCYAN << this->_name <<  HRED << ">" << BGREEN << ": " << std::endl;
	std::cout << HYELLOW << "  Health        " << BGREEN << " : " << HGREEN << this->getHp() << std::endl;
	std::cout << HYELLOW << "  Energy Points " << BGREEN << " : " << HGREEN << this->getEp() << std::endl;
	std::cout << HYELLOW << "  Level         " << BGREEN << " : " << HGREEN << this->getLevel() << std::endl;
	std::cout << HYELLOW << "  Armor         " << BGREEN << " : " << HGREEN << this->getArmorDamageReduction();
	std::cout << RESET << std::endl;
}
