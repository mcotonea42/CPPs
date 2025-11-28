/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcotonea <mcotonea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 11:00:44 by mcotonea          #+#    #+#             */
/*   Updated: 2025/07/24 09:54:32 by mcotonea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.cpp"

// int main(){
// 	Span s(5);

// 	for (int i = 0; i < 5; ++i)
// 		s.addNumber(i);
// 	for (int i = 0; i < 5; ++i)
// 		std::cout << s.getValue(i) << std::endl;
// 	try{
// 		std::cout << s.longestSpan() << std::endl;
// 		std::cout << s.shortestSpan() << std::endl;
// 	}
// 	catch (std::exception& e){
// 		std::cout << e.what() << std::endl;
// 	}
// }

int main(){
	{
		std::cout << GREEN "---------- SubjectTest ----------" RESET << std::endl;
		Span sp = Span(5);
	
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);

		std::cout << sp << std::endl;
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	{
		std::cout << GREEN "-----------Testing the addNumbers function----------" RESET << std::endl;
		try{
			Span sp(10);
			
			std::vector<int> vec;
			vec.push_back(5);
			vec.push_back(10);
			vec.push_back(15);
			vec.push_back(20);


			sp.addNumbers(vec.begin(), vec.end());
			sp.addNumber(1);
			sp.addNumber(3);

			std::cout << sp << std::endl;
			std::cout << sp.shortestSpan() << std::endl;
			std::cout << sp.longestSpan() << std::endl;
		}
		catch (std::exception& e){
			std::cout << e.what() << std::endl;
		}
	}
	{
		std::cout << GREEN "----------Test for adding elements to a full container----------" RESET << std::endl;
		Span sp(3);

		sp.addNumber(1);
		sp.addNumber(2);

		std::cout << sp << std::endl;
		try {
			sp.addNumber(3);
			std::cout << sp << std::endl;
			sp.addNumber(4);
		}
		catch (std::exception& e){
			std::cout << e.what() << std::endl;
		}
	}
	{
		std::cout << GREEN "----------Test a container too small----------" RESET << std::endl;
		Span sp(1);

		sp.addNumber(100);
		
		std::cout << sp << std::endl;
		try {
			std::cout << sp.longestSpan() << std::endl;
		}
		catch (std::exception& e){
			std::cout << e.what() << std::endl;
		}
	}
	return 0;
}