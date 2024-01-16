/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesuserr <jesuserr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 18:45:03 by jesuserr          #+#    #+#             */
/*   Updated: 2023/11/18 22:38:15 by jesuserr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"
#include <stdlib.h>		//for system("clear") in Linux

void	print_stats(DiamondTrap & p1, DiamondTrap & p2)
{
	std::cout << std::endl;
	std::cout << p1 << std::endl;
	std::cout << p2 << std::endl;
	std::cout << std::endl;
}

int	main(void)
{
	system("clear");
	
	DiamondTrap	diamondTrapA("Goku");
	DiamondTrap	diamondTrapB("Vegeta");
		
	print_stats(diamondTrapA, diamondTrapB);
	
	diamondTrapA.attack(diamondTrapB.getName());
	diamondTrapB.takeDamage(diamondTrapA.getAttackDamage());
	diamondTrapB.attack(diamondTrapA.getName());
	diamondTrapA.takeDamage(diamondTrapB.getAttackDamage());
	diamondTrapA.attack(diamondTrapB.getName());
	diamondTrapB.takeDamage(diamondTrapA.getAttackDamage());
	diamondTrapB.attack(diamondTrapA.getName());
	diamondTrapA.takeDamage(diamondTrapB.getAttackDamage());
	diamondTrapA.attack(diamondTrapB.getName());
	diamondTrapB.takeDamage(diamondTrapA.getAttackDamage());
	diamondTrapB.attack(diamondTrapA.getName());
	diamondTrapA.takeDamage(diamondTrapB.getAttackDamage());
	diamondTrapA.attack(diamondTrapB.getName());
	diamondTrapB.takeDamage(diamondTrapA.getAttackDamage());
	diamondTrapB.attack(diamondTrapA.getName());

						
	print_stats(diamondTrapA, diamondTrapB);	
	
	diamondTrapA.beRepaired(50);
	diamondTrapB.beRepaired(50);
	diamondTrapA.attack(diamondTrapB.getName());
	diamondTrapB.takeDamage(diamondTrapA.getAttackDamage());
	diamondTrapB.attack(diamondTrapA.getName());
		
	print_stats(diamondTrapA, diamondTrapB);
	
	diamondTrapA.whoAmI();
	diamondTrapB.whoAmI();
	
	return (0);
}
