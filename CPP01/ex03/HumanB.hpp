/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melvin <melvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 16:46:55 by melvin            #+#    #+#             */
/*   Updated: 2025/06/13 16:56:08 by melvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

#ifndef HUMANB_HPP
# define HUMANB_HPP

class HumanB{
private:

	std::string _name;
	Weapon* _weapon;

public:

	HumanB(std::string name);
	~HumanB(void);

	void attack() const;
	void setWeapon(Weapon& weapon);
};

#endif