/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesuserr <jesuserr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 20:39:53 by jesuserr          #+#    #+#             */
/*   Updated: 2023/10/16 11:43:53 by jesuserr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_H
# define HUMANA_H

#include "Weapon.hpp"

class HumanA
{
	private:
		std::string	_nameA;
		Weapon&		_weaponA;
	public:
		HumanA(std::string name, Weapon& weapon);
		~HumanA(void);
		void	attack(void);
};

#endif




