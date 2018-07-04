/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozlov <ikozlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/03 20:17:46 by ikozlov           #+#    #+#             */
/*   Updated: 2018/07/03 20:55:10 by ikozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_H
# define EASYFIND_H

#include <iterator>
#include <typeinfo>

template<typename T>
int		easyfind(T container, int x)
{
	for (typename T::iterator it = container.begin(); it != container.end(); ++it)
	{
		if (*it == x)
			return (std::distance(container.begin(), it));
	}
	throw std::exception();
}

#endif
