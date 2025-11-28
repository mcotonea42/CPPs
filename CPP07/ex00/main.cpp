/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melvin <melvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 20:23:28 by melvin            #+#    #+#             */
/*   Updated: 2025/07/19 22:25:28 by melvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "whatever.hpp"
#include <iostream>

/*
	You can specify the type of template
		::function<type> but this is not mandatory.
*/

int main(){
	int a = 2;
	int b = 3;

	::swap<int>(a, b);
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min(a, b) = " << ::min<int>(a, b) << std::endl;
	std::cout << "max(a, b) = " << ::max<int>(a, b) << std::endl;

	std::string c = "chaine1";
	std::string d = "chaine2";

	::swap<std::string>(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min(c, d) = " << ::min<std::string>(c, d) << std::endl;
	std::cout << "max(c, d) = " << ::max<std::string>(c, d) << std::endl;

	return 0;
}