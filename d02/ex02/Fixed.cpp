/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivankozlov <ivankozlov@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 10:05:58 by lhernand          #+#    #+#             */
/*   Updated: 2019/05/02 17:32:11 by ivankozlov       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const uint8_t Fixed::_bits = 8;

Fixed::Fixed(void) : _fixedNumber(0)
{
	return ;
}
Fixed::Fixed(const int i) : _fixedNumber( i << _bits)
{
	return;
}
Fixed::Fixed(const float f) : _fixedNumber(roundf(f * (1 << _bits))) //(1 << _bits)))
{
	return;
}
Fixed::~Fixed(void)
{
	return ;
}
Fixed::Fixed(Fixed const & src)
{
	(*this) = src;
}
Fixed  &Fixed::operator=(Fixed const & rhs)
{
	if (this == &rhs)
		return (*this);
	this->_fixedNumber = rhs.getRawBits();
	return (*this);
}
int 			Fixed::getRawBits(void) const
{
	return(this->_fixedNumber);
}
void 		Fixed::setRawBits(int const raw)
{
	this->_fixedNumber = raw;
}
float 		Fixed::toFloat(void) const
{
	return (float(this->_fixedNumber) / (1 << _bits));
}
int 			Fixed::toInt(void) const
{
	return (this->_fixedNumber >> _bits);
}
std::ostream &operator<<(std::ostream & lhs, Fixed const & rhs)
{
	lhs << rhs.toFloat();
	return (lhs);
}

//arithmetic
Fixed 		Fixed::operator+(Fixed const & rhs)
{
	return(Fixed(this->toFloat() + rhs.toFloat()));
}
Fixed 		Fixed::operator-(Fixed const & rhs)
{
	return(Fixed(this->toFloat() - rhs.toFloat()));
}
Fixed 		Fixed::operator*(Fixed const & rhs)
{
	return(Fixed(this->toFloat() * rhs.toFloat()));
}
Fixed 		Fixed::operator/(Fixed const & rhs)
{
	return(Fixed(this->toFloat() / rhs.toFloat()));
}

//increments and decrements
Fixed 		&Fixed::operator++(void)
{
	++_fixedNumber;
	return(*this);
}
Fixed 		&Fixed::operator--(void)
{
	--_fixedNumber;
	return(*this);
}
Fixed 		Fixed::operator++(int)
{
	Fixed temp(*this);
	++_fixedNumber;
	return (temp);
}
Fixed 		Fixed::operator--(int)
{
	Fixed temp(*this);
	--_fixedNumber;
	return (temp);
}

//booleans
bool 		Fixed::operator==(Fixed const & rhs) const
{
	return ((this->toFloat() == rhs.toFloat()));
}
bool			Fixed::operator>(Fixed const & rhs) const
{
	return ((this->toFloat() > rhs.toFloat()));
}
bool 		Fixed::operator<(Fixed const & rhs) const
{
	return ((this->toFloat() < rhs.toFloat()));
}
bool 		Fixed::operator>=(Fixed const & rhs) const
{
	return ((this->toFloat() >= rhs.toFloat()));
}
bool 		Fixed::operator<=(Fixed const & rhs) const
{
	return ((this->toFloat() <= rhs.toFloat()));
}
bool 		Fixed::operator!=(Fixed const & rhs) const
{
	return ((this->toFloat() != rhs.toFloat()));
}

Fixed 	&min(Fixed & lhs, Fixed & rhs)
{
	if (lhs < rhs)
		return (lhs);
	return (rhs);
}
Fixed const &min(Fixed const & lhs, Fixed const & rhs)
{
	if (lhs < rhs)
		return (lhs);
	return (rhs);
}
Fixed	&max(Fixed & lhs, Fixed & rhs)
{
	if (lhs < rhs)
		return (rhs);
	return (lhs);
}
Fixed const	&max(Fixed const & lhs, Fixed const & rhs)
{
	if (lhs < rhs)
		return (rhs);
	return (lhs);
}
