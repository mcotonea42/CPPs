/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melvin <melvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 19:34:21 by melvin            #+#    #+#             */
/*   Updated: 2025/07/01 19:41:52 by melvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat(): WrongAnimal(){
	this->type = "WrongCat";
	std::cout << "Default constructor for WrongCat class called" << std::endl;
}

WrongCat::WrongCat(const WrongCat& other): WrongAnimal(other){
	*this = other;
	std::cout << "Copy constructor for WrongCat class called" << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat& other){
	if (this != &other)
		this->type = other.type;
	// std::cout << "Assignment constructor for WrongCat class called" << std::endl;
	return *this;
}

WrongCat::~WrongCat(){
	std::cout << "Destructor for WrongCat class called" << std::endl;
}

void WrongCat::makeSound() const{
	std::cout << "Meo...(this seems to be a WrongCat)" << std::endl;
}