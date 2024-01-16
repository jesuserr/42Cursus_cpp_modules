/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesuserr <jesuserr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 14:13:21 by jesuserr          #+#    #+#             */
/*   Updated: 2023/12/03 12:54:55 by jesuserr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

/*********************** ORTHODOX CANONICAL CLASS FORM ************************/

Character::Character(void) : _name("Character"), _count(0)
{
	std::cout << "Character " << this->_name << " created." << std::endl;
	for (int i = 0; i < 4; i++)
		this->_inventory[i] = NULL;
}

Character::Character(std::string const & type) : _name(type), _count(0)
{
	std::cout << "Character " << this->_name << " created." << std::endl;
	for (int i = 0; i < 4; i++)
		this->_inventory[i] = NULL;
}

Character::Character(Character const & source)
{
	std::cout << "Character " << source._name << " cloned." << std::endl;
	this->_name = source._name;
	this->_count = source._count;
	for (int i = 0; i < 4; i++)
	{
		this->_inventory[i] = NULL;
		if (source._inventory[i] != NULL)
			this->_inventory[i] = source._inventory[i]->clone();
	}
}

Character & Character::operator=(Character const & source)
{
	if (this != &source)
	{
		std::cout << "Cloned Character assigned with new name." << std::endl;
		this->_count = source._count;
		for (int i = 0; i < 4; i++)
		{
			if (this->_inventory[i] != NULL)
				delete this->_inventory[i];
			this->_inventory[i] = NULL;
			if (source._inventory[i] != NULL)
				this->_inventory[i] = source._inventory[i]->clone();
		}
	}
	return (*this);
}

Character::~Character(void)
{
	std::cout << "Character " << this->_name << " destroyed." << std::endl;
	for (int i = 0; i < 4; i++)
		if (this->_inventory[i])
			delete this->_inventory[i];
}

/***************************** GETTERS & SETTERS ******************************/

std::string const & Character::getName() const
{
	return (this->_name);
}

/****************************** MEMBER FUNCTIONS ******************************/

void Character::equip(AMateria* m)
{
	int i = 0;
	
	if (this->_count < 4 && m != NULL)
	{
		while (this->_inventory[i])
			i++;
		this->_inventory[i] = m;
		this->_count++;
		std::cout << "Materia " << m->getType() << " equipped by " << this->_name;
		std::cout << "." << std::endl;
	}
	else if (this->_count == 4)
	{
		std::cout << "Inventory is full." << std::endl;
		delete m;
	}
	else
		std::cout << "Nonexisting Materia." << std::endl;
}

void Character::unequip(int idx)
{
	if (idx >= 0 && idx < 4 && this->_inventory[idx] != NULL)
	{
		std::cout << "Materia " << this->_inventory[idx]->getType();
		std::cout << " unequipped from " << this->_name << "." << std::endl;
		this->_inventory[idx] = NULL;
		this->_count--;		
	}
	else if (idx < 0 || idx >= 4)
		std::cout << "Slot index out of range." << std::endl;
	else
		std::cout << "No Materia in slot " << idx << "." << std::endl;
}

void Character::use(int idx, ICharacter& target)
{
	if (idx >= 0 && idx < 4 && this->_inventory[idx] != NULL)
		this->_inventory[idx]->use(target);
	else if (idx < 0 || idx >= 4)
		std::cout << "Slot index out of range." << std::endl;
	else
		std::cout << "No Materia in slot " << idx << "." << std::endl;
}

/*********************************** TESTER ***********************************/

void	Character::printMaterias(void) const
{
	for (int i = 0; i < 4; i++)
	{
		std::cout << this->_name << " inventory[" << i << "] = ";
		if (this->_inventory[i])
			std::cout << this->_inventory[i];
		else
			std::cout << "Empty";
		std::cout << std::endl;
	}
}
