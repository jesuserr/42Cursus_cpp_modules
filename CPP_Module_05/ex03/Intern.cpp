/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesuserr <jesuserr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 13:32:34 by jesuserr          #+#    #+#             */
/*   Updated: 2023/12/17 17:42:00 by jesuserr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

/*********************** ORTHODOX CANONICAL CLASS FORM ************************/

Intern::Intern(void)
{
	std::cout << "Intern created." << std::endl;
}

Intern::Intern(Intern const & source)
{
	std::cout << "Intern cloned." << std::endl;
	*this = source;
}

Intern & Intern::operator=(Intern const & source)
{
	(void) source;
	return (*this);
}

Intern::~Intern(void)
{
	std::cout << "Intern destroyed." << std::endl;
}

/****************************** MEMBER FUNCTIONS ******************************/

/* AForm * Intern::makeForm(std::string const formName, std::string const target)
{
	std::string forms[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	int			i = 0;
	
	while (i < 3 && forms[i] != formName)
		i++;
	if (i < 3)
		std::cout << "Intern creates " << formName << " form." << std::endl;
	switch (i)
	{
		case 0:
			return (new ShrubberyCreationForm(target));
		case 1:
			return (new RobotomyRequestForm(target));			
		case 2:
			return (new PresidentialPardonForm(target));			
		default:
			throw Intern::FormNotCreatedException();			
	}
}
 */

AForm * Intern::makeForm(std::string const formName, std::string const target) const
{
	std::string forms[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	AForm * (Intern::*funcPtr[3])(std::string const target) const;
	int i = 0;
	
	funcPtr[0] = &Intern::createShrubberyCreationForm;
	funcPtr[1] = &Intern::createRobotomyRequestForm;
	funcPtr[2] = &Intern::createPresidentialPardonForm;
	
	while (i < 3 && forms[i] != formName)
		i++;
	if (i < 3)
	{
		std::cout << "Intern creates " << formName << " form." << std::endl;
		return (this->*funcPtr[i])(target);
	}
	throw Intern::FormNotCreatedException();
}

AForm * Intern::createShrubberyCreationForm(std::string const target) const
{
	return (new ShrubberyCreationForm(target));
}

AForm * Intern::createRobotomyRequestForm(std::string const target) const
{
	return (new RobotomyRequestForm(target));
}

AForm * Intern::createPresidentialPardonForm(std::string const target) const
{
	return (new PresidentialPardonForm(target));	
}

/****************************** NESTED CLASSES ********************************/

const char* Intern::FormNotCreatedException::what() const throw()
{
	return ("Intern was not able to create form.");
}
