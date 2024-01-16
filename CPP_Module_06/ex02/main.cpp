/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesuserr <jesuserr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 11:02:12 by jesuserr          #+#    #+#             */
/*   Updated: 2023/12/27 11:09:49 by jesuserr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include <iostream>
#include <iomanip>

int main(void)
{
	Base	*test_ok;
	Base	*test_ko;
	
	std::srand(std::time(0));
	std::cout << "** IDENTIFY TESTS (POINTERS & REFERENCES) ***\n";
	
	for (int i = 0; i < 5; i++)
	{
		test_ok = generate();
		std::cout << "\t(PTR) Pointed object identified as: ";
		identify(test_ok);
		std::cout << "\t(REF) Pointed object identified as: ";
		identify(*test_ok);
		delete test_ok;
	}
	
	std::cout << std::endl;
	std::cout << "****** IDENTIFY TESTS THAT SHOULD FAIL ******\n";
	
	test_ko = new Base;
	std::cout << "Empty Class Base instantiated.\n";
	std::cout << "\t";
	identify(test_ko);
	std::cout << "\t";
	identify(*test_ko);
	delete test_ko;

	test_ko = NULL;
	std::cout << "Empty pointer.\n";
	std::cout << "\t";
	identify(test_ko);

	return (0);
}
