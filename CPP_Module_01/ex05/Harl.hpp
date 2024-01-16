/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesuserr <jesuserr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 12:09:56 by jesuserr          #+#    #+#             */
/*   Updated: 2023/10/16 12:45:50 by jesuserr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_H
# define HARL_H

#include <iostream>

#define DEFAULT "\001\033[0;39m\002"
#define RED 	"\001\033[1;91m\002"
#define YELLOW 	"\001\033[1;93m\002"
#define BLUE	"\001\033[1;94m\002"
#define GREEN 	"\001\033[1;92m\002"

class Harl
{
	private:
		void	_debug(void);
		void	_info(void);
		void	_warning(void);
		void	_error(void);
	public:
		Harl(void);
		~Harl(void);
		void	complain(std::string level);
};

#endif
