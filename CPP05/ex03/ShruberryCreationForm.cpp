/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShruberryCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melvin <melvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 19:13:44 by melvin            #+#    #+#             */
/*   Updated: 2025/07/11 19:33:37 by melvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShruberryCreationForm.hpp"

ShruberryCreationForm::ShruberryCreationForm(): AForm("Shruberry", 145, 137), _target("Default"){
	std::cout << "Shruberry default constructor called" << std::endl;	
}

ShruberryCreationForm::ShruberryCreationForm(const std::string& target): AForm("Shruberry", 145, 137), _target(target){
	std::cout << "Shruberry constructor called" << std::endl;
}

ShruberryCreationForm::ShruberryCreationForm(const ShruberryCreationForm& other): AForm(other), _target(other._target){
	std::cout << "Shruberry copy constructor called" << std::endl;
}

ShruberryCreationForm& ShruberryCreationForm::operator=(const ShruberryCreationForm& other){
	if (this != &other)
		this->_target = other._target;
	return *this;
}

ShruberryCreationForm::~ShruberryCreationForm(){
	std::cout << "Shruberry destructor called" << std::endl;
}

void ShruberryCreationForm::makeAction() const{
	std::ofstream outfile ((this->_target + "_shruberry").c_str());
	if (!outfile){
		std::cerr << "The outfile could not be created" << std::endl;
		return;
	}
	outfile <<
"         $$$ $$$  $ $$$\n"
"     $$$ $$/$$|$ ()|/ @, $$$\n"
"     $$/($$/$$||/$$ /_/$)_$/$$\n"
"  $() $$/$$|()|/$$/ '%\" $ ()\n"
"  $_$_$$$_$ |$ |$$/$$__$$_/$ $$$\n"
"$$$   $$$ $ $| $| /$ $ % ()$ /$$$\n"
" ()$_---()$\\$\\|$$-$$--%---()~\n"
"     $$     \\|||\n"
"             |||\n"
"             |||\n"
"             |||\n"
"       , -=-~  .-^- _\n";
	outfile.close();
}

void ShruberryCreationForm::execute(Bureaucrat const & executor) const{
	AForm::execute(executor);
}