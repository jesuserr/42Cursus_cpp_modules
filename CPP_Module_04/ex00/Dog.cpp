/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesuserr <jesuserr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 12:10:45 by jesuserr          #+#    #+#             */
/*   Updated: 2023/11/26 10:27:42 by jesuserr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

/*********************** ORTHODOX CANONICAL CLASS FORM ************************/

Dog::Dog(void) : Animal("Dog")
{
	std::cout << "Dog created." << std::endl;	
}

Dog::Dog(Dog const & source) : Animal(source)
{
	std::cout << "Dog " << source._type << " cloned." << std::endl;
	*this = source;
}

Dog & Dog::operator=(Dog const & source)
{
	if (this != &source)
	{
		std::cout << "Cloned Dog assigned with new type." << std::endl;
		this->_type = source._type;
	}
	return (*this);
}

Dog::~Dog(void)
{
	std::cout << "Dog goes to heaven." << std::endl;
}

/****************************** MEMBER FUNCTIONS ******************************/

void	Dog::makeSound() const
{
	std::cout << "Dog barks." << std::endl;
}
