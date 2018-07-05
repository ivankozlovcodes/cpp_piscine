/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozlov <ikozlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/03 22:14:09 by ikozlov           #+#    #+#             */
/*   Updated: 2018/07/04 19:20:36 by ikozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "span.hpp"

Span::Span(void) :
	_size(0) { }


Span::Span(unsigned int n) :
	_size(n) { }

Span::Span(Span &obj) 
{
	*this = obj;
	return;
}

Span::~Span(void) { }

Span &Span::operator=(Span const &r) 
{
	this->_arr = r._arr;
	return (*this);
}

void
Span::addNumber(int n)
{
	if (_arr.find(n) != _arr.end())
		throw Span::NotUniqueNumberException();
	if (_arr.size() >= _size)
		throw Span::StorageLimitException();
	_arr.insert(n);
}

int
Span::longestSpan(void)
{
	if (_arr.size() <= 1)
		throw Span::NotEnoughValuesException();
	return (*_arr.rbegin() - *_arr.begin());
}

/*
 * Span::NotUniqueNumberException Class
*/

const char
*Span::NotUniqueNumberException::message = "Error: number is not unique";

Span::NotUniqueNumberException::NotUniqueNumberException(void) { }

Span::
NotUniqueNumberException::NotUniqueNumberException(const Span::NotUniqueNumberException &src)
{
	*this = src;
}

Span::
NotUniqueNumberException::~NotUniqueNumberException(void) throw() { }

Span::NotUniqueNumberException
&Span::NotUniqueNumberException::operator= (const NotUniqueNumberException &obj)
{
	static_cast<void>(obj);
	return (*this);
}

const char*
Span::NotUniqueNumberException::what() const throw()
{
	 return (Span::NotUniqueNumberException::message);
}

/*
 * Span::NotEnoughValuesException Class
*/

const char
*Span::NotEnoughValuesException::message = "Error: span does not have enough data";

Span::NotEnoughValuesException::NotEnoughValuesException(void) { }

Span::
NotEnoughValuesException::NotEnoughValuesException(const Span::NotEnoughValuesException &src)
{
	*this = src;
}

Span::
NotEnoughValuesException::~NotEnoughValuesException(void) throw() { }

Span::NotEnoughValuesException
&Span::NotEnoughValuesException::operator= (const NotEnoughValuesException &obj)
{
	static_cast<void>(obj);
	return (*this);
}

const char*
Span::NotEnoughValuesException::what() const throw()
{
	 return (Span::NotEnoughValuesException::message);
}

/*
 * Span::StorageLimitException Class
*/

const char
*Span::StorageLimitException::message = "Error: not enough space";

Span::StorageLimitException::StorageLimitException(void) { }

Span::
StorageLimitException::StorageLimitException(const Span::StorageLimitException &src)
{
	*this = src;
}

Span::
StorageLimitException::~StorageLimitException(void) throw() { }

Span::StorageLimitException
&Span::StorageLimitException::operator= (const StorageLimitException &obj)
{
	static_cast<void>(obj);
	return (*this);
}

const char*
Span::StorageLimitException::what() const throw()
{
	 return (Span::StorageLimitException::message);
}

