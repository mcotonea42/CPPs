/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcotonea <mcotonea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 08:14:07 by mcotonea          #+#    #+#             */
/*   Updated: 2025/07/02 10:12:30 by mcotonea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure(): AMateria("cure"){
	std::cout << "Cure constructor called" << std::endl;
}

Cure::Cure(const Cure& other): AMateria(other){
	std::cout << "Cure copy constructor called" << std::endl;
}

Cure& Cure::operator=(const Cure& other){
	(void)other;
	return *this;
}

Cure::~Cure(){
	std::cout << "Cure destructor called" << std::endl;
}

AMateria* Cure::clone() const{
	return new Cure(*this);	
}

void Cure::use(ICharacter& target){
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}