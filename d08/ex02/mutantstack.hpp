/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutantstack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozlov <ikozlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/04 21:08:04 by ikozlov           #+#    #+#             */
/*   Updated: 2018/07/06 19:09:40 by ikozlov          ###   ########.fr       */
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
		~MutantStack<T>(void) { }

		MutantStack<T>(MutantStack<T> const &r) : std::stack<T>(r) { }

		MutantStack &operator= (MutantStack<T> const &r)
		{
			return (std::stack<T>::operator=(r));
		}

		typedef typename std::stack<T>::container_type::iterator iterator;

		iterator	begin()
		{
			return (this->c.begin());
		}

		iterator end()
		{
			return (this->c.end());
		}

};

#endif
