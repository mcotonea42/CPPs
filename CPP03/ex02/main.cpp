/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcotonea <mcotonea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 11:30:34 by mcotonea          #+#    #+#             */
/*   Updated: 2025/06/27 15:30:31 by mcotonea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main()
{
	std::cout << "\nClavTrap functionality:" << std::endl;
	
	ClapTrap claptrap("Clappy");
	claptrap.attack("Enemy1");
	claptrap.takeDamage(5);
	claptrap.beRepaired(3);
	for (int i = 0; i < 12; ++i)
	claptrap.attack("Jojo");
	
	std::cout << "\nScavTrap functionality:" << std::endl;
	
	ScavTrap scavtrap("Scavvy");
	scavtrap.attack("Enemy2");
	scavtrap.takeDamage(20);
	scavtrap.beRepaired(10);
	scavtrap.guardGate();
	scavtrap.guardGate();
			
	std::cout << "\nFragTrap functionality:" << std::endl;

	FragTrap fragtrap("Fraggy");
	fragtrap.attack("Enemy3");
	fragtrap.takeDamage(30);
	fragtrap.beRepaired(20);
	fragtrap.highFiveGuys();

	std::cout << std::endl;

	return 0;
}