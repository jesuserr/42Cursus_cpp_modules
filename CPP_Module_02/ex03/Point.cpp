/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesuserr <jesuserr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 21:06:21 by jesuserr          #+#    #+#             */
/*   Updated: 2023/10/21 23:35:03 by jesuserr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point(void) : _fp_x(Fixed(0)), _fp_y(Fixed(0))
{
	//std::cout << "Default constructor called" << std::endl;
	//std::cout << _fp_x << std::endl;
	//std::cout << _fp_y << std::endl;
}

Point::Point(float const x, float const y) : _fp_x(Fixed(x)), _fp_y(Fixed(y))
{
	//std::cout << "Float constructor called" << std::endl;	
	//std::cout << _fp_x << std::endl;
	//std::cout << _fp_y << std::endl;
}

Point::Point(Point const & source) : _fp_x(Fixed(source._fp_x)), _fp_y(Fixed(source._fp_y))
{
	//std::cout << "Copy constructor called" << std::endl;
	//std::cout << _fp_x << std::endl;
	//std::cout << _fp_y << std::endl;
}

Point & Point::operator=(Point const & source)
{
	//std::cout << "Copy assignment operator called" << std::endl;
	if (this != &source)
	{
		const_cast<Fixed&>(this->_fp_x) = source._fp_x;
		const_cast<Fixed&>(this->_fp_y) = source._fp_y;		
	}
	//std::cout << this->_fp_x << std::endl;
	//std::cout << this->_fp_y << std::endl;
	return (*this);
}

Point::~Point(void)
{
	//std::cout << "Destructor called" << std::endl;
}

Fixed	Point::get_fp_x(void) const
{
	return (this->_fp_x);
}

Fixed	Point::get_fp_y(void) const
{
	return (this->_fp_y);
}
