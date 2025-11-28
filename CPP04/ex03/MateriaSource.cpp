/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcotonea <mcotonea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 12:13:00 by mcotonea          #+#    #+#             */
/*   Updated: 2025/07/02 12:59:14 by mcotonea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource(){
	for (int i = 0; i < 4; ++i)
		_learn[i] = NULL;
	std::cout << "MateriaSource constructor called" << std::endl;
}

MateriaSource::MateriaSource(const MateriaSource& other){
	std::cout << "MateriaSource copy constructor called" << std::endl;
	for (int i = 0; i < 4; ++i){
		if (other._learn[i])
			_learn[i] = other._learn[i]->clone();
		else
			_learn[i] = NULL;
	}
}

MateriaSource& MateriaSource::operator=(const MateriaSource& other){
	if (this != &other){
		for (int i = 0; i < 4; ++i){
			if (_learn[i])
				delete _learn[i];
			if (other._learn[i])
				_learn[i] = other._learn[i]->clone();
			else
				_learn[i] = NULL;
		}
	}
	return *this;
}

MateriaSource::~MateriaSource(){
	std::cout << "MateriaSource destructor called" << std::endl;
	for (int i = 0; i < 4; ++i){
		if (_learn[i])
			delete _learn[i];
	}
}

void MateriaSource::learnMateria(AMateria* materia){
	for (int i = 0; i < 4; ++i){
		if (_learn[i] == NULL){
			_learn[i] = materia->clone();
			std::cout << "Learn materia of type: " << materia->getType() << std::endl;
			delete materia;
			return;
		}
	}
	std::cout << "MateriaSource is full, cannot learn more materias." << std::endl;
	delete materia;
}

AMateria* MateriaSource::createMateria(std::string const & type){
	for (int i = 0; i < 4; ++i){
		if (_learn[i] && _learn[i]->getType() == type)
			return _learn[i]->clone();
	}
	std::cout << "Materia of type " << type << " is unknown." << std::endl;
	return NULL;
}