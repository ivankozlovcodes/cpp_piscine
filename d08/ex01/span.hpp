/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivankozlov <ivankozlov@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/03 21:05:38 by ikozlov           #+#    #+#             */
/*   Updated: 2018/07/04 02:35:03 by ivankozlov       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Span_H
# define Span_H

# include <vector>

class Span
{

	public:

		/*
		 *	NotUniqueNumberException class
		 */
		class NotUniqueNumberException : public std::exception
		{
			public:
				NotUniqueNumberException(void);
				NotUniqueNumberException(const NotUniqueNumberException &src);
				virtual ~NotUniqueNumberException(void) throw();

				NotUniqueNumberException &operator= (const NotUniqueNumberException &obj);

				virtual const char	*what() const throw();

				static const char	*message;
		};

		/*
		 *	NotEnoughValuesException class
		 */
		class NotEnoughValuesException : public std::exception
		{
			public:
				NotEnoughValuesException(void);
				NotEnoughValuesException(const NotEnoughValuesException &src);
				virtual ~NotEnoughValuesException(void) throw();

				NotEnoughValuesException &operator= (const NotEnoughValuesException &obj);

				virtual const char	*what() const throw();

				static const char	*message;
		};

		/*
		 *	StorageLimitException class
		 */
		class StorageLimitException : public std::exception
		{
			public:
				StorageLimitException(void);
				StorageLimitException(const StorageLimitException &src);
				virtual ~StorageLimitException(void) throw();

				StorageLimitException &operator= (const StorageLimitException &obj);

				virtual const char	*what() const throw();

				static const char	*message;
		};

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