/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesuserr <jesuserr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 22:05:37 by jesuserr          #+#    #+#             */
/*   Updated: 2023/10/09 15:06:47 by jesuserr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iomanip>

void	print_phonebook(PhoneBook *phonebook)
{
	int	    i;
    int     size;
	Contact	contact;
		
	i = 0;
    size = phonebook->get_phonebook_size();
    if (size > 8)
	{
        size = 8;
	}
	std::cout << "|     Index|First Name| Last Name|  Nickname|" << std::endl;
    while (i < size)
	{
		contact = phonebook->get_contact(i);
		std::cout << "|" << std::right << std::setw(10) << ++i << "|" \
		<< std::setw(10) << truncate_string(contact.get_first_name()) << "|" \
		<< std::setw(10) << truncate_string(contact.get_last_name()) <<	"|" \
		<< std::setw(10) << truncate_string(contact.get_nickname()) << "|" \
		<< std::endl;
	}
}

std::string	truncate_string(std::string str)
{
	if (str.length() > 10)
	{
		str.erase(9, str.length() - 9);
		str.append(1, '.');
	}
	return(str);
}

void	print_contact(Contact *contact)
{
	std::cout << "First Name: " << contact->get_first_name() << std::endl;
	std::cout << "Last Name: " << contact->get_last_name() << std::endl;
	std::cout << "Nickname: " << contact->get_nickname() << std::endl;
	std::cout << "Phone Number: " << contact->get_phone_number() << std::endl;
	std::cout << "Darkest Secret: " << contact->get_dark_secret() << std::endl;	
}
