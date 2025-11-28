/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melvin <melvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 17:28:56 by melvin            #+#    #+#             */
/*   Updated: 2025/06/26 19:06:47 by melvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(): ClapTrap(){
	this->_hit = 100;
	this->_energy = 100;
	this->_attack = 30;
	std::cout << "Default constructor called for FragTrap " << _name << std::endl;
}

FragTrap::FragTrap(const std::string name): ClapTrap(name){
	this->_hit = 100;
	this->_energy = 100;
	this->_attack = 30;
	std::cout << "Parametrized constructor called for FragTrap " << _name << std::endl;
}

FragTrap::FragTrap(const FragTrap& other): ClapTrap(other){
	std::cout << "Copy constructor called for FrapTrap " << _name << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& other){
	if (this != &other){
		this->_name = other._name;
		this->_hit = other._hit;
		this->_energy = other._energy;
		this->_attack = other._attack;
	}
	return *this;
}

FragTrap::~FragTrap(){
	std::cout << "Destructor called for FragTrap " << _name << std::endl;
}

void FragTrap::highFiveGuys(){
	std::cout << "FragTrap " << _name << " is asking  for high five! ✋" << std::endl;
}

