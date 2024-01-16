/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesuserr <jesuserr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 14:20:02 by jesuserr          #+#    #+#             */
/*   Updated: 2023/11/27 10:51:10 by jesuserr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

/*********************** ORTHODOX CANONICAL CLASS FORM ************************/

Brain::Brain(void)
{
	for (int i = 0; i < 100; i++)
		this->_ideas[i] = "no_idea";
	std::cout << "Brain created." << std::endl;
}

Brain::Brain(Brain const & source)
{
	for (int i = 0; i < 100; i++)
		this->_ideas[i] = source._ideas[i];
	std::cout << "Brain cloned." << std::endl;
}

Brain & Brain::operator=(Brain const & source)
{
	if (this != &source)
	{
		for (int i = 0; i < 100; i++)
			this->_ideas[i] = source._ideas[i];
		std::cout << "Cloned Brain assigned with new ideas." << std::endl;
	}
	return (*this);
}

Brain::~Brain(void)
{
	std::cout << "Brain destroyed." << std::endl;
}

/***************************** GETTERS & SETTERS ******************************/

std::string*	Brain::getIdeas(void)
{
	return (this->_ideas);
}

std::string	Brain::getIdea(int i) const
{
	if (i >= 0 && i < 100)
		return (this->_ideas[i]);
	std::cout << "Index out of range." << std::endl;
	return (NULL);
}

void	Brain::setIdea(int i, std::string idea)
{
	if (i >= 0 && i < 100)
		this->_ideas[i] = idea;
	else
		std::cout << "Index out of range." << std::endl;
}
