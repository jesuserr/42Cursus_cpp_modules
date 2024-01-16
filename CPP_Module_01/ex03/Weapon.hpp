/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesuserr <jesuserr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 20:26:25 by jesuserr          #+#    #+#             */
/*   Updated: 2023/10/16 11:36:25 by jesuserr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	WEAPON_H
# define WEAPON_H

#include <iostream>

class Weapon
{
	private:
		std::string _type;
	public:
		Weapon(std::string new_type);
		~Weapon(void);
		std::string const & getType(void) const;
		void	setType(std::string new_type);
};

#endif
