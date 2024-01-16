/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesuserr <jesuserr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 14:13:32 by jesuserr          #+#    #+#             */
/*   Updated: 2023/12/02 23:36:18 by jesuserr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "MateriaSource.hpp"

/*********************** ORTHODOX CANONICAL CLASS FORM ************************/

MateriaSource::MateriaSource(void)
{
	std::cout << "MateriaSource created." << std::endl;
	this->_index = 0;
	for (int i = 0; i < 4; i++)
		this->_materia[i] = NULL;
}

MateriaSource::MateriaSource(MateriaSource const & source)
{
	std::cout << "MateriaSource cloned." << std::endl;
	this->_index = source._index;
	for (int i = 0; i < 4; i++)
	{
		if (source._materia[i] != NULL)
			this->_materia[i] = source._materia[i]->clone();		
	}
}

MateriaSource & MateriaSource::operator=(MateriaSource const & source)
{
	if (this != &source)
	{
		std::cout << "Cloned MateriaSource assigned with new material." << std::endl;
		this->_index = source._index;
		for (int i = 0; i < 4; i++)
		{
			if (this->_materia[i] != NULL)
				delete this->_materia[i];
			this->_materia[i] = NULL;
			if (source._materia[i] != NULL)
				this->_materia[i] = source._materia[i]->clone();
		}
	}
	return (*this);
}

MateriaSource::~MateriaSource(void)
{
	std::cout << "MateriaSource destroyed." << std::endl;
	for (int i = 0; i < 4; i++)
		if (this->_materia[i])
			delete this->_materia[i];
}

/****************************** MEMBER FUNCTIONS ******************************/

void	MateriaSource::learnMateria(AMateria* m)
{
	int i = 0;
	
	if (this->_index < 4 && m != NULL)
	{
		while (this->_materia[i])
			i++;
		this->_materia[i] = m;
		this->_index++;
		std::cout << "Materia " << m->getType() << " learned." << std::endl;
	}
	else if (this->_index == 4)
	{
		std::cout << "MateriaSource is full." << std::endl;
		delete m;
	}
	else
		std::cout << "Nonexisting Materia." << std::endl;
}

AMateria*	MateriaSource::createMateria(std::string const & type)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->_materia[i] && this->_materia[i]->getType() == type)
		{
			std::cout << "Materia " << type << " cloned." << std::endl;
			return (this->_materia[i]->clone());
		}
	}
	std::cout << "Materia " << type << " not found." << std::endl;
	return (NULL);
}
