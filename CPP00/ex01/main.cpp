/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcotonea <mcotonea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 13:28:29 by mcotonea          #+#    #+#             */
/*   Updated: 2025/06/11 15:41:25 by mcotonea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include "PhoneBook.hpp"
#include <iostream>

int	main(int argc, char **argv)
{
	(void)argv;
	PhoneBook pb;
	std::string command;

	if (argc != 1) {
		std::cout << "Execute only ./phonebook" << std::endl;
		return 0;
	}
	while (true)
	{
		std::cout << "Enter command(ADD, SEARCH, EXIT): ";
		if (!std::getline(std::cin, command))
			break;
		if (command == "ADD")
			pb.addContact();
		else if (command == "SEARCH")
			pb.searchContact();
		else if (command == "EXIT")
			break;
		else
			std::cout << "Unknown command" << std::endl;
	}
	return 0;
}