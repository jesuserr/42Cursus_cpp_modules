/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesuserr <jesuserr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 11:52:57 by jesuserr          #+#    #+#             */
/*   Updated: 2023/12/18 21:04:11 by jesuserr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

/*********************** ORTHODOX CANONICAL CLASS FORM ************************/

Form::Form(void) : \
_formName ("Default"), _isSigned(false), _gradeToSign(150), _gradeToExec(150)
{
	std::cout << "Default, unsigned Form created." << std::endl;
}

Form::Form(std::string const name, int const gts, int const gte) : \
_formName(name), _isSigned(false), _gradeToSign(gts), _gradeToExec(gte)
{
	checkGradeForm();
	std::cout << this->_formName << ", unsigned Form created." << std::endl;	
}

Form::Form(Form const & source) : _formName(source._formName), \
_isSigned(source._isSigned), _gradeToSign(source._gradeToSign), \
_gradeToExec(source._gradeToExec)
{
	std::cout << source._formName << ", Form cloned." << std::endl;
	*this = source;
}

Form & Form::operator=(Form const & source)
{
	if (this != &source)
	{
		std::cout << this->getFormName() << ", Form signature assigned.";
		std::cout << std::endl;
		this->_isSigned = source.getIsSigned();
		//checkGradeForm();
	}	
	return (*this);
}

Form::~Form(void)
{
	std::cout << this->_formName << ", Form destroyed." << std::endl;
}

/****************************** MEMBER FUNCTIONS ******************************/

void	Form::checkGradeForm(void) const
{
	if (this->getGradeToSign() < 1 || this->getGradeToExec() < 1)
		throw Form::GradeTooHighException();
	else if (this->getGradeToSign() > 150 || this->getGradeToExec() > 150)
		throw Form::GradeTooLowException();
}

void	Form::beSigned(Bureaucrat const &bureaucrat)
{
	if (bureaucrat.getGrade() <= this->getGradeToSign())
		this->_isSigned = true;
	else
		throw Form::GradeTooLowException();
}

/***************************** GETTERS & SETTERS ******************************/

std::string	Form::getFormName(void) const
{
	return (this->_formName);
}

bool	Form::getIsSigned(void) const
{
	return (this->_isSigned);
}

int	Form::getGradeToSign(void) const
{
	return (this->_gradeToSign);	
}

int	Form::getGradeToExec(void) const
{
	return (this->_gradeToExec);
}

/****************************** NESTED CLASSES ********************************/

const char* Form::GradeTooHighException::what() const throw()
{
	return ("Grade too high required by Form.");
}

const char* Form::GradeTooLowException::what() const throw()
{
	return ("Grade too low required by Form.");
}

/***************************** NON-MEMBER FUNCTIONS ***************************/

std::ostream & operator<<(std::ostream & stream, Form const & source)
{
	stream << source.getFormName();
	if (source.getIsSigned())
		stream << ", signed Form, ";
	else
		stream << ", unsigned Form, ";
	stream << "Grade to sign: " << source.getGradeToSign();
	stream << ", Grade to execute: " << source.getGradeToExec() << ".";
	return (stream);
}
