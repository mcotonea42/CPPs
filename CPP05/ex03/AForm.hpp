/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melvin <melvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 14:17:03 by melvin            #+#    #+#             */
/*   Updated: 2025/07/11 18:59:44 by melvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <exception>
#include "Bureaucrat.hpp"

#define HIGHEST_GRADE 1
#define LOWEST_GRADE 150

class Bureaucrat;

class AForm{
	private:

		const std::string _name;
		bool _isSigned;
		const int _signGrade;
		const int _execGrade;

	public:

		AForm();
		AForm(const std::string& name, const int sign, const int exec);
		AForm(const AForm& other);
		AForm& operator=(const AForm& other);
		virtual ~AForm();

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

		class NotSigned: public std::exception{
			public:
				virtual const char* what() const throw(){
					return "Form not signed.";
				}
		};

		const std::string& getName() const;
		bool getIsSigned() const;
		int getSignGrade() const;
		int getExecGrade() const;

		void beSigned(const Bureaucrat& b);
		virtual void makeAction() const = 0;
		void execute(Bureaucrat const & executor) const;
		
};
std::ostream& operator<<(std::ostream& os, const AForm& f);