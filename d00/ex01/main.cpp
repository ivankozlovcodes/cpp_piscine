/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivankozlov <ivankozlov@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/24 20:05:15 by ikozlov           #+#    #+#             */
/*   Updated: 2018/06/25 08:58:18 by ivankozlov       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Contact.hpp"
#include "PhoneBook.hpp"

void			printMenu(void) {
	std::cout << "Phoneboook" << std::endl;
	std::cout << "Commands:" << std::endl;
	std::cout << "ADD" << std::endl;
	std::cout << "SEARCH" << std::endl;
	std::cout << "MENU" << std::endl;
	std::cout << "EXIT" << std::endl;
	std::cout << std::endl;
}

std::string		toLower(std::string s) {
	for (int i = 0; i < s.length(); i++) {
		s[i] = tolower(s[i]);
	}
	return (s);
}

PhoneBook		initPhoneBook(void) {
	std::string	size;

	std::cout << "Please, enter an integer for book size" << std::endl;
	std::getline(std::cin, size);
	PhoneBook book(stoi(size));
	return (book);
}

static void		search(PhoneBook phoneBook) {
	int				index;
	std::string		dummy;
	Contact			contact;

	if (phoneBook.index() == 0) {
		std::cout << "Phonebook is empty." << std::endl;
		return ;
	}
	phoneBook.print();
	std::cout << "Enter the index of a contact: ";
	std::cin >> index;
	std::cout << std::endl;
	contact = phoneBook.search(index);
	if (!contact.isEmpty())
		contact.print();
	std::cin.clear();
	std::getline(std::cin, dummy);
}

int				main(void) {
	std::string		command;

	printMenu();
	PhoneBook phoneBook = initPhoneBook();
	while (1) {
		std::cout << "Please, enter a command" << std::endl;
		std::getline(std::cin, command);
		command = toLower(command);
		if (command == ADD_COMMAND)
			phoneBook.addContact(Contact::createNewContact());
		else if (command == SEARCH_COMMAND)
			search(phoneBook);
		else if (command == EXIT_COMMAND)
			break ;
		else if (command == "menu")
			printMenu();
		else
			std::cout << "Invalid command" << std::endl;
	}
	return (0);
}
