/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesuserr <jesuserr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 13:21:13 by jesuserr          #+#    #+#             */
/*   Updated: 2024/01/02 01:27:01 by jesuserr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Array.hpp"

/********************************* MY MAIN ************************************/

int main()
{
	Array<int> a(5);
	Array<int> b;
	std::cout << "a size: " << a.size() << "\n";
	std::cout << "b size: " << b.size() << "\n";
	std::cout << "printing a..." << "\n" << a << "\n\n";
			
	std::cout << "filling a..." << "\n";
	for (unsigned int i = 0; i < a.size(); i++)
		a[i] = i;
	std::cout << "printing a..." << "\n" << a << "\n\n";
			
	b = a;
	Array<int> c(a);
	std::cout << "b size: " << b.size() << "\n";
	std::cout << "c size: " << c.size() << "\n\n";
		
	std::cout << "adding 1 to each element of a..." << "\n";
	for (unsigned int i = 0; i < a.size(); i++)
		a[i] = i + 1;
	std::cout << "printing a, b and c..." << "\n";
	std::cout << a << "\n" << b << "\n" << c << "\n\n";
			
	try
	{
		std::cout << a[5] << "\n";
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	try
	{
		std::cout << a[-1] << "\n";
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	std::cout << "\n";
	const Array<int> d(a);
	std::cout << "d size: " << d.size() << "\n";
	std::cout << "d pos. 0: " << d[0] << "\n\n";
	//d[0] = 1;	//not allowed since d is const
	
	Array<std::string> e(3);
	std::cout << "e size: " << e.size() << "\n";
	std::cout << "filling e..." << "\n";
	e[0] = "hello";
	e[1] = "world";
	e[2] = "!";
	std::cout << "printing e..." << "\n" << e << "\n";

	std::cout << "\n";
	return 0;
}

/******************************* SUBJECT MAIN  ********************************/

/* #define MAX_VAL 750
#include <cstdlib>
int main(int, char**)
{
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    //SCOPE
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    delete [] mirror;//
    return 0;
} */
