/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesuserr <jesuserr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 13:40:53 by jesuserr          #+#    #+#             */
/*   Updated: 2023/12/15 23:04:16 by jesuserr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

/*********************** ORTHODOX CANONICAL CLASS FORM ************************/

RobotomyRequestForm::RobotomyRequestForm(void) : \
AForm ("RobotomyRequestForm", 72, 45, "Default")
{
	std::cout << "Unsigned Robotomy Request Form created." << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string const target) : \
AForm ("RobotomyRequestForm", 72, 45, target)
{
	std::cout << "Unsigned Robotomy Request Form for " << target;
	std::cout << " created." << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const & source) : \
AForm (source)
{
	std::cout << "Robotomy Request Form cloned." << std::endl;
}

RobotomyRequestForm & RobotomyRequestForm::operator=(RobotomyRequestForm const & source)
{
	if (this != &source)
	{
		std::cout << "Robotomy Request Form signature updated." << std::endl;
		this->setSignature(source.getIsSigned());
	}	
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm(void)
{
	std::cout << this->getTarget() << " Robotomy Request Form destroyed.";
	std::cout << std::endl;
}

/****************************** MEMBER FUNCTIONS ******************************/

void	RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	checkExecute(executor);
	std::cout << "Strange drilling noises can be heard.... ";
	std::srand(std::time(0));
	if (std::rand() % 2 == 0)
		std::cout << this->getTarget() << " has been robotomized successfully.";
	else
		std::cout << "Robotomy on " << this->getTarget() << " failed, we are doomed.";
	std::cout << std::endl;
}
