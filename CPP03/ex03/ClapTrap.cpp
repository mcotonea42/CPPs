/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcotonea <mcotonea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 12:31:11 by mcotonea          #+#    #+#             */
/*   Updated: 2025/06/25 16:38:04 by mcotonea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(): _name("Default"), _hit(10), _energy(10), _attack(0){
	std::cout << "Default constructor called for ClapTrap " << _name << std::endl;
}

ClapTrap::ClapTrap(const std::string name): _name(name), _hit(10), _energy(10), _attack(0){
	std::cout << "Parametrized constructor called for ClapTrap " << _name << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other): _name(other._name), _hit(other._hit), _energy(other._energy), _attack(other._attack){
	std::cout << "Copy constructor called for ClapTrap " << _name << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other){
	std::cout << "Copy assignment operator called for ClapTrap " << _name << std::endl;
	if (this != &other){
		this->_name = other._name;
		this->_hit = other._hit;
		this->_energy = other._energy;
		this->_attack = other._attack;
	}
	return *this;
}

ClapTrap::~ClapTrap(){
	std::cout << "Destructor called for ClapTrap " << _name << std::endl;
}


// Attacks and repairing costs 1 points each.
// ClapTrap can't do anything if it has no hit points or energy points left

void ClapTrap::attack(const std::string& target){
	if (_hit > 0 && _energy > 0){
		_energy--;
		std::cout << "ClapTrap " << _name << " attacks " << target << ", causing " << _attack << " points of damage!" << std::endl;
	}
	else
		std::cout << "ClapTrap " << _name << " can't attack!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int mount){
	if (_hit == 0){
		std::cout << "ClapTrap " << _name << " is already destroyed." << std::endl;
		return ;
	}
	if (mount >= _hit)
		_hit = 0;
	else
		_hit -= mount;
	std::cout << "ClapTrap " << _name << " takes " << mount << " points of damage!" << std::endl;
}

void ClapTrap::beRepaired(unsigned int mount){
	if (_hit > 0 && _energy > 0){
		_energy--;
		_hit += mount;
		std::cout << "ClapTrap " << _name << " is repaired for " << mount << " hits points." << std::endl;
	}
	else
		std::cout << "ClapTrap " << _name << " can't be repaired!" << std::endl;
}