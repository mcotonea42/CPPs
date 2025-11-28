/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcotonea <mcotonea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 15:21:17 by mcotonea          #+#    #+#             */
/*   Updated: 2025/06/19 17:13:36 by mcotonea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cmath>

#ifndef FIXED_HPP
#define FIXED_HPP

class Fixed{
private:

	int	_value;
	static const int _bits = 8;

public:

	Fixed(void);
	Fixed(const int nb);
	Fixed(const float nb);
	Fixed(const Fixed& other);
	Fixed& operator=(const Fixed& other);
	~Fixed(void);

	bool operator>(const Fixed& fixed) const;
	bool operator<(const Fixed& fixed) const;
	bool operator>=(const Fixed& fixed) const;
	bool operator<=(const Fixed& fixed) const;
	bool operator==(const Fixed& fixed) const;
	bool operator!=(const Fixed& fixed) const;

	Fixed operator+(const Fixed& fixed) const;
	Fixed operator-(const Fixed& fixed) const;
	Fixed operator*(const Fixed& fixed) const;
	Fixed operator/(const Fixed& fixed) const;

	Fixed& operator++();
	Fixed operator++(int);

	Fixed& operator--();
	Fixed operator--(int);

	static Fixed min(Fixed& a, Fixed& b);
	static Fixed min(const Fixed& a, const Fixed& b);
	static Fixed max(Fixed& a, Fixed& b);
	static Fixed max(const Fixed& a, const Fixed& b);

	int getRawBits(void) const;
	void setRawBits(int const raw);
	float toFloat(void) const;
	int toInt(void) const;

};

std::ostream& operator<<(std::ostream& os, const Fixed& f);

#endif