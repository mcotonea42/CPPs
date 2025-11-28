/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melvin <melvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 13:36:12 by melvin            #+#    #+#             */
/*   Updated: 2025/07/12 14:09:19 by melvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "ShruberryCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern{
	public:
	
		Intern();
		Intern(const Intern& other);
		Intern& operator=(const Intern& other);
		~Intern();

		AForm* createShruberryCreationForm(const std::string& target);
		AForm* createRobotomyRequestForm(const std::string& target);
		AForm* createPresidentialPardonForm(const std::string& target);
		AForm* makeForm(const std::string& name_form, const std::string& target_form);
};