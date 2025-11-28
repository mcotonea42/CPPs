/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcotonea <mcotonea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 07:56:55 by mcotonea          #+#    #+#             */
/*   Updated: 2025/07/02 10:12:47 by mcotonea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice(): AMateria("ice"){
	std::cout << "Ice constructor called" << std::endl;
}

Ice::Ice(const Ice& other): AMateria(other){
	std::cout << "Ice copy constructor called" << std::endl;
}

Ice& Ice::operator=(const Ice& other){
	(void)other;
	return *this;
}

Ice::~Ice(){
	std::cout << "Ice destructor called" << std::endl;
}

AMateria* Ice::clone() const{
	return new Ice(*this);
}

void Ice::use(ICharacter& target){
	std::cout << "*shoots an ice bolt at " << target.getName() << " *" << std::endl;
}