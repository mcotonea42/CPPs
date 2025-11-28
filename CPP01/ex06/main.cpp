/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcotonea <mcotonea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 13:53:08 by mcotonea          #+#    #+#             */
/*   Updated: 2025/06/18 14:18:08 by mcotonea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
int main(int argc, char **argv){

	if (argc != 2){
		std::cout << "Usage: ./harlFilter <Level>" << std::endl;
		return 1;
	}

	Harl harl;

	std::string level = argv[1];
	harl.complain(level);
}