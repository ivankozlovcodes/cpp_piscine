/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivankozlov <ivankozlov@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 12:25:44 by ivankozlov        #+#    #+#             */
/*   Updated: 2019/05/01 14:10:01 by ivankozlov       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <string>

class Zombie
{
	public:
		Zombie();
		Zombie(std::string name, std::string type);
		~Zombie(void);
		Zombie(Zombie const & src);
		Zombie &operator=(Zombie const & rhs);

		void		setName(std::string const name);
		void		setType(std::string const type);
		std::string	getType(void) const;
		std::string	getName(void) const;

		void 		announce(void) const;
	private:
		std::string 	_name;
		std::string 	_type;
};

#endif
