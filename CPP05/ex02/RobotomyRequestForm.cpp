/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melvin <melvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 19:50:44 by melvin            #+#    #+#             */
/*   Updated: 2025/07/11 19:59:13 by melvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(): AForm("Robotomy", 72, 45), _target("Default"){
	std::cout << "Robotomy default constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target): AForm("Robotomy", 72, 45), _target(target){
	std::cout << "Robotomy constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other): AForm(other), _target(other._target){
	std::cout << "Robotomy copy constructor called" << std::endl;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other){
	if (this != &other)
		this->_target = other._target;
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm(){
	std::cout << "Robotomy destructor called" << std::endl;
}

void RobotomyRequestForm::makeAction() const{
	std::cout << "Bzzzz...*drilling noises*" << std::endl;
	int r = std::rand();
	if (r % 2 == 0){
			std::cout << this->_target << " has been robotomized successfully" << std::endl;
			return ;
	}
	else{
		std::cout << "Robotomy failed on " << this->_target << std::endl;
		return;
	}
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const{
	AForm::execute(executor);
}