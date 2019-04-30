/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   untils.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivankozlov <ivankozlov@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/25 15:55:25 by ivankozlov        #+#    #+#             */
/*   Updated: 2019/04/29 18:08:27 by ivankozlov       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

std::string		toLower(std::string s) {
	for (size_t i = 0; i < s.length(); i++) {
		s[i] = tolower(s[i]);
	}
	return (s);
}

int				getNumber(void) {
	int		number;

	std::cin >> number;
	if (std::cin.fail()) {
		std::cout << "If you don't know what is the number I will pick one for you. ";
		std::cout << "This is going to be zero." << std::endl;
		number = 0;
	}
	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	return (number);
}

std::string		getInfo(std::string field) {
	std::string		buffer;

	std::cout << "Please, enter a ";
	std::cout << field << std::endl;
	std::getline(std::cin, buffer);
	return (buffer);
}

std::string		truncate(std::string s, size_t len) {
	if (s.length() > len) {
		s.erase(len - 1, s.length() - len + 1);
		s += '.';
	}
	return (s);
}
