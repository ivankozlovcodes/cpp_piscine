/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivankozlov <ivankozlov@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 16:04:19 by ivankozlov        #+#    #+#             */
/*   Updated: 2019/05/01 16:40:51 by ivankozlov       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <string>

class Brain
{
	public:
		Brain(void);
		~Brain(void);
		Brain(Brain const & src);
		Brain &operator=(Brain const & rhs);

		std::string	identify(void) const;

		private:
			std::string _identity;
};

#endif
