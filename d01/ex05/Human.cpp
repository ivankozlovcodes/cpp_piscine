/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Human.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivankozlov <ivankozlov@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 16:08:52 by ivankozlov        #+#    #+#             */
/*   Updated: 2019/05/01 16:44:21 by ivankozlov       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Human.hpp"

# include <iostream>

/*
 * Human
*/

Human::Human(void) :
	_brain(Brain())
	{
		std::cout << "Default human" << std::endl;
	}


Human::Human(const Human &src)
{
	*this = src;
}

Human::~Human(void) { }

Human
&Human::operator=(const Human &obj)
{
	if (this != &obj)
		this->_brain = obj.getBrain();
	return (*this);
}

Brain
Human::getBrain(void) const
{
	return this->_brain;
}

std::string
Human::identify(void) const
{
	return this->_brain.identify();
}
