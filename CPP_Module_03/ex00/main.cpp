/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesuserr <jesuserr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 18:45:03 by jesuserr          #+#    #+#             */
/*   Updated: 2023/10/28 19:46:05 by jesuserr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <stdlib.h>		//for system("clear") in Linux

void	print_stats(ClapTrap & p1, ClapTrap & p2)
{
	std::cout << std::endl;
	std::cout << p1 << std::endl;
	std::cout << p2 << std::endl;
	std::cout << std::endl;
}

int	main(void)
{
	system("clear");
	
	ClapTrap	clapTrapA("Goku");
	ClapTrap	clapTrapB(clapTrapA);
	
	clapTrapA.setAttackDamage(4);
	clapTrapB.setName("Vegeta");
	clapTrapB.setAttackDamage(4);
	
	print_stats(clapTrapA, clapTrapB);
		
	clapTrapA.attack(clapTrapB.getName());
	clapTrapB.takeDamage(clapTrapA.getAttackDamage());
	clapTrapB.attack(clapTrapA.getName());
	clapTrapA.takeDamage(clapTrapB.getAttackDamage());
	clapTrapA.attack(clapTrapB.getName());
	clapTrapB.takeDamage(clapTrapA.getAttackDamage());
	clapTrapB.attack(clapTrapA.getName());
	clapTrapA.takeDamage(clapTrapB.getAttackDamage());
	clapTrapA.attack(clapTrapB.getName());
	clapTrapB.takeDamage(clapTrapA.getAttackDamage());
	clapTrapB.attack(clapTrapA.getName());
		
	print_stats(clapTrapA, clapTrapB);	
	
	clapTrapA.setEnergyPoints(2);
	clapTrapA.beRepaired(10);
	clapTrapB.beRepaired(10);	
	clapTrapA.attack(clapTrapB.getName());
	clapTrapA.attack(clapTrapB.getName());
	clapTrapB.attack(clapTrapA.getName());
		
	print_stats(clapTrapA, clapTrapB);
		
	return (0);
}
