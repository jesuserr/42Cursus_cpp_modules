/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesuserr <jesuserr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 12:29:10 by jesuserr          #+#    #+#             */
/*   Updated: 2023/11/24 13:40:55 by jesuserr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

/*********************** ORTHODOX CANONICAL CLASS FORM ************************/

Animal::Animal(void) : _type ("Animal")
{
	std::cout << "Animal created." << std::endl;	
}

Animal::Animal(std::string const name) : _type(name)
{
	std::cout << "Animal " << this->_type << " created." << std::endl;
}

Animal::Animal(Animal const & source)
{
	std::cout << "Animal " << source._type << " cloned." << std::endl;
	*this = source;
}

Animal & Animal::operator=(Animal const & source)
{
	if (this != &source)
	{
		std::cout << "Cloned Animal assigned with new type." << std::endl;
		this->_type = source._type;
	}
	return (*this);
}

Animal::~Animal(void)
{
	if (this->getType() == "Animal")
		std::cout << "Animal";
	else
		std::cout << "Animal " << this->_type;
	std::cout << " goes to heaven." << std::endl;
}

/****************************** MEMBER FUNCTIONS ******************************/

void	Animal::makeSound() const
{
	std::cout << "Animal makes unknown sound." << std::endl;
}

/***************************** GETTERS & SETTERS ******************************/

std::string		Animal::getType(void) const
{
	return (this->_type);
}
