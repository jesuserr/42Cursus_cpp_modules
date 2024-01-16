/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesuserr <jesuserr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 19:17:27 by jesuserr          #+#    #+#             */
/*   Updated: 2023/11/17 20:38:58 by jesuserr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_H
# define SCAVTRAP_H

# include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
	public:
		ScavTrap(void);
		ScavTrap(std::string const name);
		ScavTrap(ScavTrap const & source);
		ScavTrap & operator=(ScavTrap const & source);
		~ScavTrap(void);
		
		void	attack(std::string const & target);
		void	guardGate(void);
};

std::ostream & operator<<(std::ostream & stream, ScavTrap const & source);

#endif
