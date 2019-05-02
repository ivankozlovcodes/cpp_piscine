/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivankozlov <ivankozlov@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 16:07:06 by ivankozlov        #+#    #+#             */
/*   Updated: 2019/05/01 18:05:59 by ivankozlov       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HumanB_HPP
# define HumanB_HPP

# include "Weapon.hpp"

# include <string.h>

class HumanB
{
	public:
		HumanB(void);
		HumanB(std::string name);
		~HumanB(void);
		HumanB(HumanB const & src);
		HumanB &operator=(HumanB const & rhs);

		void				setWeapon(Weapon &weapon);
		void				attack(void);

	private:
		std::string	_name;
		Weapon			*_weapon;

		static Weapon		&defaultWeapon;
};

#endif
