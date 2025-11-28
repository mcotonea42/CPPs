/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melvin <melvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 20:29:40 by melvin            #+#    #+#             */
/*   Updated: 2025/07/19 22:28:24 by melvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

template <typename T>
void swap(T& a, T& b){
	T temp = a;
	a = b;
	b = temp;
}

template <typename T>
const T& min(const T& a, const T& b){
	if (a < b)
		return a;
	else
		return b;
}

template <typename T>
const T& max(const T& a, const T& b){
	if (a > b)
		return a;
	else 
		return b;
}