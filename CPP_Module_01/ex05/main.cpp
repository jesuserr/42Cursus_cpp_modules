/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesuserr <jesuserr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 12:15:57 by jesuserr          #+#    #+#             */
/*   Updated: 2023/10/16 12:33:57 by jesuserr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <stdlib.h>		//for system("clear") in Linux

int	main(void)
{
	std::system("clear");
	Harl	complainer;
		
	//complainer.complain("ALL_OK");
 	complainer.complain("DEBUG");
	complainer.complain("INFO");
	complainer.complain("WARNING");
	complainer.complain("ERROR");
	return (0);
}
