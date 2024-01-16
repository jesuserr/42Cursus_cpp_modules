/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesuserr <jesuserr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 19:43:00 by jesuserr          #+#    #+#             */
/*   Updated: 2023/10/16 11:31:03 by jesuserr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>		//for system("clear") in Linux
#include <iostream>

int	main(void)
{
	std::string		string_variable;
	std::string*	string_PTR;
	std::string&	string_REF = string_variable;

	std::system("clear");
	string_variable = "HI THIS IS BRAIN";
	string_PTR = &string_variable;
	std::cout << "memory address of the string variable: ";
	std::cout << &string_variable << std::endl;
	std::cout << "memory address held by stringPTR:      ";
	std::cout << string_PTR << std::endl;
	std::cout << "memory address held by stringREF:      ";
	std::cout << &string_REF << std::endl << std::endl;
	std::cout << "value of the string variable:          ";
	std::cout << string_variable << std::endl;
	std::cout << "value pointed to by stringPTR:         ";
	std::cout << *string_PTR << std::endl;
	std::cout << "value pointed to by stringREF:         ";
	std::cout << string_REF << std::endl;
	return (0);
}
