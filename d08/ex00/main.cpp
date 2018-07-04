/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozlov <ikozlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/03 20:24:05 by ikozlov           #+#    #+#             */
/*   Updated: 2018/07/03 21:02:42 by ikozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <list>
#include <vector>
#include <iomanip>
#include <typeinfo>
#include <iostream>

#include "easyfind.hpp"

template <typename T>
void
saveSearch(T container, int search)
{
	std::cout << "Searching in " << typeid(T).name() << std::endl;
	try
	{
		for (typename T::iterator it = container.begin(); it != container.end(); ++it)
			std::cout << *it << " ";
		std::cout << std::endl;
		int ret = easyfind(container, search);
		std::cout << "Found value [" << search << "] at index [" << ret << "]" << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "Value not found" << std::endl;
	}
}

void
testVector(size_t len, int search)
{
	std::vector<int> myvector;
	std::vector<int>::iterator it;

	for (size_t i = 0; i < len; i++)
	{
		it = myvector.begin();
		myvector.insert(it, rand() % 10);
	}
	saveSearch(myvector, search);
}

void
testList(size_t len, int search)
{
	std::list<int> list;

	for (size_t i = 0; i < len; i++)
		list.push_back(rand() % 10);
	saveSearch(list, search);
}

int				main(int ac, char **av)
{
	srand(time(0));

	if (ac != 2)
	{
		std::cout << "Usage: ./a.out number" << std::endl;
		return (0);
	}
	int search = atoi(av[1]);
	testList(10, search);
	testVector(10, search);

	return (0);
}
