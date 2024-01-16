/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesuserr <jesuserr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 20:23:23 by jesuserr          #+#    #+#             */
/*   Updated: 2023/10/06 21:59:40 by jesuserr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact(void)
{
	//std::cout << "Constructor Contact called" << std::endl;
	return;
}

Contact::~Contact(void)
{
	//std::cout << "Destructor Contact called" << std::endl;
	return;
}

int	Contact::set_first_name(std::string first_name)
{
	if (first_name.length() != 0)
	{
		this->_first_name = first_name;
		return (0);
	}
	std::cout << "Please enter a valid first name: ";
	return (1);
}

int	Contact::set_last_name(std::string last_name)
{
	if (last_name.length() != 0)
	{
		this->_last_name = last_name;
		return (0);
	}
	std::cout << "Please enter a valid last name: ";
	return (1);
}

int	Contact::set_nickname(std::string nickname)
{
	if (nickname.length() != 0)
	{
		this->_nickname = nickname;
		return (0);
	}
	std::cout << "Please enter a valid nickname: ";
	return (1);	
}

int	Contact::set_phone_number(std::string phone_number)
{
	if (phone_number.length() != 0)
	{
		this->_phone_number = phone_number;
		return (0);
	}
	std::cout << "Please enter a valid phone number: ";
	return (1);	
}

int	Contact::set_dark_secret(std::string dark_secret)
{
	if (dark_secret.length() != 0)
	{
		this->_dark_secret = dark_secret;
		return (0);
	}
	std::cout << "Please enter a valid dark secret: ";
	return (1);	
}

std::string	Contact::get_first_name(void) const
{
	return (this->_first_name);
}

std::string	Contact::get_last_name(void) const
{
	return (this->_last_name);
}

std::string	Contact::get_nickname(void) const
{
	return (this->_nickname);
}
		
std::string	Contact::get_phone_number(void) const
{
	return (this->_phone_number);
}

std::string	Contact::get_dark_secret(void) const
{
	return (this->_dark_secret);
}
