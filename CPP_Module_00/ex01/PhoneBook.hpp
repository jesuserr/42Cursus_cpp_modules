/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesuserr <jesuserr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 00:02:08 by jesuserr          #+#    #+#             */
/*   Updated: 2023/10/09 15:06:14 by jesuserr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_H
# define PHONEBOOK_H

#include "Contact.hpp"

class PhoneBook
{
	private:
		Contact _contacts[8];
		int		_size;
	public:
		PhoneBook();
		~PhoneBook();
		int		get_phonebook_size(void) const;
		void	add_contact(Contact *new_contact);
		Contact	get_contact(int position) const;
	
};

/* utils.cpp */
std::string	truncate_string(std::string str);
void		print_contact(Contact *contact);
void		print_phonebook(PhoneBook *phonebook);

#endif
