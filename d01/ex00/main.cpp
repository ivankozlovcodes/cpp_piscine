/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivankozlov <ivankozlov@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 11:07:21 by ivankozlov        #+#    #+#             */
/*   Updated: 2019/05/01 11:08:37 by ivankozlov       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Pony.hpp"

int		main(void)
{
	Pony *p1 = ponyOnTheHeap();
	Pony p2 = ponyOnTheStack();

	delete p1;
	return 0;
}
