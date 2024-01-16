/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesuserr <jesuserr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 20:26:16 by jesuserr          #+#    #+#             */
/*   Updated: 2023/10/09 15:07:07 by jesuserr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
//#include <stdlib.h>		//for system("clear") in Linux

int	search_contact(PhoneBook *phonebook)
{
	Contact		contact;
	std::string	alpha_index;
	int			index;

	print_phonebook(phonebook);
	std::cout << "Please enter phonebook position [1-8]: ";
	if (!std::getline(std::cin, alpha_index))
		return(1);
	if (!(alpha_index.length() == 1 && (alpha_index[0] >= '1' && alpha_index[0] <= '8')))
	{
		std::cout << "Invalid format, please try again" << std::endl;
		return(0);
	}
	index = alpha_index[0] - '0';
	if (index > phonebook->get_phonebook_size())
	{
		std::cout << "Empty contact, please try again" << std::endl;
		return(0);
	}
	contact = phonebook->get_contact(index - 1);
	print_contact(&contact);
	return(0);
}

int	add_new_contact(PhoneBook *phonebook)
{
	Contact		new_contact;
	std::string	input_data;
	int			index;
	
	index = (phonebook->get_phonebook_size() % 8) + 1;
	std::cout << "Phonebook position: " << index << std::endl;
	input_data = "";
	while (new_contact.set_first_name(input_data))
		if (!std::getline(std::cin, input_data))
			return (1);
	input_data = "";
	while (new_contact.set_last_name(input_data))
		if (!std::getline(std::cin, input_data))
			return (1);
	input_data = "";
	while (new_contact.set_nickname(input_data))
		if (!std::getline(std::cin, input_data))
			return (1);
	input_data = "";
	while (new_contact.set_phone_number(input_data))
		if (!std::getline(std::cin, input_data))
			return (1);
	input_data = "";
	while (new_contact.set_dark_secret(input_data))
		if (!std::getline(std::cin, input_data))
			return (1);	
	phonebook->add_contact(&new_contact);
	std::cout << new_contact.get_first_name() << \
	" added successfully in position " << index << std::endl;
	return (0);
}

int	main(void)
{
	std::string	option;
	PhoneBook	my_phonebook;
	
	system("clear");
	std::cout << "*** Welcome to the crappy awesome phonebook ***" << std::endl;	
	while (true)
	{
		std::cout << std::endl << "Please enter your choice (ADD / SEARCH / EXIT): ";
		if (!std::getline(std::cin, option) || option == "EXIT")
			break;
		else if (option == "ADD")
		{
			if (add_new_contact(&my_phonebook))
				break;
		}			
		else if (option == "SEARCH")
		{
			if (my_phonebook.get_phonebook_size() == 0)
				std::cout << "Empty phonebook" << std::endl;
			else
				if (search_contact(&my_phonebook))
					break;
		}
		else
			std::cout << "Wrong option, please try again" << std::endl;
	}
	if (option != "EXIT")
		std::cout << std::endl;
	std::cout << "Phonebook destroyed, Good Bye!" << std::endl;	
	return (0);
}
