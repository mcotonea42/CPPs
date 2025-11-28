/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcotonea <mcotonea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 23:44:48 by melvin            #+#    #+#             */
/*   Updated: 2025/06/11 16:42:21 by mcotonea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

#ifndef PHONEBOOK_H
# define PHONEBOOK_H

class PhoneBook{
private:
	Contact contacts[8];
	int	_index;

public:

	PhoneBook(void);
	~PhoneBook(void);
	
	void addContact();
	void searchContact() const;
	std::string	adaptFormat(std::string str) const;
};

#endif