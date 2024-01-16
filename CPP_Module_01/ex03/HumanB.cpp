/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesuserr <jesuserr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 20:10:57 by jesuserr          #+#    #+#             */
/*   Updated: 2023/10/16 11:44:19 by jesuserr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name) : _nameB(name)
{
	std::cout << this->_nameB << " emerges with bare hands" << std::endl;
	return;
}

HumanB::~HumanB(void)
{
	std::cout << this->_nameB << " has been destroyed" << std::endl;
	return;
}

void	HumanB::attack(void)
{
	std::cout << this->_nameB << " attacks with their ";
	std::cout << this->_weaponB->getType() << std::endl;
}

void	HumanB::setWeapon(Weapon& weapon)
{
	this->_weaponB = &weapon;
}
