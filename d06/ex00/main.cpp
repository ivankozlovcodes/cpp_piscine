/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivankozlov <ivankozlov@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/02 16:40:35 by ivankozlov        #+#    #+#             */
/*   Updated: 2018/07/02 16:50:23 by ivankozlov       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int
castInt(std::string s)
{
	int		res;

	try
	{
		res = std::stoi(s);
	}
	catch (const std::exception &e)
	{
		std::cout << "Impossible" <<std::endl;
	}
	return (res);
}

int
main(int ac, char const *av[])
{
	std::string		s;

	if (ac != 2) {
		std::cout << "Usage: ./covert value" << std::endl;
		return (0);
	}
	s = std::string(av[1]);
	std::cout << castInt(s) <<std::endl;
	return (0);
}
