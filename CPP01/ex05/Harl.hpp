/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcotonea <mcotonea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 12:16:05 by mcotonea          #+#    #+#             */
/*   Updated: 2025/06/18 12:20:14 by mcotonea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#ifndef HARL_HPP
#define HARL_HPP

class Harl{
private:

	void debug(void);
	void info(void);
	void warning(void);
	void error(void);

public:

	Harl(void);
	~Harl(void);

	void complain(std::string level);
};

#endif
