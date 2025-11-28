/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcotonea <mcotonea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 09:28:16 by mcotonea          #+#    #+#             */
/*   Updated: 2025/06/19 10:20:00 by mcotonea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

// void incrementPointer(int* ptr){
// 	(*ptr)++;
// }

// void incrementReference(int& ref){
// 	ref++;
// }

int main(){
	{
		std::string str = "HI THIS IS BRAIN";
	
		std::string* stringPTR = NULL;
		std::string& stringREF = str;
		stringPTR = &str;
	
		std::cout << "The memory address of the string variable: " << &str << std::endl;
		std::cout << "The memory address held by stringPTR: " << stringPTR << std::endl;
		std::cout << "The memory address held by stringREF: " << &stringREF << std::endl;
	
		std::cout << "The value of the string variable: " << str << std::endl;
		std::cout << "The value pointed to by stringPTR: " << *stringPTR << std::endl;
		std::cout << "The value pointed to by stringREF: " << stringREF << std::endl;
	}
	// {
	// 	int a = 10;
	// 	int b = 10;

	// 	incrementPointer(&a);
	// 	incrementReference(b);

	// 	std::cout << "a = " << a << std::endl;
	// 	std::cout << "b = " << b << std::endl;
	// }
}