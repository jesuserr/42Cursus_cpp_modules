/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesuserr <jesuserr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 11:50:45 by jesuserr          #+#    #+#             */
/*   Updated: 2023/10/21 15:43:44 by jesuserr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int const Fixed::_fraction_bits = 8;

Fixed::Fixed(void) : _fp_value(0)
{
	//std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(int const value) : _fp_value(value << Fixed::_fraction_bits)
{
	//std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(float const value) : _fp_value(roundf(value * (1 << Fixed::_fraction_bits)))
{
	//std::cout << "Float constructor called" << std::endl;
}

Fixed::~Fixed(void)
{
	//std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(Fixed const & source)
{
	//std::cout << "Copy constructor called" << std::endl;
	*this = source;
}

Fixed & Fixed::operator=(Fixed const & source)
{
	//std::cout << "Copy assignment operator called" << std::endl;
	if (this != &source)
		this->_fp_value = source._fp_value;
	return (*this);
}

int		Fixed::getRawBits(void) const
{
	//std::cout << "getRawBits member function called" << std::endl;
	return (this->_fp_value);
}

void	Fixed::setRawBits(int const raw)
{
	//std::cout << "setRawBits member function called" << std::endl;
	this->_fp_value = raw;
}

float	Fixed::toFloat(void) const
{
	return ((float)this->_fp_value / (1 << Fixed::_fraction_bits));	
}

int		Fixed::toInt(void) const
{
	return (this->_fp_value >> Fixed::_fraction_bits);
}

std::ostream & operator<<(std::ostream & stream, Fixed const & source)
{
	stream << source.toFloat();
	return (stream);
}

/************************************ ex02 ************************************/
/**************************** ARITHMETIC OPERATORS ****************************/

Fixed Fixed::operator*(Fixed const & source)
{
	//std::cout << "Multiplication operator called" << std::endl;
	this->_fp_value = this->toFloat() * source.toFloat() * (1 << Fixed::_fraction_bits);
	return (*this);	
}

Fixed Fixed::operator+(Fixed const & source)
{
	//std::cout << "Addition operator called" << std::endl;
	//std::cout << this->_fp_value << std::endl;
	//std::cout << source._fp_value << std::endl;
	this->_fp_value = this->_fp_value + source._fp_value;
	return (*this);
}

Fixed Fixed::operator-(Fixed const & source)
{
	//std::cout << "Subtraction operator called" << std::endl;
	this->_fp_value = this->_fp_value - source._fp_value;
	return (*this);
}

Fixed Fixed::operator/(Fixed const & source)
{
	//std::cout << "Division operator called" << std::endl;
	this->_fp_value = this->toFloat() / source.toFloat() * (1 << Fixed::_fraction_bits);
	return (*this);
}

/*********************************** ex02 *************************************/
/*************************** COMPARISON OPERATORS *****************************/

bool	Fixed::operator>(Fixed const & source) const
{
	if (this->_fp_value > source._fp_value)
		return (true);
	return (false);
}

bool	Fixed::operator<(Fixed const & source) const
{
	if (this->_fp_value < source._fp_value)
		return (true);
	return (false);
}

bool	Fixed::operator==(Fixed const & source) const
{
	if (this->_fp_value == source._fp_value)
		return (true);
	return (false);
}

bool	Fixed::operator!=(Fixed const & source) const
{
	if (this->_fp_value != source._fp_value)
		return (true);
	return (false);
}

bool	Fixed::operator>=(Fixed const & source) const
{
	if (this->_fp_value >= source._fp_value)
		return (true);
	return (false);
}

bool	Fixed::operator<=(Fixed const & source) const
{
	if (this->_fp_value <= source._fp_value)
		return (true);
	return (false);
}

/*********************************** ex02 *************************************/
/*************************** INCREMENT / DECREMENT ****************************/

Fixed	Fixed::operator++(void)
{
	this->_fp_value++;
	return (*this);
}

Fixed	Fixed::operator--(void)
{
	this->_fp_value--;
	return (*this);
}

Fixed	Fixed::operator++(int)
{
	Fixed	copy_old = *this;

	this->_fp_value++;
	//operator++();
	return (copy_old);
}

Fixed	Fixed::operator--(int)
{
	Fixed	copy_old = *this;

	this->_fp_value--;
	//operator--();
	return (copy_old);
}

/*********************************** ex02 *************************************/
/************************* COMPARISON WITH REFERENCE **************************/

Fixed & Fixed::min(Fixed & a, Fixed & b)
{
	if (a.getRawBits() > b.getRawBits())
		return (b);
	return (a);	
}

Fixed & Fixed::max(Fixed & a, Fixed & b)
{
	if (a.getRawBits() > b.getRawBits())
		return (a);
	return (b);	
}

Fixed const & Fixed::min(Fixed const & a, Fixed const & b)
{
	if (a.getRawBits() > b.getRawBits())
		return (b);
	return (a);	
}

Fixed const & Fixed::max(Fixed const & a, Fixed const & b)
{
	if (a.getRawBits() > b.getRawBits())
		return (a);
	return (b);	
}
