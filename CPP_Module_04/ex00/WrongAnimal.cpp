/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesuserr <jesuserr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 13:49:47 by jesuserr          #+#    #+#             */
/*   Updated: 2023/11/24 13:50:06 by jesuserr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

/*********************** ORTHODOX CANONICAL CLASS FORM ************************/

WrongAnimal::WrongAnimal(void) : _type ("WrongAnimal")
{
	std::cout << "WrongAnimal created." << std::endl;	
}

WrongAnimal::WrongAnimal(std::string const name) : _type(name)
{
	std::cout << "WrongAnimal " << this->_type << " created." << std::endl;
}

WrongAnimal::WrongAnimal(WrongAnimal const & source)
{
	std::cout << "WrongAnimal " << source._type << " cloned." << std::endl;
	*this = source;
}

WrongAnimal & WrongAnimal::operator=(WrongAnimal const & source)
{
	if (this != &source)
	{
		std::cout << "Cloned WrongAnimal assigned with new type." << std::endl;
		this->_type = source._type;
	}
	return (*this);
}

WrongAnimal::~WrongAnimal(void)
{
	if (this->getType() == "WrongAnimal")
		std::cout << "WrongAnimal";
	else
		std::cout << "WrongAnimal " << this->_type;
	std::cout << " goes to heaven." << std::endl;
}

/****************************** MEMBER FUNCTIONS ******************************/

void	WrongAnimal::makeSound() const
{
	std::cout << "WrongAnimal makes unknown sound." << std::endl;
}

/***************************** GETTERS & SETTERS ******************************/

std::string		WrongAnimal::getType(void) const
{
	return (this->_type);
}
