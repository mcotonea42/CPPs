/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melvin <melvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 19:42:52 by mcotonea          #+#    #+#             */
/*   Updated: 2025/07/18 00:31:09 by melvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main(int argc, char **argv){
	if (argc != 2){
		std::cout << "Use ./convert <input>" << std::endl;
		return 1;
	};
	ScalarConverter::convert(argv[1]);
	return 0;
}