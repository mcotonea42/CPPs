/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcotonea <mcotonea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 23:53:03 by melvin            #+#    #+#             */
/*   Updated: 2025/06/11 15:46:04 by mcotonea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Contact.hpp"

/* Constructor */
Contact::Contact(void){
	return;
}

/* Destructor */
Contact::~Contact(void){
	return;
}

/* Getters */
std::string	Contact::getFirstName() const{
	return this->_firstName;
}

std::string Contact::getLastName() const{
	return this->_lastName;
}

std::string Contact::getNickName() const{
	return this->_nickName;
}

std::string Contact::getPhoneNumber() const{
	return this->_phoneNumber;
}

std::string Contact::getDarkestSecret() const{
	return this->_darkestSecret;
}

/* Setters */
void	Contact::setFirstName(std::string s){
	this->_firstName = s;
}

void	Contact::setLastName(std::string s){
	this->_lastName = s;
}

void	Contact::setNickName(std::string s){
	this->_nickName = s;
}

void	Contact::setPhoneNumber(std::string s){
	this->_phoneNumber = s;
}

void	Contact::setDarkestSecret(std::string s){
	this->_darkestSecret = s;
}

void	Contact::fill_contact(void){
	std::string input;
	
	std::cout << "Enter your first name" << std::endl;
	std::getline(std::cin, input);
	while (input.empty())
	{
		std::cout << "Input must not be empty." << std::endl;
		std::getline(std::cin, input);
	}
	setFirstName(input);
	
	std::cout << "Enter your last name" << std::endl;
	std::getline(std::cin, input);
	while (input.empty())
	{
		std::cout << "Input must not be empty." << std::endl;
		std::getline(std::cin, input);
	}
	setLastName(input);
	
	std::cout << "Enter your nickname" << std::endl;
	std::getline(std::cin, input);
	while (input.empty())
	{
		std::cout << "Input must not be empty." << std::endl;
		std::getline(std::cin, input);
	}
	setNickName(input);

	std::cout << "Enter your phone number" << std::endl;
	std::getline(std::cin, input);
	while (input.empty())
	{
		std::cout << "Input must not be empty." << std::endl;
		std::getline(std::cin, input);
	}
	setPhoneNumber(input);
	
	std::cout << "Enter your darkest secret" << std::endl;
	std::getline(std::cin, input);
	while (input.empty())
	{
		std::cout << "Input must not be empty." << std::endl;
		std::getline(std::cin, input);
	}
	setDarkestSecret(input);
}