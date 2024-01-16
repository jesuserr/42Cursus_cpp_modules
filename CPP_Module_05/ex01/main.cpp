/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesuserr <jesuserr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 22:32:18 by jesuserr          #+#    #+#             */
/*   Updated: 2023/12/18 21:46:50 by jesuserr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main(void)
{
	Form		form1("ID_CARD", 150, 150);
	Form		form2("PASSPORT", 1, 1);
	
 	std::cout << std::endl << "TEST 0" << std::endl;
	std::cout << form1 << std::endl;
	std::cout << form2 << std::endl;
				
	std::cout << std::endl << "TEST 1" << std::endl;
	try
	{
		Form	form3("LICENSE", 151, 151);
		std::cout << form3 << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	
	std::cout << std::endl << "TEST 2" << std::endl;
	try
	{
		Form	form3("LICENSE", 0, 0);
		std::cout << form3 << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	
	std::cout << std::endl << "TEST 3" << std::endl;
	try
	{
		std::cout << form2 << std::endl;
		Bureaucrat	Paco("Paco", 2);
		Paco.signForm(form2);
		std::cout << form2 << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	
	std::cout << std::endl;
	std::cout << form1 << std::endl;
	std::cout << form2 << std::endl;
	std::cout << std::endl;
	
	return (0);
}
