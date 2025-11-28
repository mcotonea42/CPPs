/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcotonea <mcotonea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 13:24:04 by mcotonea          #+#    #+#             */
/*   Updated: 2025/06/27 15:14:20 by mcotonea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(): ClapTrap("Default_clap_name"){
	this->_name = "Default";
	this->_hit = FragTrap::_hit;
	this->_energy = ScavTrap::_energy;
	this->_attack = FragTrap::_attack;
	std::cout << "Default constructor called for DiamondTrap " << _name << std::endl;
}

DiamondTrap::DiamondTrap(const std::string name): ClapTrap(name + "_clap_name"){
	this->_name = name;
	this->_hit = FragTrap::_hit;
	this->_energy = ScavTrap::_energy;
	this->_attack = FragTrap::_attack;
	std::cout << "Parametrized constructor called for DiamondTrap " << _name << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& other): ClapTrap(other){
	this->_name = other._name;
	this->_hit = other._hit;
	this->_energy = other._energy;
	this->_attack = other._attack;
	std::cout << "Copy constructor called for DiamondTrap " << _name << std::endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other){
	if (this != &other){
		this->_name = other._name;
		this->_hit = other._hit;
		this->_energy = other._energy;
		this->_attack = other._attack;
		this->ClapTrap::_name = other.ClapTrap::_name;
	}
	return *this;
}

DiamondTrap::~DiamondTrap(){
	std::cout << "Destructor called for DiamondTrap " << _name << std::endl;
}

void DiamondTrap::attack(const std::string& target){
	ScavTrap::attack(target);	
}

void DiamondTrap::whoAmI(){
	std::cout << "I'm DiamondTrap " << _name << " , I'm the descendant of the ClapTrap " << ClapTrap::_name << std::endl;
}