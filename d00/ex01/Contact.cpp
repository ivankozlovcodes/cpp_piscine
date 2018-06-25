/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivankozlov <ivankozlov@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/24 19:56:21 by ikozlov           #+#    #+#             */
/*   Updated: 2018/06/25 15:27:35 by ivankozlov       ###   ########.fr       */
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
	newContact.setLastName(getInfo("last name"));
	newContact.setNickname(getInfo("nickname"));
	newContact.setLogin(getInfo("login"));
	newContact.setEmail(getInfo("email"));
	newContact.setPhone(getInfo("phone"));
	newContact.setBday(getInfo("birthday"));
	newContact.setMeal(getInfo("favorite meal"));
	newContact.setUColor(getInfo("underwear color"));
	newContact.setSecret(getInfo("darkest secret"));
	newContact._notEmpty = 1;
	return (newContact);
}

std::string		Contact::getFirstName(void) {
	return (this->_firstName);
}

std::string		Contact::getLastName(void) {
	return (this->_lastName);
}

std::string		Contact::getNickname(void) {
	return (this->_nickname);
}

void			Contact::setFirstName(std::string name) {
	this->_firstName = name;
}

void			Contact::setLastName(std::string name) {
	this->_lastName = name;
}

void			Contact::setNickname(std::string name) {
	this->_nickname = name;
}

void			Contact::setLogin(std::string name) {
	this->_login = name;
}

void			Contact::setEmail(std::string name) {
	this->_email = name;
}

void			Contact::setPhone(std::string name) {
	this->_phone = name;
}

void			Contact::setBday(std::string name) {
	this->_bday = name;
}

void			Contact::setMeal(std::string name) {
	this->_meal = name;
}

void			Contact::setUColor(std::string name) {
	this->_ucolor = name;
}

void			Contact::setSecret(std::string name) {
	this->_secret = name;
}

void			Contact::print(void) {
	std::cout << "First name: ";
	std::cout << _firstName << std::endl;
	std::cout << "Last name: ";
	std::cout << _lastName << std::endl;
	std::cout << "Nickname: ";
	std::cout << _nickname << std::endl;
	std::cout << "Login: ";
	std::cout << _login << std::endl;
	std::cout << "Email: ";
	std::cout << _email << std::endl;
	std::cout << "Phone: ";
	std::cout << _phone << std::endl;
	std::cout << "Birthday: ";
	std::cout << _bday << std::endl;
	std::cout << "Favourite meal: ";
	std::cout << _meal << std::endl;
	std::cout << "Underwear color: ";
	std::cout << _ucolor << std::endl;
	std::cout << "Darkest secret: ";
	std::cout << _secret << std::endl;
	std::cout << std::endl;
}

int				Contact::isEmpty(void) {
	return (!this->_notEmpty);
}