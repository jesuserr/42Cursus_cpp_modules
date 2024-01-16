/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesuserr <jesuserr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 21:45:42 by jesuserr          #+#    #+#             */
/*   Updated: 2023/10/16 11:29:23 by jesuserr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <stdlib.h>		//for system("clear") in Linux

int	main(void)
{
	Zombie*	zombie_horde;
	int		num_zombies;
		
	std::system("clear");
	num_zombies = 5;
	zombie_horde = zombieHorde(num_zombies, "zombie_heap");
	if (!zombie_horde)
		return (1);
	while (--num_zombies >= 0)
		zombie_horde[num_zombies].announce();
	delete[] zombie_horde;
	return (0);
}
