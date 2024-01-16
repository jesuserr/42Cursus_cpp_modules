/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesuserr <jesuserr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 08:39:14 by jesuserr          #+#    #+#             */
/*   Updated: 2023/10/16 11:37:37 by jesuserr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string new_type) : _type(new_type)
{
	std::cout << "Weapon "<< this->_type << " has been crafted" << std::endl;
	return;
}

Weapon::~Weapon(void)
{
	std::cout << "Weapon " << this->_type << " has been destroyed" << std::endl;
	return;
}

std::string const & Weapon::getType(void) const
{
	return (this->_type);
}

void	Weapon::setType(std::string new_type)
{
	this->_type = new_type;
}
