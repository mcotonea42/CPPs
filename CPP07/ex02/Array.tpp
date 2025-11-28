/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcotonea <mcotonea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 01:50:49 by melvin            #+#    #+#             */
/*   Updated: 2025/07/22 11:20:25 by mcotonea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Array.hpp"

/* 
	We write Array<T> because we ara defining methods of the Array
	class for a generic type T.
*/

template<typename T>
Array<T>::Array(): _data(NULL), _size(0){}

template<typename T>
Array<T>::Array(unsigned int n): _data(new T[n]), _size(n){}

/* 
	new T[n] calls default constructor of T like T obj;
	We create n instances of T in _data. We allocates memory for n objects T.
*/

template<typename T>
Array<T>::Array(const Array& other): _data(new T[other._size]), _size(other._size){
	for (unsigned int i = 0; i < _size; ++i)
		_data[i] = other._data[i];
}

template<typename T>
Array<T>& Array<T>::operator=(const Array& other){
	if (this != &other){
		delete[] _data;
		_size = other._size;
		_data = new T[_size];
		for (unsigned int i = 0; i < _size; ++i)
			_data[i] = other._data[i];
	}
	return *this;
}

template<typename T>
Array<T>::~Array(){
	delete [] _data;
}

/* 
	Index operator overload
*/
template<typename T>
T& Array<T>::operator[](unsigned int index){
	if (index >= _size)
		throw InvalidIndex();
	return _data[index];
}

template<typename T>
const T& Array<T>::operator[](unsigned int index) const{
	if (index >= _size)
		throw InvalidIndex();
	return _data[index];
}

template<typename T>
unsigned int Array<T>::size() const{
	return _size;
}