/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melvin <melvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 14:24:50 by melvin            #+#    #+#             */
/*   Updated: 2025/07/11 16:11:43 by melvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(): _name("Default"), _isSigned(false), _signGrade(LOWEST_GRADE), _execGrade(LOWEST_GRADE){
	std::cout << "Form default constructor called" << std::endl;
}

Form::Form(const std::string& name, const int sign, const int exec): _name(name), _isSigned(false), _signGrade(sign), _execGrade(exec){
	if (sign > LOWEST_GRADE || exec > LOWEST_GRADE)
		throw Form::GradeTooLowException();
	if (sign < HIGHEST_GRADE || exec < HIGHEST_GRADE)
		throw Form::GradeTooHighException();
	std::cout << "Form's parameter constructor called" << std::endl;
}

Form::Form(const Form& other): _name(other._name), _isSigned(other._isSigned), _signGrade(other._signGrade), _execGrade(other._execGrade){
	std::cout << "Form copy constructor called" << std::endl;
}

Form& Form::operator=(const Form& other){
	if (this != &other)
		this->_isSigned = other._isSigned;
	return *this;
}

Form::~Form(){
	std::cout << "Form destructor called" << std::endl;
}

const std::string& Form::getName() const{
	return this->_name;
}

bool Form::getIsSigned() const{
	return this->_isSigned;
}

int Form::getSignGrade() const{
	return this->_signGrade;
}

int Form::getExecGrade() const{
	return this->_execGrade;
}

void Form::beSigned(const Bureaucrat& b){
	if (b.getGrade() > this->getSignGrade())
		throw Form::GradeTooLowException();
	else if (this->getIsSigned() == true)
		throw Form::AlreadySigned();
	else 
		this->_isSigned = true;
}

std::ostream& operator<<(std::ostream& os, const Form& f){
	os << "The form " << f.getName() << " is signed: " << f.getIsSigned() << std::endl
	<< "Grade required to sign it: " << f.getSignGrade() << " and grade required to execute it: " << f.getExecGrade() << std::endl;
	return os;
}
