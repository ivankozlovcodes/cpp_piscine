/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Human.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivankozlov <ivankozlov@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 16:07:06 by ivankozlov        #+#    #+#             */
/*   Updated: 2019/05/01 16:41:41 by ivankozlov       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMAN_HPP
# define HUMAN_HPP

# include "Brain.hpp"

class Human
{
	public:
		Human(void);
		~Human(void);
		Human(Human const & src);
		Human &operator=(Human const & rhs);

		std::string	identify(void) const;
		Brain				getBrain(void) const;

	private:
		Brain				_brain;
};

#endif
