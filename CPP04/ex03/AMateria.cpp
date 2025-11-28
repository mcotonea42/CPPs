/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcotonea <mcotonea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 07:39:06 by mcotonea          #+#    #+#             */
/*   Updated: 2025/07/02 12:47:53 by mcotonea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria(std::string const &type): type(type){
	std::cout << "AMateria constructor called" << std::endl;
}

AMateria::AMateria(const AMateria& other){
	*this = other;
	std::cout << "AMateria copy constructor called" << std::endl;
}

AMateria& AMateria::operator=(const AMateria &other){
	if (this != &other)
		this->type = other.type;
	return *this;
}

AMateria::~AMateria(){
	std::cout << "AMateria destructor called" << std::endl;
}

std::string const &AMateria::getType() const{
	return this->type;
}

void AMateria::use(ICharacter& target){
	(void)target;
}