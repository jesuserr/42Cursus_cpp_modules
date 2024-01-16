/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesuserr <jesuserr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 21:45:42 by jesuserr          #+#    #+#             */
/*   Updated: 2023/10/16 11:27:25 by jesuserr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	Zombie*	zombie_heap;
	
	zombie_heap = newZombie("Zombie_Heap");
	zombie_heap->announce();
	delete zombie_heap;
	randomChump("Zombie_Stack");
	return (0);
}
