/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivankozlov <ivankozlov@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 10:05:58 by lhernand          #+#    #+#             */
/*   Updated: 2019/05/02 17:26:24 by ivankozlov       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Fixed.hpp"

Fixed::Fixed(void) : _fixedNumber(0)
{
	std::cout << "Default constructor called" << std::endl;
	return ;
}
Fixed::~Fixed(void)
{	std::cout << "Destructor called" << std::endl;
	return ;
}
Fixed::Fixed(Fixed const & src)
{
	std::cout << "Copy constructor called" << std::endl;
	(*this) = src;
}
Fixed  &Fixed::operator=(Fixed const & rhs)
{
	std::cout << "Assignation operator called" << std::endl;
	if (this == &rhs)
		return (*this);
	this->_fixedNumber = rhs.getRawBits();
	return (*this);
}
int 			Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return(this->_fixedNumber);
}
void 		Fixed::setRawBits(int const raw)
{
	this->_fixedNumber = raw;
}

const uint8_t Fixed::_bits = 8;
