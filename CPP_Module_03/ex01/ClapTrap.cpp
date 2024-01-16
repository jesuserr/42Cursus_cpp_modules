/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesuserr <jesuserr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 18:44:52 by jesuserr          #+#    #+#             */
/*   Updated: 2023/11/19 21:41:07 by jesuserr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

/*********************** ORTHODOX CANONICAL CLASS FORM ************************/

ClapTrap::ClapTrap(void)
{
	std::cout << "Unnamed ClapTrap ready to fight!!" << std::endl;
	this->_name = "Unnamed";
	this->_hitPoints = 10;
	this->_energyPoints = 10;
	this->_attackDamage = 0;
}

ClapTrap::ClapTrap(std::string const name) : _name(name)
{
	std::cout << "ClapTrap " << this->_name << ", ready to fight!!" << std::endl;
	this->_hitPoints = 10;
	this->_energyPoints = 10;
	this->_attackDamage = 0;
}

ClapTrap::ClapTrap(ClapTrap const & source)
{
	std::cout << "ClapTrap " << source._name << " cloned." << std::endl;
	*this = source;
}

ClapTrap & ClapTrap::operator=(ClapTrap const & source)
{
	if (this != &source)
	{
		std::cout << "Cloned ClapTrap assigned with new atributes, ready to " \
		<< "fight!!" << std::endl;
		this->_name = source._name;
		this->_hitPoints = source._hitPoints;
		this->_energyPoints = source._energyPoints;
		this->_attackDamage = source._attackDamage;
	}
	return (*this);
}

ClapTrap::~ClapTrap(void)
{
	if (this->getName() == "Unnamed")
		std::cout << "Unnamed ClapTrap";
	else
		std::cout << "ClapTrap " << this->_name;
	std::cout << " leaves the battlefield." << std::endl;
}

/****************************** MEMBER FUNCTIONS ******************************/

void	ClapTrap::attack(std::string const & target)
{
	if (this->_hitPoints < 1)
		std::cout << "ClapTrap " << this->_name << " cannot attack " << target \
		<< ", no hit points left.";
	else if (this->_energyPoints < 1)
		std::cout << "ClapTrap " << this->_name << " cannot attack " << target \
		<< ", no energy points left.";
	else
	{
		std::cout << "ClapTrap " << this->_name << " attacks " << target << \
		", causing " << this->_attackDamage << " damage points.";
		this->_energyPoints--;
	}
	std::cout << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (this->_hitPoints < 1)
		std::cout << "ClapTrap " << this->_name << " is already defeated";
	else
	{
		std::cout << "ClapTrap " << this->_name << " takes " \
		<< amount << " damage points";
		if (amount >= this->_hitPoints)
		{
			amount = this->_hitPoints;
			std::cout << " and is defeated";
		}
		this->_hitPoints -= amount;
	}
	std::cout << "." << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_energyPoints < 1)
		std::cout << "ClapTrap " << this->_name << " cannot repair itself, "\
		<< "no energy points left.";
	else if (this->_hitPoints < 1)
		std::cout << "ClapTrap " << this->_name << " cannot repair itself, "\
		<< "no hit points left.";
	else
	{
		std::cout << "ClapTrap " << this->_name << " repairs itself";
		this->_energyPoints--;
		this->_hitPoints += amount;
		std::cout << " with additional " << amount << " hit points.";
	}
	std::cout << std::endl;
}

/***************************** GETTERS & SETTERS ******************************/

unsigned int	ClapTrap::getHitPoints(void) const
{
	return (this->_hitPoints);
}

unsigned int	ClapTrap::getEnergyPoints(void) const
{
	return (this->_energyPoints);
}

unsigned int	ClapTrap::getAttackDamage(void) const
{
	return (this->_attackDamage);
}

std::string		ClapTrap::getName(void) const
{
	return (this->_name);
}

void	ClapTrap::setHitPoints(unsigned int value)
{
	this->_hitPoints = value;
}

void	ClapTrap::setEnergyPoints(unsigned int value)
{
	this->_energyPoints = value;
}
void	ClapTrap::setAttackDamage(unsigned int value)
{
	this->_attackDamage = value;
}

void	ClapTrap::setName(std::string name)
{
	this->_name = name;
}

/***************************** NON-MEMBER FUNCTIONS ***************************/

std::ostream & operator<<(std::ostream & stream, ClapTrap const & source)
{
	stream << "Name:[" << source.getName() << "]  Hit points:[" << \
	source.getHitPoints() << "]  Energy points:[" << source.getEnergyPoints() \
	<< "]  Damage points:[" << source.getAttackDamage() << "]";
	return (stream);
}
