/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melvin <melvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 01:37:21 by melvin            #+#    #+#             */
/*   Updated: 2025/07/20 02:13:05 by melvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <exception>

template <typename T>

class Array{
	private:

		T* _data;
		unsigned int _size;
	
	public:
	
		Array();
		Array(unsigned int n);
		Array(const Array& other);
		Array& operator=(const Array& other);
		~Array();

		T& operator[](unsigned int index);
		const T& operator[](unsigned int index) const;

		class InvalidIndex: public std::exception{
			public:
				virtual const char* what() const throw(){
					return "Invalid index";
				}
		};
		
		unsigned int size() const;
};

#include "Array.tpp"