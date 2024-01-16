/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesuserr <jesuserr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 22:33:34 by jesuserr          #+#    #+#             */
/*   Updated: 2023/12/18 19:25:58 by jesuserr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

/*********************** ORTHODOX CANONICAL CLASS FORM ************************/

Bureaucrat::Bureaucrat(void) : _name ("Default"), _grade(150)
{
	std::cout << "Default, bureaucrat grade 150 created." << std::endl;
}

Bureaucrat::Bureaucrat(std::string const name, int grade) : \
_name(name), _grade(grade)
{
	checkGrade();
	std::cout << this->_name << ", bureaucrat grade " << this->_grade;
	std::cout << " created." << std::endl;	
}

Bureaucrat::Bureaucrat(Bureaucrat const & source) : _name(source._name)
{
	std::cout << source._name << ", bureaucrat cloned." << std::endl;
	*this = source;
}

Bureaucrat & Bureaucrat::operator=(Bureaucrat const & source)
{
	if (this != &source)
	{
		std::cout << this->getName() << ", bureaucrat grade assigned.";
		std::cout << std::endl;
		this->_grade = source.getGrade();
		//checkGrade();
	}	
	return (*this);
}

Bureaucrat::~Bureaucrat(void)
{
	std::cout << this->_name << ", bureaucrat destroyed." << std::endl;
}

/****************************** MEMBER FUNCTIONS ******************************/

void	Bureaucrat::checkGrade(void) const
{
	if (this->getGrade() < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (this->getGrade() > 150)
		throw Bureaucrat::GradeTooLowException();
}

void	Bureaucrat::incrementGrade(void)
{
	if (this->getGrade() - 1 < 1)
		throw Bureaucrat::GradeTooHighException();
	this->_grade--;
	std::cout << this->getName() << ", bureaucrat grade increased to ";
	std::cout << this->getGrade() << "." << std::endl;
}

void	Bureaucrat::decrementGrade(void)
{
	if (this->getGrade() + 1 > 150)
		throw Bureaucrat::GradeTooLowException();
	this->_grade++;
	std::cout << this->getName() << ", bureaucrat grade decreased to ";
	std::cout << this->getGrade() << "." << std::endl;
}

/***************************** GETTERS & SETTERS ******************************/

std::string		Bureaucrat::getName(void) const
{
	return (this->_name);
}

int	Bureaucrat::getGrade(void) const
{
	return (this->_grade);
}

/****************************** NESTED CLASSES ********************************/

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade too high.");
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade too low.");
}

/***************************** NON-MEMBER FUNCTIONS ***************************/

std::ostream & operator<<(std::ostream & stream, Bureaucrat const & source)
{
	stream << source.getName() << ", bureaucrat grade " << source.getGrade();
	stream << ".";
	return (stream);
}
