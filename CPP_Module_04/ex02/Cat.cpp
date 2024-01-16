/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesuserr <jesuserr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 12:15:37 by jesuserr          #+#    #+#             */
/*   Updated: 2023/11/27 18:08:03 by jesuserr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

/*********************** ORTHODOX CANONICAL CLASS FORM ************************/

Cat::Cat(void) : AAnimal("Cat")
{
	std::cout << "Cat created." << std::endl;
	this->_brain = new Brain();
}

Cat::Cat(Cat const & source) : AAnimal(source)
{
	std::cout << "Cat cloned." << std::endl;
	this->_brain = new Brain();
	for (int i = 0; i < 100; i++)
		this->_brain->setIdea(i, source._brain->getIdea(i));	
}

Cat & Cat::operator=(Cat const & source)
{
	if (this != &source)
	{
		std::cout << "Cloned Cat assigned with new ideas." << std::endl;
		this->_type = source._type;
		for (int i = 0; i < 100; i++)
			this->_brain->setIdea(i, source._brain->getIdea(i));		
	}
	return (*this);
}

Cat::~Cat(void)
{
	std::cout << "Cat goes to heaven." << std::endl;
	delete this->_brain;
}

/****************************** MEMBER FUNCTIONS ******************************/

void	Cat::makeSound() const
{
	std::cout << "Cat meows." << std::endl;
}

Brain	*Cat::getBrain(void) const
{
	return (this->_brain);
}
