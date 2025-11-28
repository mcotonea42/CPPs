/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcotonea <mcotonea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 23:12:53 by melvin            #+#    #+#             */
/*   Updated: 2025/07/24 09:46:59 by mcotonea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <exception>
#include <algorithm>

#define GREEN "\033[32m"
#define RESET "\033[0m"

class ValueNotFound: public std::exception{
	public:
		virtual const char* what() const throw(){
			return "Value not found in the container.";
		}
};

/* 
	Dans un template, quand on utilise un type defini a l'interieur d'un
	type parametre (T::iterator), on doit ecrire typename devant pour dire au compilateur
	que c'est un type et pas une variable ou une fonction.
*/
template <typename T>
typename T::iterator easyfind(T& container, int value){
	typename T::iterator it = std::find(container.begin(), container.end(), value);
	if (it == container.end())
		throw ValueNotFound();
	return it;
}
