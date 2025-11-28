/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcotonea <mcotonea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 16:27:04 by mcotonea          #+#    #+#             */
/*   Updated: 2025/06/16 16:28:58 by mcotonea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

class Zombie{
private:

	std::string _name;

public:

	Zombie(std::string name);
	~Zombie(void);

	void announce(void);
};

Zombie* newZombie(std::string name);
void randomChump(std::string name);

#endif