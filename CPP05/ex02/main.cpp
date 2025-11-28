/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melvin <melvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 12:11:05 by melvin            #+#    #+#             */
/*   Updated: 2025/07/11 23:27:30 by melvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShruberryCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main(){
	Bureaucrat bob("Bob", 1);
	Bureaucrat max("Max" ,150);
	
	ShruberryCreationForm garden("Garden");
	RobotomyRequestForm robot("Robot");
	PresidentialPardonForm pres("Pres");

	std::cout << "*--------------------*" << std::endl;
	
	try{
		bob.signForm(garden);
		garden.execute(bob);
	}
	catch (std::exception& e){
		std::cout << "Exception catched: " << e.what() << std::endl;
	}
	std::cout << "*--------------------*" << std::endl;

	try {
		bob.signForm(robot);
		robot.execute(max);
	}
	catch (std::exception& e){
		std::cout << "Exception catched: " << e.what() << std::endl;
	}

	std::cout << "*--------------------*" << std::endl;

	try{
		pres.execute(bob);	
	}
	catch (std::exception& e){
		std::cout << "Exception catched: " << e.what() << std::endl;
	}

	std::cout << "*--------------------*" << std::endl;

	return 0;
}