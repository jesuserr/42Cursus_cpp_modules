/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesuserr <jesuserr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 11:07:18 by jesuserr          #+#    #+#             */
/*   Updated: 2023/11/19 23:11:19 by jesuserr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

/*********************** ORTHODOX CANONICAL CLASS FORM ************************/

FragTrap::FragTrap(void) : ClapTrap()
{
	std::cout << "Unnamed FragTrap ready to fight!!" << std::endl;
	this->setHitPoints(100);
	this->setEnergyPoints(100);
	this->setAttackDamage(30);
}

FragTrap::FragTrap(std::string const name) : ClapTrap(name)
{
	std::cout << "FragTrap " << this->getName() << ", ready to fight!!" << std::endl;
	this->setHitPoints(100);
	this->setEnergyPoints(100);
	this->setAttackDamage(30);
}

FragTrap::FragTrap(FragTrap const & source) : ClapTrap(source)
{
	std::cout << "FragTrap " << source.getName() << " cloned." << std::endl;
}

FragTrap & FragTrap::operator=(FragTrap const & source)
{
	if (this != &source)
	{
		std::cout << "Cloned FragTrap assigned with new atributes, ready to " \
		<< "fight!!" << std::endl;
		this->setName(source.getName());
		this->setHitPoints(source.getHitPoints());
		this->setEnergyPoints(source.getEnergyPoints());
		this->setAttackDamage(source.getAttackDamage());
	}
	return (*this);
}

FragTrap::~FragTrap(void)
{
	if (this->getName() == "Unnamed")
		std::cout << "Unnamed FragTrap";
	else
		std::cout << "FragTrap " << this->getName();
	std::cout << " leaves the battlefield." << std::endl;
}

/****************************** MEMBER FUNCTIONS ******************************/

void	FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap " << this->getName() << " expecting high fives...";
	std::cout << std::endl;
}

/***************************** NON-MEMBER FUNCTIONS ***************************/

std::ostream & operator<<(std::ostream & stream, FragTrap const & source)
{
	stream << "Name:[" << source.getName() << "]  Hit points:[" << \
	source.getHitPoints() << "]  Energy points:[" << source.getEnergyPoints() \
	<< "]  Damage points:[" << source.getAttackDamage() << "]";
	return (stream);
}
