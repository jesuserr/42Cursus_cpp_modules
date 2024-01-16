/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesuserr <jesuserr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 10:55:43 by jesuserr          #+#    #+#             */
/*   Updated: 2024/01/11 20:33:24 by jesuserr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include "PmergeMe.hpp"

int main(int argc, char** argv)
{
	//system("clear");
	try
	{
		PmergeMe dataToSort;
		dataToSort.sortNumbers(argc, argv);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
		return (EXIT_FAILURE);
	}		
	return (EXIT_SUCCESS);
}
