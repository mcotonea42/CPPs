/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcotonea <mcotonea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 11:17:41 by mcotonea          #+#    #+#             */
/*   Updated: 2025/07/24 12:57:07 by mcotonea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

template <typename T>
MutantStack<T>::MutantStack(): std::stack<T>(){}

template <typename T>
MutantStack<T>::MutantStack(const MutantStack& other): std::stack<T>(other){}

template <typename T>
MutantStack<T>& MutantStack<T>::operator=(const MutantStack& other){
	if (this != &other)
		std::stack<T>::operator=(other);
	return *this;
}

template <typename T>
MutantStack<T>::~MutantStack() {}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin(){
	return this->c.begin();
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::end(){
	return this->c.end();
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::rbegin(){
	return this->c.rbegin();
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::rend(){
	return this->c.rend();
}

template <typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::begin() const{
	return this->c.begin();
	
}

template <typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::end() const{
	return this->c.end();
}

template <typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::rbegin() const{
	return this->c.rbegin();
	
}

template <typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::rend() const{
	return this->c.rend();
}