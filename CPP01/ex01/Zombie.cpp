/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcotonea <mcotonea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 08:47:33 by mcotonea          #+#    #+#             */
/*   Updated: 2025/06/18 09:56:37 by mcotonea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

/* 
	Default constructor of the Zombie class.
*/

Zombie::Zombie(void){}


/* 
	Zombie class destructor.
	Called automatically when a Zombie object is destroyed.
*/
Zombie::~Zombie(){
	std::cout << _name << " is destroyed" << std::endl;
}

/* 
	Displays the zombie's name followed by a message.
*/
void Zombie::announce(){
	std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

/* 
	Setter for the zombie's name.
*/

void Zombie::setName(std::string name){
	_name = name;
}