/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melvin <melvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 14:24:50 by melvin            #+#    #+#             */
/*   Updated: 2025/07/11 19:46:33 by melvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm(): _name("Default"), _isSigned(false), _signGrade(LOWEST_GRADE), _execGrade(LOWEST_GRADE){
	std::cout << "AForm default constructor called" << std::endl;
}

AForm::AForm(const std::string& name, const int sign, const int exec): _name(name), _isSigned(false), _signGrade(sign), _execGrade(exec){
	if (sign > LOWEST_GRADE || exec > LOWEST_GRADE)
		throw AForm::GradeTooLowException();
	if (sign < HIGHEST_GRADE || exec < HIGHEST_GRADE)
		throw AForm::GradeTooHighException();
	std::cout << "AForm's parameter constructor called" << std::endl;
}

AForm::AForm(const AForm& other): _name(other._name), _isSigned(other._isSigned), _signGrade(other._signGrade), _execGrade(other._execGrade){
	std::cout << "AForm copy constructor called" << std::endl;
}

AForm& AForm::operator=(const AForm& other){
	if (this != &other)
		this->_isSigned = other._isSigned;
	return *this;
}

AForm::~AForm(){
	std::cout << "AForm destructor called" << std::endl;
}

const std::string& AForm::getName() const{
	return this->_name;
}

bool AForm::getIsSigned() const{
	return this->_isSigned;
}

int AForm::getSignGrade() const{
	return this->_signGrade;
}

int AForm::getExecGrade() const{
	return this->_execGrade;
}

void AForm::beSigned(const Bureaucrat& b){
	if (b.getGrade() > this->getSignGrade())
		throw AForm::GradeTooLowException();
	else if (this->getIsSigned() == true)
		throw AForm::AlreadySigned();
	else 
		this->_isSigned = true;
}

void AForm::execute(Bureaucrat const & executor) const{
	if (!_isSigned)
		throw AForm::NotSigned();
	if (executor.getGrade() > this->getExecGrade())
		throw AForm::GradeTooLowException();
	std::cout << executor.getName() << " executed form " << this->getName() << std::endl;
	makeAction();
}

std::ostream& operator<<(std::ostream& os, const AForm& f){
	os << "The form " << f.getName() << " is signed: " << f.getIsSigned() << std::endl
	<< "Grade required to sign it: " << f.getSignGrade() << " and grade required to execute it: " << f.getExecGrade() << std::endl;
	return os;
}
