/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcotonea <mcotonea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 16:32:32 by mcotonea          #+#    #+#             */
/*   Updated: 2025/06/19 10:00:27 by mcotonea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(){
	Zombie *heap = new Zombie("Melvin");
	heap->announce();
	delete heap;

	randomChump("Marc");
	randomChump("Corrector");
	
	Zombie *corrector = new Zombie("Corrector");
	corrector->announce();
	delete corrector;
}