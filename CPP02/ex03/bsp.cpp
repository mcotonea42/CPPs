/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcotonea <mcotonea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 16:43:02 by mcotonea          #+#    #+#             */
/*   Updated: 2025/06/20 11:48:16 by mcotonea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

static float area(const Point a, const Point b, const Point c){
	float area;

	area = (a.getX().toFloat() * (b.getY().toFloat() - c.getY().toFloat()) +
			b.getX().toFloat() * (c.getY().toFloat() - a.getY().toFloat()) +
			c.getX().toFloat() * (a.getY().toFloat() - b.getY().toFloat())) / 2;

	if (area < 0)
		area = area * -1;
	return area;
}

bool bsp(Point const a, Point const b, Point const c, Point const point){
	float Totalarea = area(a, b, c);
	float area1 = area(point, a, b);
	float area2 = area(point, b, c);
	float area3 = area(point, a, c);

	if (area1 == 0 || area2 == 0 || area3 == 0)
		return false;
	if ((area1 + area2 + area3) == Totalarea)
		return true;
	return false;
}