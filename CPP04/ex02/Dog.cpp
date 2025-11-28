/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melvin <melvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 00:51:27 by melvin            #+#    #+#             */
/*   Updated: 2025/07/01 23:12:53 by melvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(): AAnimal(), _brain(new Brain()){
	this->type = "Dog";
	std::cout << "Default constructor for Dog class called" << std::endl;
}

Dog::Dog(const Dog& other): AAnimal(other), _brain(NULL){
	*this = other;
	std::cout << "Copy constructor for Dog class called" << std::endl;
}

Dog& Dog::operator=(const Dog& other){
	if (this != &other){
		this->type = other.type;
		if (_brain != NULL)
			delete _brain;
		this->_brain = new Brain(*other._brain);
	}
	// std::cout << "Assignment operator for Dog class called" << std::endl;
	return *this;
}

Dog::~Dog(){
	if (this->_brain)
		delete _brain;
	std::cout << "Destructor for Dog class called" << std::endl;
}

void Dog::makeSound() const{
	std::cout << "Wouaf Wouaf 🐶" << std::endl;
}

const std::string& Dog::getType() const{
	return this->type;
}

std::string Dog::getIdea(size_t i) const{
	return (this->_brain->getIdea(i));
}

void Dog::setIdea(size_t i, const std::string& idea){
	this->_brain->setIdea(i, idea);
}