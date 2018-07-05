/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozlov <ikozlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/04 19:01:18 by ikozlov           #+#    #+#             */
/*   Updated: 2018/07/04 19:08:25 by ikozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "span.hpp"

int
main(void)
{
	Span sp(10);

	sp.addNumber(10);
	try
	{
		sp.addNumber(10);
		// std::cout << sp.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	sp.addNumber(1);
	std::cout << sp.longestSpan() << std::endl;

	return (0);
}
