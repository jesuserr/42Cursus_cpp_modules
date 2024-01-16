/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesuserr <jesuserr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 12:09:53 by jesuserr          #+#    #+#             */
/*   Updated: 2023/10/16 12:37:33 by jesuserr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl()
{
	std::cout << "Harl enters the restaurant" << std::endl;
	return;
}

Harl::~Harl()
{
	std::cout << "Harl leaves the restaurant" << std::endl;
	return;
}

void	Harl::_debug(void)
{
	std::cout << BLUE << "[ DEBUG ]" << DEFAULT << std::endl;
	std::cout << "I love having extra bacon for my ";
	std::cout << "7XL-double-cheese-triple-pickle-specialketchup burger.";
	std::cout << std::endl << "I really do!" << std::endl;
}

void	Harl::_info(void)
{
	std::cout << GREEN << "[ INFO ]" << DEFAULT << std::endl;
	std::cout << "I cannot believe adding extra bacon costs more money.";
	std::cout << std::endl << "You didn’t put enough bacon in my burger!";
	std::cout << " If you did, I wouldn’t be asking for more!" << std::endl;
}

void	Harl::_warning(void)
{
	std::cout << YELLOW << "[ WARNING ]" << DEFAULT << std::endl;
	std::cout << "I think I deserve to have some extra bacon for free.";
	std::cout << std::endl << "I’ve been coming for years whereas you started";
	std::cout << " working here since last month." << std::endl;
}

void	Harl::_error(void)
{
	std::cout << RED << "[ ERROR ]" << DEFAULT << std::endl;
	std::cout << "This is unacceptable! I want to speak to the manager now.";
	std::cout << std::endl;
}

void	Harl::complain(std::string level)
{
	void		(Harl::*funcPtr[4])(void);
	std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	int			i;
	
	funcPtr[0] = &Harl::_debug;
	funcPtr[1] = &Harl::_info;
	funcPtr[2] = &Harl::_warning;
	funcPtr[3] = &Harl::_error;
	i = 0;
	while (i < 4 && level != levels[i])
		i++;
	if (i < 4)
		(this->*funcPtr[i])();
	else
	{
		std::cout << "[ Probably complaining about insignificant problems ]";
		std::cout << std::endl;
	}
	return;
}
