/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesuserr <jesuserr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 20:48:27 by jesuserr          #+#    #+#             */
/*   Updated: 2023/11/19 22:54:09 by jesuserr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

/*********************** ORTHODOX CANONICAL CLASS FORM ************************/

DiamondTrap::DiamondTrap(void) : ClapTrap("Unnamed_clap_name")
{
	this->_name = "Unnamed";
	std::cout << "Unnamed DiamondTrap, ready to fight!!" << std::endl;
	this->setHitPoints(this->FragTrap::_hitPointsDef);
	this->setEnergyPoints(this->ScavTrap::_energyPointsDef);
	this->setAttackDamage(this->FragTrap::_attackDamageDef);
}

DiamondTrap::DiamondTrap(std::string const name) : ClapTrap(name + "_clap_name")
{
	this->_name = name;
	std::cout << "DiamondTrap " << this->_name << ", ready to fight!!" << std::endl;
	this->setHitPoints(this->FragTrap::_hitPointsDef);
	this->setEnergyPoints(this->ScavTrap::_energyPointsDef);
	this->setAttackDamage(this->FragTrap::_attackDamageDef);
}

DiamondTrap::DiamondTrap(DiamondTrap const & source) : ClapTrap(source), \
FragTrap(source), ScavTrap(source)
{
	std::cout << "DiamondTrap " << source.getName() << " cloned." << std::endl;
}

DiamondTrap & DiamondTrap::operator=(DiamondTrap const & source)
{
	if (this != &source)
	{
		std::cout << "Cloned DiamondTrap assigned with new atributes, ready to " \
		<< "fight!!" << std::endl;
		this->_name = source.getName();
		this->setHitPoints(source.getHitPoints());
		this->setEnergyPoints(source.getEnergyPoints());
		this->setAttackDamage(source.getAttackDamage());		
	}
	return (*this);
}

DiamondTrap::~DiamondTrap(void)
{
	if (this->_name == "Unnamed")
		std::cout << "Unnamed DiamondTrap";
	else
		std::cout << "DiamondTrap " << this->_name;
	std::cout << " leaves the battlefield." << std::endl;
}

/****************************** MEMBER FUNCTIONS ******************************/

void	DiamondTrap::whoAmI(void)
{
 	if (this->_name ==  "Unnamed")
		std::cout << "Unnamed DiamondTrap is named: " << ClapTrap::getName();
	else
		std::cout << "DiamondTrap " << this->_name << " is named: " << ClapTrap::getName();
	std::cout << "." << std::endl;
}

/***************************** NON-MEMBER FUNCTIONS ***************************/

std::ostream & operator<<(std::ostream & stream, DiamondTrap const & source)
{
	stream << "Name:[" << source.getName() << "]  Hit points:[" << \
	source.getHitPoints() << "]  Energy points:[" << source.getEnergyPoints() \
	<< "]  Damage points:[" << source.getAttackDamage() << "]";
	return (stream);
}
