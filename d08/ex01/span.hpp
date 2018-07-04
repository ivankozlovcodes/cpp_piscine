/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozlov <ikozlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/03 21:05:38 by ikozlov           #+#    #+#             */
/*   Updated: 2018/07/03 22:14:04 by ikozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Span_H
# define Span_H

# include <vector>

class Span
{

	public:

		Span(void);
		Span(unsigned int n);
		Span(Span &obj);
		~Span(void);
		Span &operator=(Span const &r);

		void				addNumber(int n);
		int					shortestSpan(void);
		int					longestSpan(void);

	private:

		std::vector<int>	_arr;
		unsigned int		_size;

};

#endif