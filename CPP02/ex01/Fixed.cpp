/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcotonea <mcotonea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 16:50:03 by mcotonea          #+#    #+#             */
/*   Updated: 2025/06/20 11:55:23 by mcotonea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

Fixed::Fixed(): _value(0){
	std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed(){
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed& other){
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
	// this->_value = other.getRawBits();
}

Fixed& Fixed::operator=(const Fixed& other){
	std::cout << "Copy assignement operator called" << std::endl;
	if (this != &other)
		this->_value = other.getRawBits();
	return *this;
}

Fixed::Fixed(const int nb){
	std::cout << "Int constructor called" << std::endl;
	// _value = nb << _bits;
	_value = nb * (1 << _bits);
}

/* 
	La fonction roundf permet d'arrondir un float a l'entier le plus proche. 
	1 << _bits = 1 << 8 = 2puissance8 = 256. 
*/
Fixed::Fixed(const float nb){
	std::cout << "Float constructor called" << std::endl;
	_value = roundf(nb * (1 << _bits));
}


int Fixed::getRawBits() const {
	return this->_value;
}

void Fixed::setRawBits(int const raw){
	this->_value = raw;
}

float Fixed::toFloat(void) const{
	return static_cast<float>(_value) / (1 << _bits);
}

int	Fixed::toInt(void) const{
	return _value / (1 << _bits);
}

std::ostream& operator<<(std::ostream& os, const Fixed& f){
	os << f.toFloat();
	return os;
}