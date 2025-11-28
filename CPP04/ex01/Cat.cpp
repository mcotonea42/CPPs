/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melvin <melvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 01:28:36 by melvin            #+#    #+#             */
/*   Updated: 2025/07/01 22:50:42 by melvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(): Animal(), _brain(new Brain()){
	this->type = "Cat";
	std::cout << "Default constructor for Cat class called" << std::endl;
}

Cat::Cat(const Cat& other): Animal(other), _brain(NULL){
	*this = other;
	std::cout << "Copy constructor for Cat class called" << std::endl;
}

Cat& Cat::operator=(const Cat& other){
	if (this != &other){
		this->type = other.type;
		if (_brain != NULL)
			delete _brain;
		this->_brain = new Brain(*other._brain);
	}
	// std::cout << "Assignment operator for Cat class called" << std::endl;
	return *this;
}

Cat::~Cat(){
	if (this->_brain)
		delete _brain;
	std::cout << "Destructor for Cat class called" << std::endl;
}

void Cat::makeSound() const{
	std::cout << "Meoow Meoow 🐱" << std::endl;
}

const std::string& Cat::getType() const{
	return this->type;
}

std::string Cat::getIdea(size_t i) const{
	return (this->_brain->getIdea(i));
}

void Cat::setIdea(size_t i, const std::string& idea){
	this->_brain->setIdea(i, idea);	
}