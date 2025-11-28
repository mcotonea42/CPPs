/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcotonea <mcotonea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 16:43:02 by mcotonea          #+#    #+#             */
/*   Updated: 2025/06/20 11:48:16 by mcotonea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

#ifndef POINT_HPP
#define POINT_HPP

class Point{
private:

	const Fixed _x;
	const Fixed _y;

public:

	Point();
	Point(const float x, const float y);
	Point(const Point& other);
	Point& operator=(const Point& other);
	~Point();


	const Fixed& getX(void) const;
	const Fixed& getY(void) const;
};

#endif