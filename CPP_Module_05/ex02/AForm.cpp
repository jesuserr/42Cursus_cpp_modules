/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesuserr <jesuserr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 12:44:14 by jesuserr          #+#    #+#             */
/*   Updated: 2023/12/18 21:53:42 by jesuserr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

/********************** ORTHODOX CANONICAL CLASS FORM *************************/

AForm::AForm(void) : \
_formName ("Default"), _isSigned(false), _gradeToSign(150), _gradeToExec(150), \
_target("Default")
{
	//std::cout << "Default, unsigned AForm created." << std::endl;
}

AForm::AForm(std::string const name, int const gts, int const gte, \
std::string const target) : _formName(name), _isSigned(false), _gradeToSign(gts), \
_gradeToExec(gte), _target(target)
{
	checkGradeForm();
	//std::cout << this->_formName << ", unsigned AForm created." << std::endl;	
}

AForm::AForm(AForm const & source) : _formName(source._formName), \
_isSigned(source._isSigned), _gradeToSign(source._gradeToSign), \
_gradeToExec(source._gradeToExec), _target(source._target)
{
	//std::cout << source._formName << ", AForm cloned." << std::endl;
	*this = source;
}

AForm & AForm::operator=(AForm const & source)
{
	if (this != &source)
	{
		//std::cout << this->getFormName() << ", AForm signature assigned.";
		//std::cout << std::endl;
		this->_isSigned = source.getIsSigned();
		//checkGradeForm();
	}	
	return (*this);
}

AForm::~AForm(void)
{
	//std::cout << this->_formName << ", AForm destroyed." << std::endl;
}

/****************************** MEMBER FUNCTIONS ******************************/

void	AForm::checkGradeForm(void) const
{
	if (this->getGradeToSign() < 1 || this->getGradeToExec() < 1)
		throw AForm::GradeTooHighException();
	else if (this->getGradeToSign() > 150 || this->getGradeToExec() > 150)
		throw AForm::GradeTooLowException();
}

void	AForm::beSigned(Bureaucrat const &bureaucrat)
{
	if (bureaucrat.getGrade() <= this->getGradeToSign())
		this->_isSigned = true;
	else
		throw AForm::GradeTooLowException();
}

void	AForm::checkExecute(Bureaucrat const & executor) const
{
	if (!this->getIsSigned())
		throw AForm::FormNotSignedException();
	else if (executor.getGrade() > this->getGradeToExec())
		throw AForm::GradeTooLowException();	
}

/***************************** GETTERS & SETTERS ******************************/

std::string	AForm::getFormName(void) const
{
	return (this->_formName);
}

bool	AForm::getIsSigned(void) const
{
	return (this->_isSigned);
}

int	AForm::getGradeToSign(void) const
{
	return (this->_gradeToSign);	
}

int	AForm::getGradeToExec(void) const
{
	return (this->_gradeToExec);
}

std::string	AForm::getTarget(void) const
{
	return (this->_target);
}

void	AForm::setSignature(bool sign)
{
	this->_isSigned = sign;
}

/****************************** NESTED CLASSES ********************************/

const char* AForm::GradeTooHighException::what() const throw()
{
	return ("Grade too high required by AForm.");
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return ("Grade too low required by AForm.");
}

const char* AForm::FormNotSignedException::what() const throw()
{
	return ("AForm is not signed.");
}

/***************************** NON-MEMBER FUNCTIONS ***************************/

std::ostream & operator<<(std::ostream & stream, AForm const & source)
{
	stream << source.getFormName() << " on " << source.getTarget();
	if (source.getIsSigned())
		stream << ", signed AForm, ";
	else
		stream << ", unsigned AForm, ";
	stream << "Grade to sign: " << source.getGradeToSign();
	stream << ", Grade to execute: " << source.getGradeToExec() << ".";
	return (stream);
}
