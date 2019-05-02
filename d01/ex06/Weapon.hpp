/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivankozlov <ivankozlov@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 16:48:25 by ivankozlov        #+#    #+#             */
/*   Updated: 2019/05/01 17:08:59 by ivankozlov       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <string>

class Weapon
{
	public:
		Weapon(void);
		Weapon(std::string type);
		~Weapon(void);
		Weapon(Weapon const & src);
		Weapon &operator=(Weapon const & rhs);

		void					setType(std::string type);
		std::string		&getType(void);

	private:
		std::string		_type;
};

#endif
