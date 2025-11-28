/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melvin <melvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 11:45:55 by melvin            #+#    #+#             */
/*   Updated: 2025/07/11 15:26:41 by melvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <exception>
#include "Form.hpp"

#define HIGHEST_GRADE 1
#define LOWEST_GRADE 150

class Form;

class Bureaucrat{
	private:

		const std::string _name;
		int _grade;
	
	public:

		Bureaucrat();
		Bureaucrat(const std::string& name, int grade);
		Bureaucrat(const Bureaucrat& other);
		Bureaucrat& operator=(const Bureaucrat& other);
		~Bureaucrat();

		class GradeTooHighException: public std::exception{
			public:
				virtual const char* what() const throw(){
					return "Grade too high!";
				}
		};

		class GradeTooLowException: public std::exception{
			public:
				virtual const char* what() const throw(){
					return "Grade too low!";
				}
		};

		const std::string& getName() const;
		int getGrade() const;

		void promoteBureaucrate();
		void demoteBureaucrate();	

		void signForm(Form& f) const;
};
std::ostream& operator<<(std::ostream& os, const Bureaucrat& b);