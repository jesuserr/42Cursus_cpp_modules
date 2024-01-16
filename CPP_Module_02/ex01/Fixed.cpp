/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesuserr <jesuserr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 11:50:45 by jesuserr          #+#    #+#             */
/*   Updated: 2023/10/21 15:20:40 by jesuserr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int const Fixed::_fraction_bits = 8;

Fixed::Fixed(void) : _fp_value(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(int const value) : _fp_value(value << Fixed::_fraction_bits)
{
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(float const value) : _fp_value(roundf(value * (1 << Fixed::_fraction_bits)))
{
	std::cout << "Float constructor called" << std::endl;
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(Fixed const & source)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = source;
}

Fixed & Fixed::operator=(Fixed const & source)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &source)
		this->_fp_value = source._fp_value;
	return (*this);
}

int		Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
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
