/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melvin <melvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 12:11:05 by melvin            #+#    #+#             */
/*   Updated: 2025/07/12 14:31:09 by melvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShruberryCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main(){
	Intern intern;

	AForm* f1;
	AForm* f2;
	AForm* f3;
	AForm* f4;

	std::cout << "*--------------------*" << std::endl;
	f1 = intern.makeForm("Shruberry", "garden");
	std::cout << "*--------------------*" << std::endl;
	f2 = intern.makeForm("Robotomy", "Marvin");
	std::cout << "*--------------------*" << std::endl;
	f3 = intern.makeForm("Presidential", "Bob");
	std::cout << "*--------------------*" << std::endl;
	f4 = intern.makeForm("Unknown", "Luc");
	
	std::cout << "*--------------------*" << std::endl;

	if (f1) delete f1;
	if (f2) delete f2;
	if (f3) delete f3;
	if (f4) delete f4;

	return 0;
}