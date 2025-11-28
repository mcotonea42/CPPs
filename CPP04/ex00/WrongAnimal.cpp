/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAninal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melvin <melvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 18:56:56 by melvin            #+#    #+#             */
/*   Updated: 2025/07/01 19:32:43 by melvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(): type("Default"){
	std::cout << "Default constructor for WrongAnimal class called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& other){
	*this = other;
	std::cout << "Copy constructor for WrongAnimal class called" << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other){
	if (this != &other)
		this->type = other.type;
	// std::cout << "Assignment operator for WrongAnimal class called" << std::endl;
	return *this;
}

WrongAnimal::~WrongAnimal(){
	std::cout << "Destructor for WrongAnimal class called" << std::endl;
}

void WrongAnimal::makeSound() const{
	std::cout << "Unknown WrongAnimal sound" << std::endl;
}