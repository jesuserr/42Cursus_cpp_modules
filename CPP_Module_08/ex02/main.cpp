/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesuserr <jesuserr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 13:21:46 by jesuserr          #+#    #+#             */
/*   Updated: 2024/01/05 20:50:33 by jesuserr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "MutantStack.hpp"
#include <cstdlib>
#include <list>

int main(void)
{
 	system("clear");
	
	/************************ IMPROVED SUBJECT EXAMPLE ************************/
	
/* 	MutantStack<int> mstack;
	std::cout << "MutantStack size: " << mstack.size() << "\n";
		
	std::cout << "\nPushing 5 and 17 to MutantStack.\n";
	mstack.push(5);
	mstack.push(17);
	std::cout << "Top element of MutantStack: " << mstack.top() << "\n";
	std::cout << "MutantStack size: " << mstack.size() << "\n";
	
	std::cout << "\nPopping 17 from MutantStack.\n";	
	mstack.pop();
	std::cout << "Top element of MutantStack: " << mstack.top() << "\n";
	std::cout << "MutantStack size: " << mstack.size() << "\n";
	
	std::cout << "\nPushing 3, 5, 737 and 0 to MutantStack.\n";
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);
	std::cout << "Top element of MutantStack: " << mstack.top() << "\n";
	std::cout << "MutantStack size: " << mstack.size() << "\n";
	
	std::cout << "\nPrinting MutantStack using iterators.\n";
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	
	std::cout << "\nCopying MutantStack to new MutantStack_2.\n";
	MutantStack<int> mstack2(mstack);
	std::cout << "Printing new MutantStack_2 using iterators.\n";
	MutantStack<int>::iterator it2 = mstack2.begin();
	MutantStack<int>::iterator ite2 = mstack2.end();
	while (it2 != ite2)
		std::cout << *(it2++) << std::endl;
		
	std::cout << "\nAssigning values to new MutantStack_3.\n";
	MutantStack<int> mstack3;
	mstack3 = mstack;
	std::cout << "Printing new MutantStack_3 using iterators.\n";
	MutantStack<int>::iterator it3 = mstack3.begin();
	MutantStack<int>::iterator ite3 = mstack3.end();
	while (it3 != ite3)
		std::cout << *(it3++) << std::endl;
		
	std::cout << "\nSwapping MutantStack_2 and MutantStack_3.\n";
	std::cout << "Pushing 100 to MutantStack_2.\n";
	mstack2.push(100);
	std::cout << "Pushing 200 to MutantStack_3.\n";
	mstack3.push(200);
	swap(mstack2, mstack3);
	std::cout << "Top element of MutantStack_2: " << mstack2.top() << "\n";
	std::cout << "MutantStack_2 size: " << mstack2.size() << "\n";
	std::cout << "Top element of MutantStack_3: " << mstack3.top() << "\n";
	std::cout << "MutantStack_3 size: " << mstack3.size() << "\n";
	
	std::cout << "\nCopying MutantStack to std::stack.\n";
	std::stack<int> s(mstack);
	std::cout << "Top element of std::stack: " << s.top() << "\n";
	std::cout << "std::stack size: " << s.size() << "\n";
	
	std::cout << std::endl; */

	/************************ MY TESTS WITH PURE STACKS************************/
		
	/* std::stack<int> mstack;
	std::cout << mstack.empty() << "\n";
	std::cout << "Pushing 5 values to stack.\n";
	for (int i = 1; i <= 5; i++)
		mstack.push(i);
	std::cout << "Stack size: " << mstack.size() << "\n";
	std::cout << "Top value: " << mstack.top() << "\n";
	std::cout << "Popping 1 value from stack.\n";
	mstack.pop();
	std::cout << "Stack size: " << mstack.size() << "\n";
	std::cout << "Top value: " << mstack.top() << "\n";
	std::cout << mstack.empty() << "\n";
	} */
	
	/********************** SUBJECT EXAMPLE WITH A LIST ***********************/
	
	std::list<int> lst;
	
	std::cout << "List size: " << lst.size() << "\n";
		
	std::cout << "\nPushing 5 and 17 to list.\n";
	lst.push_back(5);
	lst.push_back(17);
	std::cout << "Top element of list: " << lst.back() << "\n";
	std::cout << "List size: " << lst.size() << "\n";
			
	std::cout << "\nPopping 17 from list.\n";
	lst.pop_back();
	std::cout << "Top element of list: " << lst.back() << "\n";
	std::cout << "List size: " << lst.size() << "\n";
	
	std::cout << "\nPushing 3, 5, 737 and 0 to list.\n";
	lst.push_back(3);
	lst.push_back(5);
	lst.push_back(737);
	lst.push_back(0);
	std::cout << "Top element of list: " << lst.back() << "\n";
	std::cout << "List size: " << lst.size() << "\n";
	
	std::cout << "\nPrinting list using iterators.\n";
	std::list<int>::iterator it = lst.begin();
	std::list<int>::iterator ite = lst.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	
	return 0;
}
