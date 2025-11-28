/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcotonea <mcotonea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 16:23:37 by melvin            #+#    #+#             */
/*   Updated: 2025/06/19 10:22:54 by mcotonea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

#ifndef HUMANA_HPP
# define HUMANA_HPP

class HumanA{
private:

	std::string _name;
	Weapon& _weapon;

public:

	HumanA(std::string name, Weapon& weapon);
	~HumanA();

	void attack() const;
};

#endif