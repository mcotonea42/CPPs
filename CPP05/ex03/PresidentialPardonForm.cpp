/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melvin <melvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 20:05:50 by melvin            #+#    #+#             */
/*   Updated: 2025/07/11 20:10:17 by melvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(): AForm("Presidential", 25, 5), _target("Default"){
	std::cout << "Presidential default constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string& target): AForm("Presidential", 25, 5), _target(target){
	std::cout << "Presidential constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other): AForm(other), _target(other._target){
	std::cout << "Presidential copy constructor called" << std::endl;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other){
	if (this != &other)
		this->_target = other._target;
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm(){
	std::cout << "Presidential destructor called" << std::endl;
}

void PresidentialPardonForm::makeAction() const{
	std::cout << _target << " has been pardoned by Zaphod Beeblerox" << std::endl;
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const{
	AForm::execute(executor);
}