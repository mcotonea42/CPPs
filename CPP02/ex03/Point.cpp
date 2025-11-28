/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcotonea <mcotonea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 16:43:02 by mcotonea          #+#    #+#             */
/*   Updated: 2025/06/24 15:37:27 by mcotonea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point(): _x(0), _y(0){}

Point::Point(const float x, const float y): _x(x), _y(y){}

Point::Point(const Point& other): _x(other._x), _y(other._y){}

Point& Point::operator=(const Point& other){
	if (this == &other)
		return *this;
	return *this;
}

Point::~Point(){}

const Fixed& Point::getX(void) const{
	return (this->_x);
}

const Fixed& Point::getY(void) const{
	return (this->_y);
}