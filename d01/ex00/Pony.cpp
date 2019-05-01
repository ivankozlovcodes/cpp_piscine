/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pony.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivankozlov <ivankozlov@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 10:53:36 by ivankozlov        #+#    #+#             */
/*   Updated: 2019/05/01 11:09:28 by ivankozlov       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Pony.hpp"

#include <iostream>

Pony::Pony(void) :
	name("asd"),
	color("asd")
{
	greet();
}

Pony::Pony(std::string name, std::string color) :
	name(name),
	color(color)
{
	greet();
}

Pony::~Pony(void) { }

void	Pony::greet(void)
{
	std::cout << "Pony" << std::endl;
	std::cout  << "Name '" << name << "'" << std::endl;
	std::cout << "Color '" << color << "'" << std::endl;
}

Pony	*ponyOnTheHeap(void)
{
	Pony *pony = new Pony("I never", "watch my little pony");

	return pony;
}

Pony	ponyOnTheStack(void)
{
	Pony pony = Pony("So I dont", "give two shits");

	return pony;
}
