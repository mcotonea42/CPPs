/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcotonea <mcotonea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 11:30:34 by mcotonea          #+#    #+#             */
/*   Updated: 2025/06/27 15:44:09 by mcotonea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int main()
{
	{
		std::cout << "\nClavTrap functionality:" << std::endl;
		
		ClapTrap claptrap("Clappy");
		claptrap.attack("Enemy1");
		claptrap.takeDamage(5);
		claptrap.beRepaired(3);
		for (int i = 0; i < 12; ++i)
		claptrap.attack("Jojo");	
	}
	{
		std::cout << "\nScavTrap functionality:" << std::endl;
		
		ScavTrap scavtrap("Scavvy");
		scavtrap.attack("Enemy2");
		scavtrap.takeDamage(20);
		scavtrap.beRepaired(10);
		scavtrap.guardGate();
		scavtrap.guardGate();
	}		
	{
		std::cout << "\nFragTrap functionality:" << std::endl;
	
		FragTrap fragtrap("Fraggy");
		fragtrap.attack("Enemy3");
		fragtrap.takeDamage(30);
		fragtrap.beRepaired(20);
		fragtrap.highFiveGuys();
	}
	{
		std::cout << "\nDiamondTrap functionality:" << std::endl;
	
		DiamondTrap d1("Bob");
		d1.attack("Enemy4");
		d1.takeDamage(25);
		d1.beRepaired(13);
		d1.whoAmI();
	}
	return 0;
}