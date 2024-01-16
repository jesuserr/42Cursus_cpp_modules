/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesuserr <jesuserr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 22:32:18 by jesuserr          #+#    #+#             */
/*   Updated: 2023/12/18 21:49:00 by jesuserr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main(void)
{
	Bureaucrat	Pedro("Pedro", 1);
	Bureaucrat	Paco("Paco", 75);
	Bureaucrat	Pepe("Pepe", 150);
			
	std::cout << std::endl << "TEST 0" << std::endl;
	std::cout << Pedro << std::endl;
	std::cout << Paco << std::endl;
	std::cout << Pepe << std::endl;
	
	std::cout << std::endl << "TEST 1" << std::endl;
	try
	{
		PresidentialPardonForm	PPF("Carles");
		std::cout << PPF << std::endl;
		Pedro.signForm(PPF);
		Pedro.executeForm(PPF);
		std::cout << PPF << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	
	std::cout << std::endl << "TEST 2" << std::endl;
	try
	{
		RobotomyRequestForm RRF("HAL");
		std::cout << RRF << std::endl;
		Pedro.signForm(RRF);
		Pedro.executeForm(RRF);
		std::cout << RRF << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	
	std::cout << std::endl << "TEST 3" << std::endl;
	try
	{
		ShrubberyCreationForm SCF("House");
		std::cout << SCF << std::endl;
		Pedro.signForm(SCF);
		Pedro.executeForm(SCF);
		std::cout << SCF << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	
	std::cout << std::endl;
	
	return (0);
}
