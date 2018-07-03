/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozlov <ikozlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/03 14:50:44 by ikozlov           #+#    #+#             */
/*   Updated: 2018/07/03 14:55:44 by ikozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iomanip>
#include <iostream>

template <typename T>
void
print(T data)
{
	std::cout << data << std::endl;
}

template <typename T>
void
iter(T *ptr, size_t len, void (*f)(T))
{
	for (size_t i = 0; i < len; i++)
		f(ptr[i]);
}

int main( void )
{
	std::string	test[] = 
	{
		"A", "BC", "DEF", "GHIJ", "KLMNO", "PQRSTU", "VWXYZ"
	};

	char	test2[] = 
	{
		'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M'
	};

	int 	test3[] =
	{
		1, 12, 123, 1234, 12345, 123456, 1234567, 12345678, 123456789, 1234567890
	};

	double 	test4[] =
	{
		1.00, 1.20, 12.30, 12.34, 123.45, 1234.56, 12345.67, 123456.78, 1234567.89, 12345678.90
	};

	std::cout << "Testing Iter, printing an array of strings:" << std::endl;
	iter<std::string>(test, 7, &print);

	std::cout << std::endl << "Testing Iter, printing an array of char:" << std::endl;
	iter<char>(test2, 13, &print);

	std::cout << std::endl << "Testing Iter, printing an array of int:" << std::endl;
	iter<int>(test3, 10, &print);

	std::cout << std::fixed << std::setprecision(2);
	std::cout << std::endl << "Testing Iter, printing an array of double:" << std::endl;
	iter<double>(test4, 10, &print);

	return (0);
}
