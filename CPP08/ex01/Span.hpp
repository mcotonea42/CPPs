/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcotonea <mcotonea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 11:05:52 by mcotonea          #+#    #+#             */
/*   Updated: 2025/07/24 09:51:35 by mcotonea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <exception>
#include <algorithm>
#include <vector>
#include <limits>
#include <ostream>

#define GREEN "\033[32m"
#define RESET "\033[0m"

class Span{
	private:
		
		unsigned int _N;
		std::vector<int> _v;

	public:

		Span();
		Span(unsigned int N);
		Span(const Span& other);
		Span& operator=(const Span& other);
		~Span();

		void addNumber(int n);
		int shortestSpan();
		int longestSpan();

		const std::vector<int>& getVector() const;

		std::vector<int>::iterator begin() {return _v.begin();};
		std::vector<int>::iterator end() {return _v.end();};

	
		void addNumbers(std::vector<int>::iterator begin, std::vector<int>::iterator end);
		
		class FullContainer: public std::exception{
			public:
				virtual const char* what() const throw(){
					return "The container is already full.";
				}
		};

		class NotEnoughElement: public std::exception{
			public:
				virtual const char* what() const throw(){
					return "Not enough element in the container.";
				}
		};
};

std::ostream& operator<<(std::ostream& os, const Span& sp);