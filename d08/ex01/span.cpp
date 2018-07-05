/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozlov <ikozlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/03 22:14:09 by ikozlov           #+#    #+#             */
/*   Updated: 2018/07/04 20:32:20 by ikozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <climits>

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

std::ostream
&operator<< (std::ostream &out, const Span &obj)
{
	obj.print(out);
	return (out);
}

void
Span::print(std::ostream &os) const
{
	std::set<int>::iterator it;

	for (it = _arr.begin(); it != _arr.end(); it++) {
		os << *it << " ";
	}
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

int
Span::shortestSpan(void)
{
	int		res = INT_MAX;
	std::set<int>::iterator it;
	std::set<int>::iterator nx;

	for (it = _arr.begin(),\
			nx = std::next(it, 1); nx != it; it++)
	{
		if (nx != _arr.end() && (*nx - *it < res))
			res = *nx - *it;
	}
	return (res);
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

