/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesuserr <jesuserr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 11:50:45 by jesuserr          #+#    #+#             */
/*   Updated: 2023/10/21 15:20:25 by jesuserr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int const Fixed::_fraction_bits = 8;

Fixed::Fixed(void) : _fp_value(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(Fixed const & source)
{
	std::cout << "Copy constructor called" << std::endl;
	this->_fp_value = source.getRawBits();
}

Fixed & Fixed::operator=(Fixed const & source)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &source)
		this->_fp_value = source.getRawBits();
	return(*this);
}

int		Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return(this->_fp_value);
}

void	Fixed::setRawBits(int const raw)
{
	//std::cout << "setRawBits member function called" << std::endl;
	this->_fp_value = raw;
}
