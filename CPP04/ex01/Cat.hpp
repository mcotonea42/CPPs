/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melvin <melvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 01:26:46 by melvin            #+#    #+#             */
/*   Updated: 2025/07/01 22:01:06 by melvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Animal.hpp"
#include "Brain.hpp"

class Cat: public Animal{
	private:

		Brain* _brain;
		
	public:

		Cat();
		Cat(const Cat& other);
		Cat& operator=(const Cat& other);
		virtual ~Cat();

		void makeSound() const;
		const std::string& getType() const;
		std::string getIdea(size_t i) const;
		void setIdea(size_t i, const std::string& idea);
		
};