/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivankozlov <ivankozlov@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 16:05:53 by ivankozlov        #+#    #+#             */
/*   Updated: 2019/05/01 16:42:41 by ivankozlov       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

#include <sstream>

/*
 * Brain
*/

Brain::Brain(void)
{
	std::ostringstream	oss;
	oss << this;
	std::string s(oss.str());

	this->_identity = oss.str();
}

Brain::Brain(const Brain &src)
{
	*this = src;
}

Brain::~Brain(void) { }

Brain
&Brain::operator=(const Brain &obj)
{
	if (this != &obj)
		this->_identity = obj.identify();
	return (*this);
}

std::string
Brain::identify(void) const
{
	return this->_identity;
}
