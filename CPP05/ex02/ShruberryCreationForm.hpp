/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShruberryCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melvin <melvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 19:07:42 by melvin            #+#    #+#             */
/*   Updated: 2025/07/11 19:33:47 by melvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <fstream>
#include "AForm.hpp"

class AForm;

class ShruberryCreationForm: public AForm{
	private:

		std::string _target;

	public:

		ShruberryCreationForm();
		ShruberryCreationForm(const std::string& target);
		ShruberryCreationForm(const ShruberryCreationForm& other);
		ShruberryCreationForm& operator=(const ShruberryCreationForm& other);
		~ShruberryCreationForm();

		void makeAction() const;
		void execute(Bureaucrat const & executor) const;
};