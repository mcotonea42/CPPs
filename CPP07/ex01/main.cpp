/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melvin <melvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 21:52:51 by melvin            #+#    #+#             */
/*   Updated: 2025/07/19 22:15:17 by melvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "iter.hpp"


void ft_tolower(char& c){
	c = std::tolower(c);
}

void ft_toupper(char& c){
	c = std::toupper(c);
}

int increment(int& i){
	i++;
	return i;
}

template <typename P>
void printElement(const P& x){
	std::cout << x << " ";
}

void printChar(const char& c){
	std::cout << c << " ";
}

void printInt(const int i){
	std::cout << i << " ";
}

/* 
	Remove comments to test with type-pecific print function.
	If we make a print function taking a template as arguments,
	then we need to do is indicate the type we want to print.
*/

int main(){
	char a[] = {'A', 'B', 'C'};
	
	::iter(a, 3, ft_tolower);
	::iter(a, 3, printElement<char>);
	// ::iter(a, 3, printChar); 

	std::cout << std::endl;
	
	int i[] = {1, 2, 3};
	// ::iter(i, 3, printInt);
	::iter(i, 3, printElement<int>);
	std::cout << std::endl;	
	::iter(i, 3, increment);
	// ::iter(i, 3, printInt);
	::iter(i, 3, printElement<int>);
}