/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivankozlov <ivankozlov@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 16:07:06 by ivankozlov        #+#    #+#             */
/*   Updated: 2019/05/01 17:29:00 by ivankozlov       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

# include "Weapon.hpp"

# include <string.h>

class HumanA
{
	public:
		HumanA(void);
		HumanA(std::string name, Weapon &weapon);
		~HumanA(void);
		HumanA(HumanA const & src);
		HumanA &operator=(HumanA const & rhs);

		void				attack(void);

	private:
		std::string	_name;
		Weapon			&_weapon;

		static Weapon		&defaultWeapon;
};

#endif
