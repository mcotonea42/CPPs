/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melvin <melvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 12:11:05 by melvin            #+#    #+#             */
/*   Updated: 2025/07/11 16:24:08 by melvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(){
	try{
		Bureaucrat high("Bob", 1);
		Bureaucrat low("Marc", 75);
		Form a("a", 150, 150);
		Form b("b", 1, 1);

		std::cout << std::endl;
		std::cout << "--------------------" << std::endl;
		std::cout << std::endl;

		std::cout << high;
		std::cout << low;
		std::cout << a;
		std::cout << b;
		
		std::cout << std::endl;
		std::cout << "--------------------" << std::endl;
		std::cout << std::endl;
		
		high.signForm(a);
		low.signForm(a);
		low.signForm(b);
		high.signForm(b);
		
		std::cout << std::endl;
	}
	catch (std::exception& e){
		std::cout << "Exception catched: " << e.what() << std::endl;
	}
		

	return 0;
}