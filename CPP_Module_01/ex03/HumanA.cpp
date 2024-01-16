/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesuserr <jesuserr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 10:16:41 by jesuserr          #+#    #+#             */
/*   Updated: 2023/10/16 11:43:33 by jesuserr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon& weapon) : _nameA(name),_weaponA(weapon)
{
	std::cout << this->_nameA << " emerges with ";
	std::cout << this->_weaponA.getType() << std::endl;	
	return;
}

HumanA::~HumanA(void)
{
	std::cout << this->_nameA << " has been destroyed" << std::endl;
	return;
}

void	HumanA::attack(void)
{
	std::cout << this->_nameA << " attacks with their ";
	std::cout << this->_weaponA.getType() << std::endl;
}
