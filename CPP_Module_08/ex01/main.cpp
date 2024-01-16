/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesuserr <jesuserr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 11:39:53 by jesuserr          #+#    #+#             */
/*   Updated: 2024/01/03 21:04:56 by jesuserr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Span.hpp"

int main(void)
{
	system("clear");
	
	/***************************** SUBJECT EXAMPLE ****************************/

	Span sp = Span(5);
	
	sp.addNumber(6);		
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	
	//sp.printVector();
	std::cout << "Shortest span: \t\t" << sp.shortestSpan() << '\n';
	std::cout << "Longest span: \t\t" << sp.longestSpan() << '\n';
			
	/******************************** MY TESTS ********************************/
		
	// Block to simulate exceptions due to less than 2 values
/* 	Span sp = Span(5);
 	try
	{
		sp.addNumber(6);
		sp.addNumber(3);
		std::cout << sp.shortestSpan() << '\n';
		std::cout << sp.longestSpan() << '\n';
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';		
	} */
	
	// Block to simulate exception due to full vector and check deep copies
/*	Span sp = Span(5);
 	try
	{
		sp.addNumber(6);
		sp.addNumber(3);
		Span sp2(sp);
		sp.addNumber(17);
		sp.addNumber(9);
		Span sp3;
		sp3 = sp;
		sp.addNumber(11);
		sp2.addNumber(1000);
		sp3.addNumber(2000);
		std::cout << '\n';
		sp.printVector();
		std::cout << '\n';
		sp2.printVector();
		std::cout << '\n';
		sp3.printVector();
		std::cout << '\n';
		//sp.addNumber(5);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	} */
	
	// Block to simulate fill of Span using a range of iterators
/* 	#define NUMBERS 10000
	srand(time(NULL));
	
	Span sp = Span(NUMBERS);
	std::vector<int> huge(NUMBERS);
	
	for (int i = 0; i < NUMBERS; i++)
		huge[i] = rand();
	
	try
	{
		sp.addRange(huge.begin(), huge.end());
		sp.printVector();
		std::cout << "Shortest span: \t\t" << sp.shortestSpan() << '\n';
		std::cout << "Longest span: \t\t" << sp.longestSpan() << '\n';
		std::cout << "Current size: \t\t" << sp.getCurrentSize() << '\n';
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	} */

	return 0;
}
