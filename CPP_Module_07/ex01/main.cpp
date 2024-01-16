/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesuserr <jesuserr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 00:23:41 by jesuserr          #+#    #+#             */
/*   Updated: 2023/12/31 12:37:16 by jesuserr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "iter.hpp"

int main(void)
{
	int arrayInt[] = {1, 2, 3, 4, 5};
	::iter(arrayInt, 5, print);				// :: means global scope
	std::cout << "\n";
	::iter(arrayInt, 5, twoTimes);
	::iter(arrayInt, 5, print);
	std::cout << "\n";
	
	char arrayChar[] = {'a', 'b', 'c', 'd', 'e'};
	::iter(arrayChar, 5, print);
	std::cout << "\n";
	
	std::string arrayString[] = {"Hello", "how", "are", "you", "?"};
	::iter(arrayString, 5, print);
	std::cout << "\n";
	
	float arrayFloat[] = {1.1, 2.2, 3.3, 4.4, 5.5};
	::iter(arrayFloat, 5, print);
	std::cout << "\n";
	::iter(arrayFloat, 5, twoTimes);
	::iter(arrayFloat, 5, print);
	std::cout << "\n";
	
	void *arrayVoid[] = {&arrayInt, &arrayChar, &arrayString, &arrayFloat};
	::iter(arrayVoid, 4, print);	
	std::cout << "\n";
	
	return 0;
}
