/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesuserr <jesuserr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 09:52:44 by jesuserr          #+#    #+#             */
/*   Updated: 2024/01/11 00:07:17 by jesuserr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>
#include "RPN.hpp"

int main(int argc, char** argv)
{
	//system("clear");
	if (argc == 2)
	{
		try
		{
			RPN expression;
			expression.calculate(argv[1]);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
			return (EXIT_FAILURE);
		}		
		return (EXIT_SUCCESS);
	}
	std::cerr << "Error: wrong number of arguments." << '\n';
	return (EXIT_FAILURE);
}
