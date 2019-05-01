/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieHorde.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivankozlov <ivankozlov@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 14:35:50 by ivankozlov        #+#    #+#             */
/*   Updated: 2019/05/01 14:51:54 by ivankozlov       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIEEVENT_HPP
# define ZOMBIEEVENT_HPP

# include "Zombie.hpp"

# define DEFAULT_N 10

class ZombieHorde
{
	public:
		ZombieHorde(void);
		ZombieHorde(int N);
		~ZombieHorde(void);
		ZombieHorde(ZombieHorde const & src);
		ZombieHorde &operator=(ZombieHorde const & rhs);

		void 	announce(void);

	private:
		Zombie	*_horde;
		int 		_N;
};

#endif
