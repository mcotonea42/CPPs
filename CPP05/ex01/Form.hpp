/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melvin <melvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 14:17:03 by melvin            #+#    #+#             */
/*   Updated: 2025/07/11 16:18:21 by melvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <exception>
#include "Bureaucrat.hpp"

#define HIGHEST_GRADE 1
#define LOWEST_GRADE 150

class Bureaucrat;

class Form{
	private:

		const std::string _name;
		bool _isSigned;
		const int _signGrade;
		const int _execGrade;

	public:

		Form();
		Form(const std::string& name, const int sign, const int exec);
		Form(const Form& other);
		Form& operator=(const Form& other);
		~Form();

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

		class AlreadySigned: public std::exception{
			public:
				virtual const char* what() const throw(){
					return "Form already signed!";
				}
		};

		const std::string& getName() const;
		bool getIsSigned() const;
		int getSignGrade() const;
		int getExecGrade() const;

		void beSigned(const Bureaucrat& b);
};
std::ostream& operator<<(std::ostream& os, const Form& f);