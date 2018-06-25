/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozlov <ikozlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/24 19:56:21 by ikozlov           #+#    #+#             */
/*   Updated: 2018/06/24 20:45:14 by ikozlov          ###   ########.fr       */
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
	return (newContact);
}

std::string		Contact::getFirstName(void) {
	return (this->_firstName);
}

void			Contact::setFirstName(std::string name) {
	this->_firstName = name;
}
