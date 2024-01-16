/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesuserr <jesuserr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 18:45:03 by jesuserr          #+#    #+#             */
/*   Updated: 2023/11/18 11:39:42 by jesuserr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include <stdlib.h>		//for system("clear") in Linux

void	print_stats(FragTrap & p1, FragTrap & p2)
{
	std::cout << std::endl;
	std::cout << p1 << std::endl;
	std::cout << p2 << std::endl;
	std::cout << std::endl;
}

int	main(void)
{
	system("clear");
	
	FragTrap	fragTrapA("Goku");
	FragTrap	fragTrapB(fragTrapA);
	
	print_stats(fragTrapA, fragTrapB);
	
	fragTrapB.setName("Vegeta");
		
	print_stats(fragTrapA, fragTrapB);
		
	fragTrapA.attack(fragTrapB.getName());
	fragTrapB.takeDamage(fragTrapA.getAttackDamage());
	fragTrapB.attack(fragTrapA.getName());
	fragTrapA.takeDamage(fragTrapB.getAttackDamage());
	fragTrapA.attack(fragTrapB.getName());
	fragTrapB.takeDamage(fragTrapA.getAttackDamage());
	fragTrapB.attack(fragTrapA.getName());
	fragTrapA.takeDamage(fragTrapB.getAttackDamage());
	fragTrapA.attack(fragTrapB.getName());
	fragTrapB.takeDamage(fragTrapA.getAttackDamage());
	fragTrapB.attack(fragTrapA.getName());
	fragTrapA.takeDamage(fragTrapB.getAttackDamage());
	fragTrapA.attack(fragTrapB.getName());
	fragTrapB.takeDamage(fragTrapA.getAttackDamage());
	fragTrapB.attack(fragTrapA.getName());
	
				
	print_stats(fragTrapA, fragTrapB);	
	
	fragTrapA.beRepaired(50);
	fragTrapB.beRepaired(50);
	fragTrapA.attack(fragTrapB.getName());
	fragTrapB.takeDamage(fragTrapA.getAttackDamage());
	fragTrapB.attack(fragTrapA.getName());
		
	print_stats(fragTrapA, fragTrapB);
	
	fragTrapA.highFivesGuys();
	fragTrapB.highFivesGuys();
	
	return (0);
}
