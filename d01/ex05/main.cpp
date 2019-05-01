/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivankozlov <ivankozlov@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 16:10:31 by ivankozlov        #+#    #+#             */
/*   Updated: 2019/05/01 16:43:23 by ivankozlov       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"
#include "Human.hpp"

#include <iostream>

int 			main(void)
{
	Human bob;
	std::cout << bob.identify() << std::endl;
	Brain bobsBrain = bob.getBrain();
	std::cout << bobsBrain.identify() << std::endl;
	std::cout << bob.getBrain().identify() << std::endl;

	return (0);
}