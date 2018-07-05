/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutantstack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozlov <ikozlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/04 21:08:04 by ikozlov           #+#    #+#             */
/*   Updated: 2018/07/04 21:34:01 by ikozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <list>
# include <stack>
# include <iterator>

template <typename T>
class MutantStack : public std::stack<T>
{

	public:

		MutantStack<T>(void) { }

		MutantStack<T>(MutantStack<T> const &r)
		{
			this->_list = r._list;
			return (*this);
		}

		~MutantStack<T>(void) { }

		MutantStack &operator= (MutantStack<T> const &r)
		{
			*this = r;
			return (*this);
		}

		bool		empty(void)
		{
			return (_list.empty());
		}

		size_t		size(void)
		{
			return (_list.size());
		}

		size_t		top(void)
		{
			return (_list.front());
		}

		void		push(T val)
		{
			_list.push_front(val);
		}

		void		pop(void)
		{
			_list.pop_front();
		}

		// typedef std::iterator<std::forward_iterator_tag, T> iterator;
		typedef typename std::list<T>::iterator iterator;

		iterator	begin()
		{
			return (_list.begin());
		}

		iterator end() {
			return (_list.end());
		}

	private:

		std::list<T>	_list;

};

#endif