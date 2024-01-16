/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesuserr <jesuserr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 19:26:16 by jesuserr          #+#    #+#             */
/*   Updated: 2023/11/19 23:06:35 by jesuserr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

/*********************** ORTHODOX CANONICAL CLASS FORM ************************/

ScavTrap::ScavTrap(void) : ClapTrap()
{
	std::cout << "ScavTrap " << this->getName() << ", ready to fight!!" << std::endl;
	this->setHitPoints(_hitPointsDef);
	this->setEnergyPoints(_energyPointsDef);
	this->setAttackDamage(_attackDamageDef);
}

ScavTrap::ScavTrap(std::string const name) : ClapTrap(name)
{
	std::cout << "ScavTrap " << this->getName() << ", ready to fight!!" << std::endl;
	this->setHitPoints(_hitPointsDef);
	this->setEnergyPoints(_energyPointsDef);
	this->setAttackDamage(_attackDamageDef);
}

ScavTrap::ScavTrap(ScavTrap const & source) : ClapTrap(source)
{
	std::cout << "ScavTrap " << source.getName() << " cloned." << std::endl;
}

ScavTrap & ScavTrap::operator=(ScavTrap const & source)
{
	if (this != &source)
	{
		std::cout << "Cloned ScavTrap assigned with new atributes, ready to " \
		<< "fight!!" << std::endl;
		this->setName(source.getName());
		this->setHitPoints(source.getHitPoints());
		this->setEnergyPoints(source.getEnergyPoints());
		this->setAttackDamage(source.getAttackDamage());		
	}
	return (*this);
}

ScavTrap::~ScavTrap(void)
{
	std::cout << "ScavTrap " << this->getName();
	std::cout << " leaves the battlefield." << std::endl;
}

/****************************** MEMBER FUNCTIONS ******************************/

void	ScavTrap::attack(std::string const & target)
{
	if (this->getHitPoints() < 1)
		std::cout << "ScavTrap " << this->getName() << " cannot attack " << target \
		<< ", no hit points left.";
	else if (this->getEnergyPoints() < 1)
		std::cout << "ScavTrap " << this->getName() << " cannot attack " << target \
		<< ", no energy points left.";
	else
	{
		std::cout << "ScavTrap " << this->getName() << " attacks " << target << \
		", causing " << this->getAttackDamage() << " damage points.";
		this->setEnergyPoints(this->getEnergyPoints() - 1);
		
	}
	std::cout << std::endl;
}

void	ScavTrap::guardGate(void)
{
	std::cout << "ScavTrap " << this->getName() << " is now in Gate keeper mode.";
	std::cout << std::endl;
}

/***************************** NON-MEMBER FUNCTIONS ***************************/

std::ostream & operator<<(std::ostream & stream, ScavTrap const & source)
{
	stream << "Name:[" << source.getName() << "]  Hit points:[" << \
	source.getHitPoints() << "]  Energy points:[" << source.getEnergyPoints() \
	<< "]  Damage points:[" << source.getAttackDamage() << "]";
	return (stream);
}
