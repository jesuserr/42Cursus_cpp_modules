/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesuserr <jesuserr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 13:50:41 by jesuserr          #+#    #+#             */
/*   Updated: 2023/11/26 10:29:23 by jesuserr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

/*********************** ORTHODOX CANONICAL CLASS FORM ************************/

WrongCat::WrongCat(void) : WrongAnimal("WrongCat")
{
	std::cout << "WrongCat created." << std::endl;	
}

WrongCat::WrongCat(WrongCat const & source) : WrongAnimal(source)
{
	std::cout << "WrongCat " << source._type << " cloned." << std::endl;
	*this = source;
}

WrongCat & WrongCat::operator=(WrongCat const & source)
{
	if (this != &source)
	{
		std::cout << "Cloned WrongCat assigned with new type." << std::endl;
		this->_type = source._type;
	}
	return (*this);
}

WrongCat::~WrongCat(void)
{
	std::cout << "WrongCat goes to heaven." << std::endl;
}

/****************************** MEMBER FUNCTIONS ******************************/

void	WrongCat::makeSound() const
{
	std::cout << "WrongCat meows." << std::endl;
}
