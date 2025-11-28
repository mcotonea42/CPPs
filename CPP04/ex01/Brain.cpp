/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melvin <melvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 20:03:52 by melvin            #+#    #+#             */
/*   Updated: 2025/07/01 21:59:57 by melvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain(){
	std::cout << "Default constructor for Brain class called" << std::endl;
}

Brain::Brain(const Brain& other){
	*this = other;
	std::cout << "Copy constructor for Brain class called" << std::endl;
}

Brain& Brain::operator=(const Brain& other){
	for (int i = 0; i < 100; i++){
		if (this != &other)
			this->_ideas[i] = other._ideas[i];
	}
	// std::cout << "Assignment operator for Brain class called" << std::endl;
	return *this;		
}

Brain::~Brain(){
	std::cout << "Destructor for Brain class called" << std::endl;
}

std::string Brain::getIdea(size_t i) const{
	return this->_ideas[i];
}

void Brain::setIdea(size_t i, const std::string& idea){
	this->_ideas[i] = idea;
}