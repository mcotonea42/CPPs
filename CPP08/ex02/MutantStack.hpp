/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcotonea <mcotonea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 11:14:07 by mcotonea          #+#    #+#             */
/*   Updated: 2025/07/24 13:39:54 by mcotonea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <stack>

#define GREEN "\033[32m"
#define RESET "\033[0m"

/* 
	std::stack est un adaptateur de container qui encapsule un containair sous jacent: initialement, ce container sous-jacent est un std::deque<T>.
	std::stack utilise les methodes du container sous-jacent pour implementer ses propres fonctions.
	Toute fonction disponible sur le container sous-jacent est disponible a travers 'c'.
	Pour acceder au type du container encapsule par std::stack<T>, on peut faire std::stack<T>::container_type.
	On peut acceder aux iterateurs du container encapsule par std::stack en faisant:
		std::stack<T>::container_type::iterator // std::stack<T>::container_type::const_iterator 
	pour les redefinir et les implementer.
*/


template <typename T>
class MutantStack: public std::stack<T>{
	public:

		MutantStack();
		MutantStack(const MutantStack& other);
		MutantStack& operator=(const MutantStack& other);
		~MutantStack();

		typedef typename std::stack<T>::container_type::iterator iterator;
		typedef typename std::stack<T>::container_type::const_iterator const_iterator;

		iterator begin();
		iterator end();
		iterator rbegin();
		iterator rend();

		const_iterator begin() const;
		const_iterator end() const;
		const_iterator rbegin() const;
		const_iterator rend() const;

};
