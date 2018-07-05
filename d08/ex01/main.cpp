/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozlov <ikozlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/04 19:01:18 by ikozlov           #+#    #+#             */
/*   Updated: 2018/07/04 20:38:24 by ikozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "span.hpp"

int
main(void)
{
	unsigned int	n = 10;
	Span sp(n);

	sp.addNumber(10);
	try
	{
		std::cout << "Trying to add the same number" << std::endl;
		sp.addNumber(10);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	try
	{
		std::cout << "Trying to get spans with one number" << std::endl;
		std::cout << sp.longestSpan() << std::endl;
		std::cout << sp.shortestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	srand(time(NULL));
	for (int i = 1; i < n; i++)
		try
		{
			sp.addNumber(rand() % 100);
		}
		catch (const std::exception& e)
		{
			i--;
		}
	

	std::cout << "Here is numbers I generated" << std::endl;
	std::cout << sp << std::endl;
	std::cout << "Shortest span is: " << sp.shortestSpan() << std::endl;
	std::cout << "Longest span is: " << sp.longestSpan() << std::endl;

	std::cout << "Now I will add one more number to span and die with exception. Thanks" << std::endl;
	sp.addNumber(666);

	return (0);
}
