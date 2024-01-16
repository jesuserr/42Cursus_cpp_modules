/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesuserr <jesuserr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 21:26:12 by jesuserr          #+#    #+#             */
/*   Updated: 2024/01/11 00:05:50 by jesuserr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>
#include "BitcoinExchange.hpp"

int main(int argc, char** argv)
{
	//system("clear");
	if (argc == 2)
	{
		try
		{
			BitcoinExchange exchange;
			exchange.convert(argv[1]);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
			return (EXIT_FAILURE);
		}		
		return (EXIT_SUCCESS);
	}
	else if (argc == 1)
		std::cerr << "Error: no file provided." << '\n';
	else if (argc > 2)
		std::cerr << "Error: too many arguments." << '\n';
	return (EXIT_FAILURE);
}
