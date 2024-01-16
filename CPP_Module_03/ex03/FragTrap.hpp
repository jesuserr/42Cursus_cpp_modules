/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesuserr <jesuserr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 11:07:07 by jesuserr          #+#    #+#             */
/*   Updated: 2023/11/19 00:11:26 by jesuserr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_H
# define FRAGTRAP_H

# include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
{
	protected:
		static const unsigned int	_hitPointsDef = 100;
		static const unsigned int	_energyPointsDef = 100;
		static const unsigned int	_attackDamageDef = 30;			
	public:
		FragTrap(void);
		FragTrap(std::string const name);
		FragTrap(FragTrap const & source);
		FragTrap & operator=(FragTrap const & source);
		~FragTrap(void);
		
		void	highFivesGuys(void);
};

std::ostream & operator<<(std::ostream & stream, FragTrap const & source);

#endif
