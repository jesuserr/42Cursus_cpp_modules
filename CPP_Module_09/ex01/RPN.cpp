/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesuserr <jesuserr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 09:52:51 by jesuserr          #+#    #+#             */
/*   Updated: 2024/01/11 15:30:45 by jesuserr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

/*********************** ORTHODOX CANONICAL CLASS FORM ************************/

RPN::RPN(void)
{
	//std::cout << "RPN constructor called" << '\n';
}

RPN::RPN(const RPN& source)
{
	(void)source;
}

RPN& RPN::operator=(const RPN& source)
{
	(void)source;
	return (*this);
}

RPN::~RPN(void)
{
	//std::cout << "RPN destructor called" << '\n';
}

/****************************** MEMBER FUNCTIONS ******************************/

void	RPN::calculate(const std::string expression)
{
	std::stringstream ss(expression);
	std::string value;
	float number;
	
	while (ss >> value)
	{
		if (value.length() != 1)
			throw std::invalid_argument("Error: invalid expression.");
		if (value[0] >= '0' && value[0] <= '9')
		{
			std::istringstream(value) >> number;
			_myStack.push(number);
		}
		else if (value[0] == '+' || value[0] == '-' || value[0] == '*' || value[0] == '/')
			executeOperator(value[0]);
		else
			throw std::invalid_argument("Error: invalid expression.");
	}
	if (_myStack.size() != 1)
		throw std::invalid_argument("Error: invalid expression.");
	std::cout << std::setprecision(39);
	std::cout << _myStack.top() << std::endl;
}

void	RPN::executeOperator(const char operation)
{
	float firstOperand;
	float secondOperand;
	
	if (_myStack.size() < 2)
		throw std::invalid_argument("Error: invalid expression.");
	secondOperand = _myStack.top();
	_myStack.pop();
	firstOperand = _myStack.top();
	_myStack.pop();
	if (operation == '+')
		_myStack.push(firstOperand + secondOperand);
	else if (operation == '-')
		_myStack.push(firstOperand - secondOperand);
	else if (operation == '*')
		_myStack.push(firstOperand * secondOperand);
	else if (operation == '/')
	{
		if (secondOperand == 0)
			throw std::invalid_argument("Error: division by zero.");
		_myStack.push(firstOperand / secondOperand);
	}		
}
