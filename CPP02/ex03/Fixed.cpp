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

/* 
	Constructors:
		- Default constructor
		- Copy constructor
		- Int parameter constructor
		- Float parameter constructor
*/
Fixed::Fixed(): _value(0){}

Fixed::Fixed(const Fixed& other){
	*this = other;
	// this->_value = other.getRawBits();
}
Fixed::Fixed(const int nb){
	// _value = nb << _bits;
	_value = nb * (1 << _bits);
}

Fixed::Fixed(const float nb){
	_value = roundf(nb * (1 << _bits));
}

// Destructor
Fixed::~Fixed(){}

// Assignment operator overload
Fixed& Fixed::operator=(const Fixed& other){
	if (this != &other)
		this->_value = other.getRawBits();
	return *this;
}

// Overloading comparison operators
bool Fixed::operator>(const Fixed& fixed) const{
	return (this->_value > fixed._value);
}

bool Fixed::operator<(const Fixed& fixed) const{
	return (this->_value < fixed._value);
}

bool Fixed::operator>=(const Fixed& fixed) const{
	return (this->_value >= fixed._value);
}

bool Fixed::operator<=(const Fixed& fixed) const{
	return (this->_value <= fixed._value);
}

bool Fixed::operator==(const Fixed& fixed) const{
	return (this->_value == fixed._value);
}

bool Fixed::operator!=(const Fixed& fixed) const{
	return (this->_value != fixed._value);
}

// Overloading arithmetic operators
Fixed Fixed::operator+(const Fixed& fixed) const{
	return Fixed(this->toFloat() + fixed.toFloat());
}

Fixed Fixed::operator-(const Fixed& fixed) const{
	return Fixed(this->toFloat() - fixed.toFloat());
}

Fixed Fixed::operator*(const Fixed& fixed) const{
	return Fixed(this->toFloat() * fixed.toFloat());
}

Fixed Fixed::operator/(const Fixed& fixed) const{
	return Fixed(this->toFloat() / fixed.toFloat());
}

//Overloading incrementing operators
Fixed& Fixed::operator++(){
	++_value;
	return *this;
}

Fixed Fixed::operator++(int){
	Fixed tmp = *this;
	++_value;
	return (tmp);
}

Fixed& Fixed::operator--(){
	--_value;
	return *this;
}

Fixed Fixed::operator--(int){
	Fixed tmp = *this;
	--_value;
	return (tmp);
}

//Comparison function between two values

Fixed Fixed::min(Fixed& a, Fixed& b){
	if (a < b)
		return a;
	return b;
}

Fixed Fixed::min(const Fixed& a, const Fixed& b){
	if (a < b)
		return a;
	return b;
}

Fixed Fixed::max(Fixed& a, Fixed& b){
	if (a > b)
		return a;
	return b;
}

Fixed Fixed::max(const Fixed& a, const Fixed& b){
	if (a > b)
		return a;
	return b;
}

// Getter
int Fixed::getRawBits() const {
	return this->_value;
}

// Setter
void Fixed::setRawBits(int const raw){
	this->_value = raw;
}

// Public methods / Public member functions
float Fixed::toFloat(void) const{
	return static_cast<float>(_value) / (1 << _bits);
}

int	Fixed::toInt(void) const{
	return _value / (1 << _bits);
}

// Overloaded output stream operator
std::ostream& operator<<(std::ostream& os, const Fixed& f){
	os << f.toFloat();
	return os;
}