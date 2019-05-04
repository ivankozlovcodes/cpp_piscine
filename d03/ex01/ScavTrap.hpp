/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhernand <lhernand@student.42.us.or>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 14:38:50 by lhernand          #+#    #+#             */
/*   Updated: 2019/01/25 14:38:51 by lhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "Colors.hpp"
# include <string>
# include <iostream>
# include <cstdlib>
# include <unistd.h>
# define ZERO 0
# define RANGEDEPCOST 15
# define MELEEEPCOST 10
# define SPECIALEPCOST 25

class ScavTrap
{
	public:
		ScavTrap(void);
		ScavTrap(std::string name);
		~ScavTrap(void);
		ScavTrap(ScavTrap const & src);
		ScavTrap &operator=(ScavTrap const & rhs);

		void 		rangedAttack(std::string const & target);
		void 		meleeAttack(std::string const & target);
		void 		takeDamage(unsigned int amount);
		void 		beRepaired(unsigned int amount);
		void      	challengeNewcomer( std::string const & challenge );
		void 		printStats(void);
		std::string 	getName(void) const;
		unsigned int			getHp(void) const;
		unsigned int			getMaxHp(void) const;
		unsigned int			getEp(void) const;
		unsigned int			getMaxEp(void) const;
		unsigned int			getLevel(void) const;
		unsigned int 			getMeleeAttackDamage(void) const;
		unsigned int			getRangedAttackDamage(void) const;
		unsigned int			getArmorDamageReduction(void) const;

		void			setName(std::string name);
		void			setHp(unsigned int hp) ;
		void			setMaxHp(unsigned int maxHp);
		void			setEp(unsigned int ep);
		void			setMaxEp(unsigned int maxEp);
		void			setLevel(unsigned int level);
		void			setMeleeAttackDamage(unsigned int meleeAttackDamage);
		void			setRangedAttackDamage(unsigned int rangedAttackDamage);
		void			setArmorDamageReduction(unsigned int armorDamageReduction);

	private:
		std::string	_name;
		unsigned int 			_hp;
		unsigned int			_maxHp;
		unsigned int			_ep;
		unsigned int			_maxEp;
		unsigned int			_level;
		unsigned int			_meleeAttackDamage;
		unsigned int			_rangedAttackDamage;
		unsigned int 			_armorDamageReduction;
};


#endif
