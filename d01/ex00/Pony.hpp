/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pony.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivankozlov <ivankozlov@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 10:46:56 by ivankozlov        #+#    #+#             */
/*   Updated: 2019/05/01 11:03:52 by ivankozlov       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PONY_HPP
# define PONY_HPP

# include <string>
// # include <unistd.h>

class Pony
{
	public:
		Pony(void);
		Pony(std::string name, std::string color);

		~Pony(void);

		void greet(void);

		std::string name;
		std::string color;
};

Pony  *ponyOnTheHeap(void);
Pony  ponyOnTheStack(void);

#endif