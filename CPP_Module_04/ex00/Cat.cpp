/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesuserr <jesuserr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 12:15:37 by jesuserr          #+#    #+#             */
/*   Updated: 2023/11/26 10:37:32 by jesuserr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

/*********************** ORTHODOX CANONICAL CLASS FORM ************************/

Cat::Cat(void) : Animal("Cat")
{
	std::cout << "Cat created." << std::endl;
}

Cat::Cat(Cat const & source) : Animal(source)
{
	std::cout << "Cat " << source._type << " cloned." << std::endl;
	*this = source;
}

Cat & Cat::operator=(Cat const & source)
{
	if (this != &source)
	{
		std::cout << "Cloned Cat assigned with new type." << std::endl;
		this->_type = source._type;
	}
	return (*this);
}

Cat::~Cat(void)
{
	std::cout << "Cat goes to heaven." << std::endl;
}

/****************************** MEMBER FUNCTIONS ******************************/

void	Cat::makeSound() const
{
	std::cout << "Cat meows." << std::endl;
}
