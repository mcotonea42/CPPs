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

#ifndef FIXED_HPP
#define FIXED_HPP

class Fixed{
private:

	int	_value;
	static const int _bits = 8;

public:

	Fixed(void);
	Fixed(const Fixed& other);
	Fixed& operator=(const Fixed& other);
	~Fixed(void);
	
	int getRawBits(void) const;
	void setRawBits(int const raw);

};

#endif