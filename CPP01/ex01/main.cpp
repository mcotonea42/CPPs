/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcotonea <mcotonea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 08:57:46 by mcotonea          #+#    #+#             */
/*   Updated: 2025/06/19 10:09:22 by mcotonea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(){
	int N = 5;
	if (N <= 0){
		std::cerr << "The horde must include at least one zombie." << std::endl;
		return 1;
	}
	
	Zombie* horde = zombieHorde(N, "ZombieHorde");
	if (!horde){
		std::cerr << "Memory allocation failed" << std::endl;
		return 1;	
	}

	for (int i = 0; i < N; i++){
		horde[i].announce();
	}
	delete [] horde;
}