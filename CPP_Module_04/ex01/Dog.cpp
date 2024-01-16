/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesuserr <jesuserr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 12:10:45 by jesuserr          #+#    #+#             */
/*   Updated: 2023/11/27 11:36:16 by jesuserr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

/*********************** ORTHODOX CANONICAL CLASS FORM ************************/

Dog::Dog(void) : Animal("Dog")
{
	std::cout << "Dog created." << std::endl;
	this->_brain = new Brain();
}

Dog::Dog(Dog const & source) : Animal(source)
{
	std::cout << "Dog cloned." << std::endl;
	this->_brain = new Brain();
	for (int i = 0; i < 100; i++)
		this->_brain->setIdea(i, source._brain->getIdea(i));	
}

Dog & Dog::operator=(Dog const & source)
{
	if (this != &source)
	{
		std::cout << "Cloned Dog assigned with new ideas." << std::endl;
		this->_type = source._type;
		for (int i = 0; i < 100; i++)
			this->_brain->setIdea(i, source._brain->getIdea(i));		
	}
	return (*this);
}

Dog::~Dog(void)
{
	std::cout << "Dog goes to heaven." << std::endl;
	delete this->_brain;
}

/****************************** MEMBER FUNCTIONS ******************************/

void	Dog::makeSound() const
{
	std::cout << "Dog barks." << std::endl;
}

Brain	*Dog::getBrain(void) const
{
	return (this->_brain);
}
