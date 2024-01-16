/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesuserr <jesuserr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 23:03:44 by jesuserr          #+#    #+#             */
/*   Updated: 2024/01/03 01:02:54 by jesuserr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "easyfind.hpp"
#include <vector>
#include <list>

int main(void)
{
	std::system("clear");
	
	std::vector<int> vec;
	for (int i = 1; i <= 5; i++)	// Fill vector with values from 1 to 5
		vec.push_back(i);
	try
	{
		std::cout << "Searching in int vector.\n";
		::easyfind(vec, 3);			// Value found
		::easyfind(vec, 12);		// Exception thrown
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	std::list<int> lst;
	for (int i = 6; i <= 10; i++)	// Fill list with values from 6 to 10
		lst.push_back(i);
	try
	{
		std::cout << "\nSearching in int list.\n";
		::easyfind(lst, 7);			// Value found
		::easyfind(lst, 15);		// Exception thrown
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	std::vector<char> vec_char;
	vec_char.push_back('a');		// Fill vector with values from 'a' to 'e'
	vec_char.push_back('b');
	vec_char.push_back('c');
	vec_char.push_back('d');
	vec_char.push_back('e');
	try
	{
		std::cout << "\nSearching in char vector.\n";
		::easyfind(vec_char, 'a');	// Value found
		::easyfind(vec_char, 'A');	// Exception thrown
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
		
	return 0;
}
