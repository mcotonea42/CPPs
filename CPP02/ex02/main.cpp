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

#include "Fixed.hpp"
#include <iostream>
#include <iomanip>

int main() {
    {
        Fixed a;
        Fixed const b(Fixed(5.05f) * Fixed(2));

        std::cout << a << std::endl;
        std::cout << ++a << std::endl;
        std::cout << a << std::endl;
        std::cout << a++ << std::endl;
        std::cout << a << std::endl;

        std::cout << b << std::endl;
        
        std::cout << Fixed::max(a, b) << std::endl;
    }
    {
        Fixed a;                    // Default constructor
        Fixed b(10);                // Int constructor
        Fixed c(42.42f);            // Float constructor
        Fixed d(b);                 // Copy constructor
        Fixed e; 
        e = c;                      // Copy assignment

        std::cout << "a (default)        = " << a << std::endl;
        std::cout << "b (int 10)         = " << b << std::endl;
        std::cout << "c (float 42.42f)   = " << c << std::endl;
        std::cout << "d (copy of b)      = " << d << std::endl;
        std::cout << "e (assigned c)     = " << e << std::endl;

        std::cout << "\nArithmetic tests:" << std::endl;
        Fixed f = b + c;
        Fixed g = c - b;
        Fixed h = b * c;
        Fixed i = c / b;
        std::cout << "b + c = " << f << std::endl;
        std::cout << "c - b = " << g << std::endl;
        std::cout << "b * c = " << h << std::endl;
        std::cout << "c / b = " << i << std::endl;

        std::cout << "\nComparison tests:" << std::endl;
        std::cout << "b > c: " << (b > c) << std::endl;
        std::cout << "b < c: " << (b < c) << std::endl;
        std::cout << "b >= d: " << (b >= d) << std::endl;
        std::cout << "c <= e: " << (c <= e) << std::endl;
        std::cout << "c == e: " << (c == e) << std::endl;
        std::cout << "c != b: " << (c != b) << std::endl;

        std::cout << "\nIncrement/Decrement tests:" << std::endl;
        Fixed j;
        std::cout << "j = " << j << std::endl;
        std::cout << "++j = " << ++j << std::endl;
        std::cout << "j++ = " << j++ << std::endl;
        std::cout << "j = " << j << std::endl;
        std::cout << "--j = " << --j << std::endl;
        std::cout << "j-- = " << j-- << std::endl;
        std::cout << "j = " << j << std::endl;

        std::cout << "\nMin/Max tests:" << std::endl;
        std::cout << "min(b, c) = " << Fixed::min(b, c) << std::endl;
        std::cout << "max(b, c) = " << Fixed::max(b, c) << std::endl;
    }

    return 0;
}
