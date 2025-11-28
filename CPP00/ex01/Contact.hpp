/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcotonea <mcotonea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 23:44:19 by melvin            #+#    #+#             */
/*   Updated: 2025/06/11 15:45:30 by mcotonea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

#ifndef CONTACT_H
# define CONTACT_H

class Contact {
private:

	std::string _firstName;
	std::string	_lastName;
	std::string _nickName;
	std::string _phoneNumber;
	std::string _darkestSecret;

public:

	Contact(void);
	~Contact(void);

	std::string	getFirstName(void) const;
	void	setFirstName(std::string s);

	std::string getLastName(void) const;
	void	setLastName(std::string s);
	
	std::string getNickName(void) const;
	void	setNickName(std::string s);

	std::string getPhoneNumber(void) const;
	void	setPhoneNumber(std::string s);
	
	std::string getDarkestSecret(void) const;
	void	setDarkestSecret(std::string s);

	void	fill_contact(void);
};

#endif