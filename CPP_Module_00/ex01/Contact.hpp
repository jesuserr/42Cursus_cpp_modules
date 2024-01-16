/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesuserr <jesuserr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 12:34:40 by jesuserr          #+#    #+#             */
/*   Updated: 2023/10/09 15:06:06 by jesuserr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_H
# define CONTACT_H

#include <string>
#include <iostream>

class Contact
{
	private:
		std::string _first_name;
		std::string _last_name;
		std::string _nickname;
		std::string _phone_number;
		std::string _dark_secret;
	public:
		Contact();
		~Contact();
		int			set_first_name(std::string first_name);
		int			set_last_name(std::string last_name);
		int			set_nickname(std::string nickname);
		int			set_phone_number(std::string phone_number);
		int			set_dark_secret(std::string dark_secret);
		std::string	get_first_name(void) const;
		std::string	get_last_name(void) const;
		std::string	get_nickname(void) const;
		std::string	get_phone_number(void) const;
		std::string	get_dark_secret(void) const;
};

#endif
