/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melvin <melvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 00:51:27 by melvin            #+#    #+#             */
/*   Updated: 2025/07/01 01:33:13 by melvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(): Animal(){
	this->type = "Dog";
	std::cout << "Default constructor for Dog class called" << std::endl;
}

Dog::Dog(const Dog& other): Animal(other){
	*this = other;
	std::cout << "Copy constructor for Dog class called" << std::endl;
}

Dog& Dog::operator=(const Dog& other){
	if (this != &other)
		this->type = other.type;
	// std::cout << "Assignment operator for Dog class called" << std::endl;
	return *this;
}

Dog::~Dog(){
	std::cout << "Destructor for Dog class called" << std::endl;
}

void Dog::makeSound() const{
	std::cout << "Wouaf Wouaf 🐶" << std::endl;
}

const std::string& Dog::getType() const{
	return this->type;
}