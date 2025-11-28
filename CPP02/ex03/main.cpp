/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcotonea <mcotonea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 16:43:02 by mcotonea          #+#    #+#             */
/*   Updated: 2025/06/20 11:48:16 by mcotonea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

bool bsp(Point const a, Point const b, Point const c, Point const point);

int main() {
    {
        Point a(0, 0);
        Point b(5, 0);
        Point c(0, 5);
        Point point (2, 3);
        if (bsp(a, b, c, point))
            std::cout << "The point is inside the triangle" << std::endl;
        else
            std::cout << "The point is outside the triangle" << std::endl;
    }
    {
        Point a;
        Point b(6,3);
        Point c(-1,8);
        Point point(1.48, 2.0);
        if (bsp(a, b, c, point))
            std::cout << "The point is inside the triangle" << std::endl;
        else
            std::cout << "The point is outside the triangle" << std::endl;
    }
    return 0;
}

