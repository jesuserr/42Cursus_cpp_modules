/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesuserr <jesuserr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 22:32:18 by jesuserr          #+#    #+#             */
/*   Updated: 2023/12/18 20:38:52 by jesuserr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main(void)
{
	Bureaucrat	Jose("Jose", 150);
	Bureaucrat	Paco("Paco", 1);
	Bureaucrat	Default;
			
	std::cout << std::endl << "TEST 0" << std::endl;
	std::cout << Jose << std::endl;
	std::cout << Paco << std::endl;
	std::cout << Default << std::endl;
			
	std::cout << std::endl << "TEST 1" << std::endl;
	try
	{
		Bureaucrat	Pepe("Pepe", 151);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	
	std::cout << std::endl << "TEST 2" << std::endl;
	try
	{
		Bureaucrat	Pepe("Pepe", 0);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	
	std::cout << std::endl << "TEST 3" << std::endl;
	try
	{
		Jose.decrementGrade();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	
	std::cout << std::endl << "TEST 4" << std::endl;
	try
	{
		Paco.incrementGrade();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	
	std::cout << std::endl << "TEST 5" << std::endl;
	try
	{
		Bureaucrat	Pepe(Jose);
		std::cout << Pepe << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	
	std::cout << std::endl << "TEST 6" << std::endl;
	try
	{
		Bureaucrat	Pepe = Paco;
		std::cout << Pepe << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	
	std::cout << std::endl << "TEST 7" << std::endl;
	try
	{
		Jose.incrementGrade();
		Jose.incrementGrade();
		Jose.incrementGrade();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl << "TEST 8" << std::endl;
	try
	{
		Paco.decrementGrade();
		Paco.decrementGrade();
		Paco.decrementGrade();
		Paco.incrementGrade();
		Paco.incrementGrade();
		Paco.incrementGrade();
		Paco.incrementGrade();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl;
	std::cout << Jose << std::endl;
	std::cout << Paco << std::endl;
	std::cout << Default << std::endl;
	std::cout << std::endl;
	
	return (0);
}
