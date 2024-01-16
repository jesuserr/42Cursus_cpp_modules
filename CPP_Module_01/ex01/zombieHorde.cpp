/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesuserr <jesuserr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 12:10:46 by jesuserr          #+#    #+#             */
/*   Updated: 2023/10/16 11:29:49 by jesuserr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie*	zombieHorde(int N, std::string name)
{
	Zombie*	horde;
		
	if (N < 1)
	{
		std::cout << "Not enough zombies for a horde" << std::endl;
		return (NULL);
	}
	try
	{
		horde = new Zombie[N];
		//throw std::bad_alloc();
	}
	catch (const std::bad_alloc& ba)
	{
		std::cerr << "Error: memory allocation failed " << ba.what() << std::endl;
		return (NULL);
	}
	while (--N >= 0)
		horde[N].set_name(name);
	return (horde);
}
