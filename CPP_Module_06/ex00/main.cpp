/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesuserr <jesuserr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 11:11:04 by jesuserr          #+#    #+#             */
/*   Updated: 2023/12/24 00:27:40 by jesuserr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main(int argc, char **argv)
{
	if (argc == 2)
	{
		try
		{
			ScalarConverter::convert(argv[1]);
/* 			ScalarConverter::convert("c");
			ScalarConverter::convert("a");
			ScalarConverter::convert("0");
			ScalarConverter::convert("-42");
			ScalarConverter::convert("42");
			ScalarConverter::convert("0.0f");
			ScalarConverter::convert("-4.2f");
			ScalarConverter::convert("4.2f");
			ScalarConverter::convert("-inff");
			ScalarConverter::convert("+inff");
			ScalarConverter::convert("+nanf");
			ScalarConverter::convert("0.0");
			ScalarConverter::convert("-4.2");
			ScalarConverter::convert("4.2");
			ScalarConverter::convert("-inf");
			ScalarConverter::convert("+inff");
			ScalarConverter::convert("nan");
 			ScalarConverter::convert("2147483647");
			std::cout << std::endl;
			ScalarConverter::convert("2147483648");
			std::cout << std::endl;
			ScalarConverter::convert("-2147483648");
			std::cout << std::endl;
			ScalarConverter::convert("-2147483649");
			std::cout << std::endl;	*/		
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	else
		std::cerr << "Error - Invalid number of arguments." << std::endl;
	return (0);
}
