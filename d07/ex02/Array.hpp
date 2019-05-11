/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivankozlov <ivankozlov@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/03 14:59:42 by ikozlov           #+#    #+#             */
/*   Updated: 2019/05/08 14:06:08 by ivankozlov       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_H
# define ARRAY_H

template <typename T>
class Array
{

	public:

		Array<T>(void) :
			_n(0),
			_array(new T()) { }

		Array<T>(unsigned int n) :
			_n(n),
			_array(new T[n]) { }

		Array<T>(Array<T> const &r)
		{
			*this = r;
		}

		~Array<T>(void) { }

		Array<T> &operator=(Array const &r)
		{
			this->_n = r._n;
			this->_array = new T[this->_n];
			for (unsigned int i = 0; i < this->_n; i++)
				this->_array[i] = (r._array[i]);
			return (*this);
		}

		T &operator[] (unsigned int n)
		{
			if (n >= _n)
				throw std::exception();
			return (_array[n]);
		}

		unsigned int size() const
		{
			return (_n);
		}

	private:

		unsigned int	_n;
		T				*_array;
};

#endif
