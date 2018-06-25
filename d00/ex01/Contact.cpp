/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozlov <ikozlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/24 19:56:21 by ikozlov           #+#    #+#             */
/*   Updated: 2018/06/24 22:08:21 by ikozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include <iostream>

Contact::Contact(void) { return ; }
Contact::~Contact(void) { return ; }

std::string		getInfo(std::string field) {
	std::string		buffer;

	std::cout << "Please, enter a ";
	std::cout << field << std::endl;
	std::getline(std::cin, buffer);
	return (buffer);
}

Contact		Contact::createNewContact(void) {
	Contact		newContact;

	newContact.setFirstName(getInfo("first name"));
	newContact._notEmpty = 1;
	return (newContact);
}

std::string		Contact::getFirstName(void) {
	return (this->_firstName);
}

void			Contact::setFirstName(std::string name) {
	this->_firstName = name;
}

void			Contact::print(void) {
	std::cout << "Print contact" << std::endl;
}

int				Contact::isEmpty(void) {
	return (!this->_notEmpty);
}