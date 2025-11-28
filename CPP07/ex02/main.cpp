/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcotonea <mcotonea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 01:48:46 by melvin            #+#    #+#             */
/*   Updated: 2025/07/22 11:21:45 by mcotonea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

int main(){
	{
	Array<int> a(5);
	for (unsigned int i = 0; i < a.size(); ++i)
		a[i] = static_cast<int>(i) * 10;

	std::cout << "Array a: ";
	for (unsigned int i = 0; i < a.size(); ++i)
		std::cout << a[i] << " ";
	std::cout << std::endl;

	Array<int> b = a;
	b[0] = 999;

	std::cout << "Array b: ";
	for (unsigned int i = 0; i < b.size(); ++i)
		std::cout << b[i] << " ";
	std::cout << std::endl;

	try {
		std::cout << b[6] << std::endl;
	}
	catch (std::exception& e){
		std::cout << "Exception catched: " << e.what() << std::endl;
	}
	}
	{
		Array<std::string> s(3);
		s[0] = "Hello";
		s[1] = "Bonjour";
		s[2] = "Hola";

		for (unsigned int i = 0; i < s.size(); ++i)
			std::cout << s[i] << " " ;
		std::cout << std::endl;
	}
	return 0;
}