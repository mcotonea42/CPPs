/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melvin <melvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 22:59:27 by melvin            #+#    #+#             */
/*   Updated: 2025/07/01 23:19:26 by melvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

AAnimal::AAnimal(): type("Default"){
	std::cout << "Default constructor for AAnimal class called" << std::endl;
}

AAnimal::AAnimal(const AAnimal& other){
	*this = other;
	std::cout << "Copy constructor for AAnimal class called" << std::endl;
}

AAnimal& AAnimal::operator=(const AAnimal& other){
	if (this != &other)
		this->type = other.type;
	// std::cout << "Assignment operator for AAnimal class called" << std::endl;
	return *this;
}

AAnimal::~AAnimal(){
	std::cout << "Destructor for AAnimal class called" << std::endl;
}

// void AAnimal::makeSound() const{
// 	std::cout << "Unknown Aanimal sound" << std::endl;
// }

const std::string& AAnimal::getType() const{
	return this->type;
}