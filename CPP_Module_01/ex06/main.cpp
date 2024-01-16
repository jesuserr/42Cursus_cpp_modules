/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesuserr <jesuserr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 12:15:57 by jesuserr          #+#    #+#             */
/*   Updated: 2023/10/15 20:39:34 by jesuserr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <stdlib.h>		//for system("clear") in Linux

int	main(int argc, char **argv)
{
	Harl	complainer;
	
	std::system("clear");
	if (argc == 2)
		complainer.complain(argv[1]);
	else
		std::cout << "[ Probably complaining about insignificant problems ]";
	std::cout << std::endl;
	return (0);
}
