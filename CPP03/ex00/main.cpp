/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcotonea <mcotonea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 11:30:34 by mcotonea          #+#    #+#             */
/*   Updated: 2025/06/25 15:34:44 by mcotonea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main(){
	ClapTrap Bob("Bob");

	Bob.attack("Jojo");
	Bob.takeDamage(5);
	Bob.beRepaired(3);

	Bob.takeDamage(100);
	Bob.attack("Jiji");
	Bob.beRepaired(5);

	return 0;
}