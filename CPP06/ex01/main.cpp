/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melvin <melvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 19:49:20 by mcotonea          #+#    #+#             */
/*   Updated: 2025/07/18 01:04:03 by melvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main(){
	Data data;

	data.name = "Bob";
	data.age = 48;

	uintptr_t raw = Serializer::serialize(&data);
	Data* result = Serializer::deserialize(raw);

	std::cout << "Original data adress: " << &data << std::endl;
	std::cout << "Deserialized data adress: " << result << std::endl;
	std::cout << "Name: " << result->name << std::endl;
	std::cout << "Age: " << result->age << std::endl;

	return 0;	
}