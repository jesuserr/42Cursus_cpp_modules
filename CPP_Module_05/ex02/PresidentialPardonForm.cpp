/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesuserr <jesuserr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 13:40:48 by jesuserr          #+#    #+#             */
/*   Updated: 2023/12/15 21:36:06 by jesuserr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

/*********************** ORTHODOX CANONICAL CLASS FORM ************************/

PresidentialPardonForm::PresidentialPardonForm(void) : \
AForm ("PresidentialPardonForm", 25, 5, "Default")
{
	std::cout << "Unsigned Presidential Pardon Form created." << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string const target) : \
AForm ("PresidentialPardonForm", 25, 5, target)
{
	std::cout << "Unsigned Presidential Pardon Form for " << target;
	std::cout << " created." << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const & source) : \
AForm (source)
{
	std::cout << "Presidential Pardon Form cloned." << std::endl;
}

PresidentialPardonForm & PresidentialPardonForm::operator=(PresidentialPardonForm const & source)
{
	if (this != &source)
	{
		std::cout << "Presidential Pardon Form signature updated." << std::endl;
		this->setSignature(source.getIsSigned());
	}	
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm(void)
{
	std::cout << this->getTarget() << " Presidential Pardon Form destroyed.";
	std::cout << std::endl;
}

/****************************** MEMBER FUNCTIONS ******************************/

void	PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	checkExecute(executor);
	std::cout << this->getTarget() << " has been pardoned by Zaphod Beeblebrox.";
	std::cout << std::endl;
}
