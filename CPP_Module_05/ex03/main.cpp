/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesuserr <jesuserr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 22:32:18 by jesuserr          #+#    #+#             */
/*   Updated: 2023/12/16 21:51:34 by jesuserr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

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
		Intern	someRandomIntern;
		AForm*	scf;
		
		scf = someRandomIntern.makeForm("shrubbery creation", "House");
		std::cout << *scf << std::endl;
		Pedro.signForm(*scf);
		Pedro.executeForm(*scf);
		std::cout << *scf << std::endl;
		delete scf;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	
	std::cout << std::endl << "TEST 2" << std::endl;
	try
	{
		Intern	someRandomIntern;
		AForm*	rrf;
		
		rrf = someRandomIntern.makeForm("robotomy request", "Bender");
		std::cout << *rrf << std::endl;
		Pedro.signForm(*rrf);
		Pedro.executeForm(*rrf);
		std::cout << *rrf << std::endl;
		delete rrf;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	
	std::cout << std::endl << "TEST 3" << std::endl;
	try
	{
		Intern	someRandomIntern;
		AForm*	ppf;
		
		ppf = someRandomIntern.makeForm("presidential pardon", "Carles");
		std::cout << *ppf << std::endl;
		Pedro.signForm(*ppf);
		Pedro.executeForm(*ppf);
		std::cout << *ppf << std::endl;
		delete ppf;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	
	std::cout << std::endl << "TEST 4" << std::endl;
	try
	{
		Intern	someRandomIntern;
		AForm*	nef;
		
		nef = someRandomIntern.makeForm("nonexisting", "ghost");
		std::cout << *nef << std::endl;
		Pedro.signForm(*nef);
		Pedro.executeForm(*nef);
		std::cout << *nef << std::endl;
		delete nef;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
		
	std::cout << std::endl;
	
	return (0);
}
