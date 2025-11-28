/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcotonea <mcotonea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 11:30:34 by mcotonea          #+#    #+#             */
/*   Updated: 2025/06/27 15:18:33 by mcotonea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main()
{
	ClapTrap claptrap("Clappy");
	ScavTrap scavtrap("Scavvy");

	std::cout << "\nClavTrap functionality:" << std::endl;
	claptrap.attack("Enemy1");
	claptrap.takeDamage(5);
	claptrap.beRepaired(3);
	for (int i = 0; i < 12; ++i)
		claptrap.attack("Jojo");

	std::cout << "\nScavTrap functionality:" << std::endl;
	scavtrap.attack("Enemy2");
	scavtrap.takeDamage(20);
	scavtrap.beRepaired(10);
	scavtrap.guardGate();
	scavtrap.guardGate();

	std::cout << std::endl;

	ScavTrap ScavCopy("Scavvou");
	
	std::cout << std::endl;
	ScavCopy = scavtrap;
	ScavCopy.attack("Enemy3");
	ScavCopy.guardGate();
			
	std::cout << std::endl;
}