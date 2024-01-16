/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesuserr <jesuserr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 10:42:54 by jesuserr          #+#    #+#             */
/*   Updated: 2023/10/09 15:06:36 by jesuserr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void)
{
	//std::cout << "Constructor PhoneBook called" << std::endl;
	this->_size = 0;
	return;
}

PhoneBook::~PhoneBook(void)
{
	//std::cout << "Destructor PhoneBook called" << std::endl;
	return;
}

int	PhoneBook::get_phonebook_size(void) const
{
	return (this->_size);
}

void	PhoneBook::add_contact(Contact *new_contact)
{
	_contacts[this->_size % 8] = *new_contact;
	this->_size++;
}

Contact	PhoneBook::get_contact(int position) const
{
	return (this->_contacts[position]);
}
