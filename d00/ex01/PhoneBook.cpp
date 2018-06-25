/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivankozlov <ivankozlov@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/24 20:10:27 by ikozlov           #+#    #+#             */
/*   Updated: 2018/06/25 16:12:58 by ivankozlov       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "utils.h"
#include <iostream>
#include <iomanip>

PhoneBook::PhoneBook(int capacity) {
	this->_capacity = capacity;
	this->_index = 0;
	this->_contacts = new Contact[this->_capacity];
}
PhoneBook::~PhoneBook(void) { return ; }

void			PhoneBook::addContact(Contact newContact) {
	if (this->_index == this->_capacity) {
		std::cout << "Phonebook is full" << std::endl;
		return ;
	}
	this->_contacts[this->_index++] = newContact;
}

void			PhoneBook::print(void) {
	Contact			current;
	std::string		tmp;

	std::cout << "|     Index|First Name| Last Name|  Nickname|" << std::endl;
	for (int i = 0; i < this->_index; i++) {
		current = this->_contacts[i];
		std::cout << "|" << std::setw(WIDTH) << i;
		tmp = truncate(current.getFirstName(), 10);
		std::cout << "|" << std::setw(WIDTH) << tmp;
		tmp = truncate(current.getLastName(), 10);
		std::cout << "|" << std::setw(WIDTH) << tmp;
		tmp = truncate(current.getNickname(), 10);
		std::cout << "|" << std::setw(WIDTH) << tmp;
		std::cout << "|" << std::endl;
	}
}

int				PhoneBook::index(void) {
	return (this->_index);
}

Contact			*PhoneBook::search(int idx) {
	if (idx > this->_index)
		return (NULL);
	return (&this->_contacts[idx]);
}
