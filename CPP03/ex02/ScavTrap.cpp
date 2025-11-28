/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melvin <melvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 16:07:58 by mcotonea          #+#    #+#             */
/*   Updated: 2025/06/26 14:30:58 by melvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(): ClapTrap(){
	this->_hit = 100;
	this->_energy = 50;
	this->_attack = 20;
	this->_guardianMode = false;
	std::cout << "Default constructor called for ScavTrap " << _name  << std::endl;
}

ScavTrap::ScavTrap(const std::string name): ClapTrap(name){
	this->_hit = 100;
	this->_energy = 50;
	this->_attack = 20;
	this->_guardianMode = false;
	std::cout << "Parametrized constructor called for ScavTrap " << _name << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& other): ClapTrap(other){
	this->_guardianMode = other._guardianMode;
	std::cout << "Copy constructor called for ScavTrap " << _name << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other){
	if (this != &other){
		this->_name = other._name;
		this->_hit = other._hit;
		this->_energy = other._energy;
		this->_attack = other._attack;
		this->_guardianMode = other._guardianMode;
	}
	return *this;
}

ScavTrap::~ScavTrap(){
	std::cout << "Destructor called for ScavTrap " << _name << std::endl;
}

void ScavTrap::attack(const std::string& target){
	if (_hit > 0 && _energy > 0){
		_energy--;
		std::cout << "ScavTrap " << _name << " attacks " << target <<", causing " << _attack << " points of damage!" << std::endl;
	}
	else
		std::cout << "ScavTrap " << _name << " is already destroyed." << std::endl;
}

void ScavTrap::guardGate(){
	if (_guardianMode == false){
		_guardianMode = true;
		std::cout << "From now, ScavTrap " << _name << " guards the gate." << std::endl;
 	}
	else
		std::cout << "ScavTrap " << _name << " is already guarding the gate." << std::endl;
}

void ScavTrap::printStatus() const {
    std::cout << "Name: " << _name << std::endl;
    std::cout << "Hit Points: " << _hit << std::endl;
    std::cout << "Energy Points: " << _energy << std::endl;
    std::cout << "Attack Damage: " << _attack << std::endl;
}