/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melvin <melvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 22:59:27 by melvin            #+#    #+#             */
/*   Updated: 2025/07/01 01:33:09 by melvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(): type("Default"){
	std::cout << "Default constructor for Animal class called" << std::endl;
}

Animal::Animal(const Animal& other){
	*this = other;
	std::cout << "Copy constructor for Animal class called" << std::endl;
}

Animal& Animal::operator=(const Animal& other){
	if (this != &other)
		this->type = other.type;
	// std::cout << "Assignment operator for Animal class called" << std::endl;
	return *this;
}

Animal::~Animal(){
	std::cout << "Destructor for Animal class called" << std::endl;
}

void Animal::makeSound() const{
	std::cout << "Unknown animal sound" << std::endl;
}

const std::string& Animal::getType() const{
	return this->type;
}