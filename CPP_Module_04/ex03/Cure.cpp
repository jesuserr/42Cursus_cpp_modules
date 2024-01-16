/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesuserr <jesuserr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 12:32:40 by jesuserr          #+#    #+#             */
/*   Updated: 2023/12/01 09:05:05 by jesuserr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

/*********************** ORTHODOX CANONICAL CLASS FORM ************************/

Cure::Cure(void) : AMateria("cure")
{
	std::cout << "Cure created." << std::endl;
}

Cure::Cure(Cure const & source) : AMateria(source)
{
	std::cout << "Cure " << source._type << " cloned." << std::endl;
	*this = source;
}

Cure & Cure::operator=(Cure const & source)
{
	if (this != &source)
	{
		std::cout << "Cloned Cure assigned with new type." << std::endl;
		this->_type = source._type;
	}
	return (*this);
}

Cure::~Cure(void)
{
	std::cout << "Cure destroyed." << std::endl;
}

/****************************** MEMBER FUNCTIONS ******************************/

AMateria*   Cure::clone(void) const
{
	return (new Cure(*this));
}
