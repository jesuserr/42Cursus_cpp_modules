/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesuserr <jesuserr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 12:32:37 by jesuserr          #+#    #+#             */
/*   Updated: 2023/12/01 09:06:04 by jesuserr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

/*********************** ORTHODOX CANONICAL CLASS FORM ************************/

Ice::Ice(void) : AMateria("ice")
{
	std::cout << "Ice created." << std::endl;
}

Ice::Ice(Ice const & source) : AMateria(source)
{
	std::cout << "Ice " << source._type << " cloned." << std::endl;
	*this = source;
}

Ice & Ice::operator=(Ice const & source)
{
	if (this != &source)
	{
		std::cout << "Cloned Ice assigned with new type." << std::endl;
		this->_type = source._type;
	}
	return (*this);
}

Ice::~Ice(void)
{
	std::cout << "Ice destroyed." << std::endl;
}

/****************************** MEMBER FUNCTIONS ******************************/

AMateria*   Ice::clone(void) const
{
	return (new Ice(*this));
}
