/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesuserr <jesuserr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 18:07:05 by jesuserr          #+#    #+#             */
/*   Updated: 2023/11/27 18:07:06 by jesuserr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

/*********************** ORTHODOX CANONICAL CLASS FORM ************************/

AAnimal::AAnimal(void) : _type ("AAnimal")
{
	std::cout << "AAnimal created." << std::endl;	
}

AAnimal::AAnimal(std::string const name) : _type(name)
{
	std::cout << "AAnimal " << this->_type << " created." << std::endl;
}

AAnimal::AAnimal(AAnimal const & source)
{
	std::cout << "AAnimal " << source._type << " cloned." << std::endl;
	*this = source;
}

AAnimal & AAnimal::operator=(AAnimal const & source)
{
	if (this != &source)
	{
		std::cout << "Cloned AAnimal assigned with new type." << std::endl;
		this->_type = source._type;
	}
	return (*this);
}

AAnimal::~AAnimal(void)
{
	if (this->getType() == "AAnimal")
		std::cout << "AAnimal";
	else
		std::cout << "AAnimal " << this->_type;
	std::cout << " goes to heaven." << std::endl;
}

/****************************** MEMBER FUNCTIONS ******************************/

void	AAnimal::makeSound() const
{
	std::cout << "AAnimal makes unknown sound." << std::endl;
}

/***************************** GETTERS & SETTERS ******************************/

std::string		AAnimal::getType(void) const
{
	return (this->_type);
}
