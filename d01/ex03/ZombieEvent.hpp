/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieEvent.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivankozlov <ivankozlov@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 14:13:48 by ivankozlov        #+#    #+#             */
/*   Updated: 2019/05/01 14:18:22 by ivankozlov       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIEEVENT_HPP
# define ZOMBIEEVENT_HPP

# include "Zombie.hpp"

# include <string>
# include <iostream>

class ZombieEvent
{
	public:
		ZombieEvent(void);
		~ZombieEvent(void);
		ZombieEvent(ZombieEvent const & src);
		ZombieEvent &operator=(ZombieEvent const & rhs);

		void 					setZombieType(std::string const type);
		std::string 	getZombieType(void) const;
		Zombie 				*newZombie(std::string const name);
		Zombie 				*randomChump(void);

	private:
		std::string 	_type;
};

#endif
