/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcotonea <mcotonea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 11:20:56 by mcotonea          #+#    #+#             */
/*   Updated: 2025/07/23 14:51:45 by mcotonea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(): _N(0){}

Span::Span(unsigned int N): _N(N){}

Span::Span(const Span& other){
	*this = other;
}

Span& Span::operator=(const Span& other){
	if (this != &other){
		_N = other._N;
		_v = other._v;
	}
	return *this;
}

Span::~Span(){}

void Span::addNumber(int n){
	if (_v.size() == _N)
		throw FullContainer();
	_v.push_back(n);
}

int Span::longestSpan(){
	if (_v.size() < 2)
		throw NotEnoughElement();
	std::vector<int> copy = _v;
	std::sort(copy.begin(), copy.end());
	return copy.back() - copy.front();
}

int Span::shortestSpan(){
	if (_v.size() < 2)
		throw NotEnoughElement();
	std::vector<int> copy = _v;
	std::sort(copy.begin(), copy.end());
	int min = std::numeric_limits<int>::max();
	for (size_t i = 0; i < copy.size() - 1; ++i){
		int compare = copy[i + 1] - copy[i];
		if (compare < min)
			min = compare;
	}
	return min;
}

void Span::addNumbers(std::vector<int>::iterator begin, std::vector<int>::iterator end){
	size_t distance = std::distance(begin, end);
	if (_v.size() + distance > _N)
		throw FullContainer();
	_v.insert(_v.end(), begin, end);
}

const std::vector<int>& Span::getVector() const{
	return _v;
}

std::ostream& operator<<(std::ostream& os, const Span& sp){
	const std::vector<int>& vec = sp.getVector();
	os << "[ " ;
	for (size_t i = 0; i < vec.size(); ++i){
		os << vec[i];
		if (i != vec.size() - 1)
			os << ", ";
	}
	os << " ]";
	return os;
}