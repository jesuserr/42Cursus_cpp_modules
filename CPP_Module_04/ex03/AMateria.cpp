/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesuserr <jesuserr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 11:06:56 by jesuserr          #+#    #+#             */
/*   Updated: 2023/12/02 13:19:09 by jesuserr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

/*********************** ORTHODOX CANONICAL CLASS FORM ************************/

AMateria::AMateria(void) : _type ("AMateria")
{
	std::cout << "AMateria created." << std::endl;	
}

AMateria::AMateria(std::string const & type) : _type(type)
{
	std::cout << "AMateria " << this->_type << " created." << std::endl;
}

AMateria::AMateria(AMateria const & source)
{
	std::cout << "AMateria " << source._type << " cloned." << std::endl;
	*this = source;
}

AMateria & AMateria::operator=(AMateria const & source)
{
	if (this != &source)
	{
		std::cout << "Cloned AMateria assigned with new type." << std::endl;
		this->_type = source._type;
	}
	return (*this);
}

AMateria::~AMateria(void)
{
	if (this->getType() == "AMateria")
		std::cout << "AMateria";
	else
		std::cout << "AMateria " << this->_type;
	std::cout << " destroyed." << std::endl;
}

/****************************** MEMBER FUNCTIONS ******************************/

void AMateria::use(ICharacter& target)
{
	if (this->_type == "ice")
		std::cout << "* shoots an ice bolt at " << target.getName() << " *";
	else if (this->_type == "cure")
		std::cout << "* heals " << target.getName() << "'s wounds *";
	else
		std::cout << "* nothing happens *";
	std::cout << std::endl;
}

/***************************** GETTERS & SETTERS ******************************/

std::string const & AMateria::getType(void) const
{
	return (this->_type);
}
