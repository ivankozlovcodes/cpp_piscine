/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivankozlov <ivankozlov@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/02 16:40:35 by ivankozlov        #+#    #+#             */
/*   Updated: 2018/07/02 18:32:46 by ivankozlov       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iomanip>
#include <iostream>

void
castInt(std::string s)
{
	std::cout << "int: ";
	try
	{
		std::cout << std::stoi(s) << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << "impossible" << std::endl;
	}
}

void
castFloat(std::string s, char _float)
{
	std::string		title = _float == 'f' ? "float: " : "double: ";
	
	std::cout << title;
	try
	{
		std::cout << static_cast<float>(std::stof(s)) << _float << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << "impossible" << std::endl;
	}
}

void
castChar(std::string s)
{
	char	res;

	std::cout << "char: ";
	try
	{
		res = static_cast<char>(std::stoi(s));
		if (res > 32 && res < 127)
			std::cout << "'" << res << "'" << std::endl;
		else
			std::cout << "Non displayable" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << "impossible" << std::endl;
	}
}

int
main(int ac, char const *av[])
{
	std::string		s;

	if (ac != 2) {
		std::cout << "Usage: ./covert value" << std::endl;
		return (0);
	}
	std::cout << std::fixed << std::setprecision(1);
	s = std::string(av[1]);
	castChar(s);
	castInt(s);
	castFloat(s, 'f');
	castFloat(s, 0);
	return (0);
}
