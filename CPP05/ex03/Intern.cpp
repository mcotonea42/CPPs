/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melvin <melvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 14:02:16 by melvin            #+#    #+#             */
/*   Updated: 2025/07/12 14:34:21 by melvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern(){
	std::cout << "Intern default constructor called" << std::endl;
}

Intern::Intern(const Intern& other){
	(void)other;
	std::cout << "Intern copy constructor called" << std::endl;
}

Intern& Intern::operator=(const Intern& other){
	(void)other;
	return *this;
}

Intern::~Intern(){
	std::cout << "Intern destructor called" << std::endl;
}

AForm* Intern::createShruberryCreationForm(const std::string& target){
	return new ShruberryCreationForm(target);
}

AForm* Intern::createRobotomyRequestForm(const std::string& target){
	return new RobotomyRequestForm(target);
}

AForm* Intern::createPresidentialPardonForm(const std::string& target){
	return new PresidentialPardonForm(target);
}

AForm* Intern::makeForm(const std::string& name_form, const std::string& target_form){
	AForm* (Intern::*create_functions[3])(const std::string&) = {&Intern::createShruberryCreationForm, &Intern::createRobotomyRequestForm, &Intern::createPresidentialPardonForm};
	std::string functions[3] = {"Shruberry", "Robotomy", "Presidential"};

	for (int i = 0; i < 3; i++){
		if (name_form == functions[i]){
			AForm* created = (this->*create_functions[i])(target_form);
			std::cout << "Intern creates " << name_form << std::endl;
			return created;
		}
	}
	std::cout << "Intern can not create a form called " << name_form << std::endl;
	return NULL;	
}
