/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivankozlov <ivankozlov@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 10:06:06 by lhernand          #+#    #+#             */
/*   Updated: 2019/05/02 17:25:51 by ivankozlov       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <string>

class Fixed
{
	public:
		Fixed(void);
		~Fixed(void);
		Fixed(Fixed const & src);
		Fixed &operator=(Fixed const & rhs);

		int 					getRawBits(void) const;
		void 				setRawBits(int const raw);
	private:
		int					_fixedNumber;
		static const uint8_t	_bits;
};

#endif
