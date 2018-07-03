/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   A.hpp                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozlov <ikozlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/02 22:28:33 by ikozlov           #+#    #+#             */
/*   Updated: 2018/07/02 22:31:40 by ikozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef A_H
# define A_H

# include "Base.hpp"

class A : public Base
{

	public:

		A(void);
		A(const A &obj);
		virtual ~A(void);
		A &operator= (A const &src);

};

#endif