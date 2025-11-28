/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melvin <melvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 01:28:36 by melvin            #+#    #+#             */
/*   Updated: 2025/07/01 01:36:21 by melvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(): Animal(){
	this->type = "Cat";
	std::cout << "Default constructor for Cat class called" << std::endl;
}

Cat::Cat(const Cat& other): Animal(other){
	*this = other;
	std::cout << "Copy constructor for Cat class called" << std::endl;
}

Cat& Cat::operator=(const Cat& other){
	if (this != &other)
		this->type = other.type;
	// std::cout << "Assignment operator for Cat class called" << std::endl;
	return *this;
}

Cat::~Cat(){
	std::cout << "Destructor for Cat class called" << std::endl;
}

void Cat::makeSound() const{
	std::cout << "Meoow Meoow 🐱" << std::endl;
}

const std::string& Cat::getType() const{
	return this->type;
}