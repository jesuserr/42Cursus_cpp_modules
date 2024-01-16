/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesuserr <jesuserr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 18:45:03 by jesuserr          #+#    #+#             */
/*   Updated: 2023/11/17 22:48:25 by jesuserr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include <stdlib.h>		//for system("clear") in Linux

void	print_stats(ScavTrap & p1, ScavTrap & p2)
{
	std::cout << std::endl;
	std::cout << p1 << std::endl;
	std::cout << p2 << std::endl;
	std::cout << std::endl;
}

int	main(void)
{
	system("clear");
	
	ScavTrap	scavTrapA("Goku");
	ScavTrap	scavTrapB(scavTrapA);
	
	print_stats(scavTrapA, scavTrapB);
	
	scavTrapB.setName("Vegeta");
		
	print_stats(scavTrapA, scavTrapB);
		
	scavTrapA.attack(scavTrapB.getName());
	scavTrapB.takeDamage(scavTrapA.getAttackDamage());
	scavTrapB.attack(scavTrapA.getName());
	scavTrapA.takeDamage(scavTrapB.getAttackDamage());
	scavTrapA.attack(scavTrapB.getName());
	scavTrapB.takeDamage(scavTrapA.getAttackDamage());
	scavTrapB.attack(scavTrapA.getName());
	scavTrapA.takeDamage(scavTrapB.getAttackDamage());
	scavTrapA.attack(scavTrapB.getName());
	scavTrapB.takeDamage(scavTrapA.getAttackDamage());
	scavTrapB.attack(scavTrapA.getName());
	scavTrapA.takeDamage(scavTrapB.getAttackDamage());
	scavTrapA.attack(scavTrapB.getName());
	scavTrapB.takeDamage(scavTrapA.getAttackDamage());
	scavTrapB.attack(scavTrapA.getName());
	scavTrapA.takeDamage(scavTrapB.getAttackDamage());
	scavTrapA.attack(scavTrapB.getName());
	scavTrapB.takeDamage(scavTrapA.getAttackDamage());
	scavTrapB.attack(scavTrapA.getName());
				
	print_stats(scavTrapA, scavTrapB);	
	
	scavTrapA.beRepaired(50);
	scavTrapB.beRepaired(50);
	scavTrapA.attack(scavTrapB.getName());
	scavTrapB.takeDamage(scavTrapA.getAttackDamage());
	scavTrapB.attack(scavTrapA.getName());
		
	print_stats(scavTrapA, scavTrapB);
	
	scavTrapA.guardGate();
	scavTrapB.guardGate();
	
	return (0);
}
