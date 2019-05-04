/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhernand <lhernand@student.42.us.or>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 01:40:34 by lhernand          #+#    #+#             */
/*   Updated: 2019/01/25 01:40:35 by lhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "Colors.hpp"
# include <string>
# include <iostream>
# include <cstdlib>
# include <unistd.h>
# define ZERO 0
# define RANGEDEPCOST 15
# define MELEEEPCOST 10
# define SPECIALEPCOST 25

class FragTrap
{
	public:
		FragTrap(void);
		FragTrap(std::string name);
		~FragTrap(void);
		FragTrap(FragTrap const & src);
		FragTrap &operator=(FragTrap const & rhs);

		void 		rangedAttack(std::string const & target);
		void 		meleeAttack(std::string const & target);
		void 		takeDamage(unsigned int amount);
		void 		beRepaired(unsigned int amount);
		void 		vaulthunter_dot_exe(std::string const & target);
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
