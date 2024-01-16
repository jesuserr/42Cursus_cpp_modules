/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesuserr <jesuserr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 20:42:24 by jesuserr          #+#    #+#             */
/*   Updated: 2023/11/18 21:09:15 by jesuserr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_H
# define DIAMONDTRAP_H

# include "FragTrap.hpp"
# include "ScavTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap
{
	private:
		std::string		_name;
	public:
		DiamondTrap(void);
		DiamondTrap(std::string const name);
		DiamondTrap(DiamondTrap const & source);
		DiamondTrap & operator=(DiamondTrap const & source);
		~DiamondTrap(void);
		
		void	whoAmI(void);
};

std::ostream & operator<<(std::ostream & stream, DiamondTrap const & source);

#endif
