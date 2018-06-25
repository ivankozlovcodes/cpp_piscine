/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozlov <ikozlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/24 20:05:15 by ikozlov           #+#    #+#             */
/*   Updated: 2018/06/24 21:06:06 by ikozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Contact.hpp"
#include "PhoneBook.hpp"

void			printMenu(void) {
	std::cout << "Phoneboook" << std::endl;
	std::cout << "Commands:" << std::endl;
	std::cout << "ADD" << std::endl;
	std::cout << std::endl;
}

std::string		toLower(std::string s) {
	for (int i = 0; i < s.length(); i++) {
		s[i] = tolower(s[i]);
	}
	return (s);
}

PhoneBook		initPhoneBook(void) {
	int			size;

	std::cout << "Please, enter an integer for book size" << std::endl;
	std::cin >> size;
	PhoneBook book(size);
	return (book);
}

int				main(void) {
	std::string		command;

	printMenu();
	PhoneBook phoneBook = initPhoneBook();
	// next line is there in order to fix first command read
	std::getline(std::cin, command);
	while (1) {
		std::cout << "Please, enter a command" << std::endl;
		std::getline(std::cin, command);
		command = toLower(command);
		if (command == ADD_COMMAND)
			phoneBook.addContact(Contact::createNewContact());
		else
			break ;
	}
	return (0);
}
