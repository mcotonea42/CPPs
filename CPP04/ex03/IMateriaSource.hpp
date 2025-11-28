/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMateriaSource.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcotonea <mcotonea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 12:03:37 by mcotonea          #+#    #+#             */
/*   Updated: 2025/07/02 12:05:11 by mcotonea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AMateria.hpp"

class AMateria;

class IMateriaSource{
	public:
	
		virtual ~IMateriaSource() {};
		virtual void learnMateria(AMateria *) = 0;
		virtual AMateria* createMateria(std::string const & type) = 0;		
};