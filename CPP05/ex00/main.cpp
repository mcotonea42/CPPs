/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melvin <melvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 12:11:05 by melvin            #+#    #+#             */
/*   Updated: 2025/07/12 14:49:56 by melvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main(){
	Bureaucrat marc("Marc", 1);
	std::cout << marc;
	
	try{
		marc.promoteBureaucrate();
	}
	catch (std::exception& e){
		std::cout << "Exception catched: " << e.what() << std::endl;
	}
	try{
		marc.demoteBureaucrate();
		std::cout << marc;
	}
	catch (std::exception& e){
		std::cout << "Exception catched: " << e.what() << std::endl;
	}

	

	return 0;
}