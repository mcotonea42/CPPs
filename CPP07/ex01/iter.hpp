/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melvin <melvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 21:53:30 by melvin            #+#    #+#             */
/*   Updated: 2025/07/19 22:19:58 by melvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <cstddef>

template <typename A, typename Func>
void iter(A* array, size_t len, Func function){
	if (array == NULL)
		return ;
	for (size_t i = 0; i < len; i++)
		function(array[i]);
};

/* 
	Using a template makes the iter function generic.
	Otherwise, we have to recreate a function for each type you want to pass as a parameter.
	This is the very principle of templates: to generate code that is adapted to the type, automatically.
*/

// template <typename A>
// void iter(A* array, size_t len, void (*function)(A&)){
// 	if (array == NULL)
// 		return ;
// 	for (size_t i = 0; i < len; i++)
// 		function(array[i]);
// };