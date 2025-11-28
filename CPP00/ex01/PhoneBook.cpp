/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcotonea <mcotonea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 23:58:48 by melvin            #+#    #+#             */
/*   Updated: 2025/06/11 16:42:21 by mcotonea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include "PhoneBook.hpp"

PhoneBook::PhoneBook(){
	this->_index = 0;
	return;
}

PhoneBook::~PhoneBook(){
	return ;
}

void PhoneBook::addContact(){
	this->contacts[this->_index % 8].fill_contact();
	this->_index++;
}

void PhoneBook::searchContact() const {
	std::cout	<< std::setw(10) << "Index" << "|" 
				<< std::setw(10) << "First Name" << "|"
				<< std::setw(10) << "Last Name" << "|"
				<< std::setw(10) << "Nickname" << std::endl;
				
	for (int i = 0; i < 8 && i < this->_index; ++i) {
		std::cout 	<< std::setw(10) << i + 1 << "|"
					<< std::setw(10) << this->adaptFormat(this->contacts[i].getFirstName()) << "|"
					<< std::setw(10) << this->adaptFormat(this->contacts[i].getLastName()) << "|"
					<< std::setw(10) << this->adaptFormat(this->contacts[i].getNickName()) << std::endl;

	}

	std::cout << "Enter an index to display the contact:";
	std::string index;
	if (!std::getline(std::cin, index))
		return;
	if (index.length() == 1 && std::isdigit(index[0])){
		int ind = index[0] - '0';
		if (ind >= 1 && ind <= 8){
			const Contact &c = this->contacts[ind - 1];
			if (c.getFirstName().empty()){
				std::cout << "This contact does not exist." << std::endl;
				return;
			}
			else {
				std::cout << "First name: " << c.getFirstName() << std::endl;
				std::cout << "Last name: " << c.getLastName() << std::endl;
				std::cout << "Nickname: " << c.getNickName() << std::endl;
				std::cout << "Phone number: " << c.getPhoneNumber() << std::endl;
				std::cout << "Darkest secret: " << c.getDarkestSecret() << std::endl;
			}
		}
		else {
			std::cout << "Invalid index." << std::endl;
		}
	}
	else
		std::cout << "Invalid input." << std::endl;
	
}

std::string PhoneBook::adaptFormat(std::string str) const {
	if (str.length() > 10){
		std::string substring = str.substr(0, 10);
		substring[9] = '.';
		return (substring);
	}
	else
		return (str);
}