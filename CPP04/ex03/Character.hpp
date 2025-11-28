/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcotonea <mcotonea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 09:34:45 by mcotonea          #+#    #+#             */
/*   Updated: 2025/07/02 11:16:28 by mcotonea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "ICharacter.hpp"

class Character: public ICharacter{
	private:

		std::string _name;
		AMateria* _inventory[4];
		AMateria* _dropped[20];
		int _droppedCount;

	public:

		Character();
		Character(std::string name);
		Character(const Character& other);
		Character& operator=(const Character& other);
		~Character();

		std::string const &getName() const;
		void equip(AMateria* m);
		void unequip(int idx);
		void use(int idx, ICharacter& target);
};