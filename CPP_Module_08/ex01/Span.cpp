/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesuserr <jesuserr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 11:39:24 by jesuserr          #+#    #+#             */
/*   Updated: 2024/01/03 21:10:53 by jesuserr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

/*********************** ORTHODOX CANONICAL CLASS FORM ************************/

Span::Span(void) : _size(0)
{
	std::cout << "Vector created, size: \t0\n";	
}

Span::Span(unsigned int size) : _size(size)
{
	std::cout << "Vector created, size: \t" << size << '\n';
}

// _vector(source._vector) makes a deep copy of the vector, assignment operator
// for standard containers like std::vector performs a deep copy
Span::Span(const Span& source) : _size(source._size), _vector(source._vector)
{
	std::cout << "Vector copied, size: \t" << source._size << '\n';
}

Span& Span::operator=(const Span& source)
{
	if (this != &source)
	{
		this->_size = source._size;
		this->_vector = source._vector;
	}
	std::cout << "Vector assigned new values, size: " << source._size << '\n';
	return (*this);
}

Span::~Span(void)
{
	std::cout << "Vector destroyed.\n";
}

/****************************** MEMBER FUNCTIONS ******************************/

void	Span::addNumber(int number)
{
	if (this->_vector.size() < this->_size)
		this->_vector.push_back(number);
	else
		throw Span::FullVectorException();
}

unsigned int Span::shortestSpan() const
{
	std::vector<int> copy = this->_vector;
	std::vector<int>::const_iterator it;
	
	if (this->_vector.size() < 2)
		throw Span::NotEnoughNumbersException();
	std::sort(copy.begin(), copy.end());
	int minValue = copy[1] - copy[0];
	for (it = copy.begin(); it != copy.end() - 1; it++)
	{
		if (*(it + 1) - *it < minValue)
			minValue = *(it + 1) - *it;
	}
    return (minValue);
}

unsigned int Span::longestSpan() const
{
	std::vector<int>::const_iterator minIt;
    std::vector<int>::const_iterator maxIt;
	
	if (this->_vector.size() < 2)
		throw Span::NotEnoughNumbersException();
   	minIt = std::min_element(this->_vector.begin(), this->_vector.end());
    maxIt = std::max_element(this->_vector.begin(), this->_vector.end());
    return (*maxIt - *minIt);
}

void	Span::addRange(iterator begin, iterator end)
{
	if (this->_vector.size() + std::distance(begin, end) > this->_size)
		throw Span::FullVectorException();
	//this->_vector.insert(this->_vector.end(), begin, end); //both are similar
	this->_vector.assign(begin, end);
}

void Span::printVector() const
{
	std::vector<int>::const_iterator it;
	
	std::cout << "Vector current elem.: \t" << this->_vector.size() << '\n';
	std::cout << "Vector maximum size: \t" << this->_size << '\n';
	std::cout << "Vector content: \t";
	for (it = this->_vector.begin(); it != this->_vector.end(); it++)
		std::cout << *it << ' ';
	std::cout << '\n';	
}

/***************************** GETTERS & SETTERS ******************************/

unsigned int Span::getCurrentSize() const
{
	return (this->_vector.size());
}

/****************************** NESTED CLASSES ********************************/

const char* Span::FullVectorException::what() const throw()
{
	return ("Error - Vector is full.");	
}

const char* Span::NotEnoughNumbersException::what() const throw()
{
	return ("Error - Not enough numbers to calculate span.");
}
