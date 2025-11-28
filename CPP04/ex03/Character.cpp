/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcotonea <mcotonea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 09:38:40 by mcotonea          #+#    #+#             */
/*   Updated: 2025/07/02 12:58:30 by mcotonea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character(): _name("Default"), _droppedCount(0){
	std::cout << "Character constructor called" << std::endl;
	for (int i = 0; i < 4; ++i)
		_inventory[i] = NULL;
	for (int i = 0; i < 20; ++i)
		_dropped[i] = NULL;
}

Character::Character(std::string name): _name(name), _droppedCount(0){
	std::cout << "Character constructor with name called" << std::endl;
	for (int i = 0; i < 4; ++i)
		_inventory[i] = NULL;
	for (int i = 0; i < 20; ++i)
		_dropped[i] = NULL;
}

Character::Character(const Character& other): _name(other._name), _droppedCount(other._droppedCount){
	std::cout << "Character copy constructor called" << std::endl;
	for (int i = 0; i < 4; ++i){
		if (other._inventory[i])
			_inventory[i] = other._inventory[i]->clone();
		else
			_inventory[i] = NULL;
	}
	for (int i = 0; i < 20; ++i){
		if (i < _droppedCount && other._dropped[i])
			_dropped[i] = other._dropped[i]->clone();
		else
			_dropped[i] = NULL;
	}
}

Character& Character::operator=(const Character& other){
	if (this != &other){
		this->_name = other._name;
		for (int i = 0; i < 4; ++i){
			if (_inventory[i])
				delete _inventory[i];
			if (other._inventory[i])
				_inventory[i] = other._inventory[i]->clone();
			else 
				_inventory[i] = NULL;			
		}
		for (int i = 0; i < 20; ++i){
			if (_dropped[i])
				delete _dropped[i];
			if (i < _droppedCount && other._dropped[i])
				_dropped[i] = other._dropped[i]->clone();
			else
				_dropped[i] = NULL;
		}
	}
	return *this;
}

Character::~Character(){
	for (int i = 0; i < 4; ++i){
		if (_inventory[i])
			delete _inventory[i];
	}
	for (int i = 0; i < 20; ++i){
		if (_dropped[i])
			delete _dropped[i];
	}
	std::cout << "Character destructor called" << std::endl;
}

std::string const &Character::getName() const {
	return this->_name;
}

void Character::equip(AMateria* m) {
	if (!m)
		return;
    for (int i = 0; i < 4; ++i){
		if (_inventory[i] == m){
			std::cout << "Materia " << m->getType() << " is already equipped." << std::endl;
			return ;
		}
	}
    for (int i = 0; i < 4; ++i){
        if (!_inventory[i]){
            _inventory[i] = m;
			std::cout << "Materia " << m->getType() << " equipped in slot " << i << "." << std::endl;
            return;
        }
    }
	std::cout << "Cannot equip materia " << m->getType() << ": inventory is full." << std::endl;
}

void Character::unequip(int idx) {
	if (idx < 0 || idx >= 4){
		std::cout << "Cannot unequip: invalid slot index " << idx << "." << std::endl;
		return;
	}
	if (_inventory[idx] == NULL){
		std::cout << "Cannot unequip: slot " << idx << " is already empty." << std::endl;
		return ;
	}
	if (_droppedCount < 20){
		_dropped[_droppedCount] = _inventory[idx];
		std::cout << "Unequipped materia " << _inventory[idx]->getType() << " from slot " << idx << "." << std::endl;
		_inventory[idx] = NULL;
	}
	else
		std::cout << "No room to store dropped materia, unequip ignored." << std::endl;
}

void Character::use(int idx, ICharacter& target){
	if (idx < 0 || idx >= 4){
		std::cout << "Cannot use materia: invalid slot index " << idx << "." << std::endl;
		return;
	}
	if (_inventory[idx] == NULL){
		std::cout << "Cannot use materia: slot " << idx << " is empty." << std::endl;
		return;
	}
    std::cout << _name << " uses materia " << _inventory[idx]->getType() << " on " << target.getName() << "." << std::endl;
    _inventory[idx]->use(target);
}
