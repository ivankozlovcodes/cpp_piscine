/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozlov <ikozlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/24 20:10:27 by ikozlov           #+#    #+#             */
/*   Updated: 2018/06/24 21:05:13 by ikozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iostream>

PhoneBook::PhoneBook(int capacity) {
	this->_capacity = capacity;
	this->_index = 0;
	this->_contacts = new Contact[this->_capacity];
}
PhoneBook::~PhoneBook(void) { return ; }

void	PhoneBook::addContact(Contact newContact) {
	if (this->_index == this->_capacity) {
		std::cout << "Phonebook is full" << std::endl;
		return ;
	}
	this->_contacts[this->_index++] = newContact;
}
