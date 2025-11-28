/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcotonea <mcotonea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 11:26:28 by mcotonea          #+#    #+#             */
/*   Updated: 2025/06/18 12:24:31 by mcotonea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#ifndef WEAPON_HPP
# define WEAPON_HPP

class Weapon{
private:

	std::string _type;

public:

	Weapon(std::string type);
	~Weapon(void);
	
	const std::string &getType(void) const;
	void setType(std::string type);
};

#endif