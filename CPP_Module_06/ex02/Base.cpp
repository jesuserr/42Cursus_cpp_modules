/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesuserr <jesuserr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 11:03:03 by jesuserr          #+#    #+#             */
/*   Updated: 2023/12/27 11:56:27 by jesuserr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base::~Base(void)
{
	//std::cout << "Base destroyed.\n";
}

/**************************** NON-MEMBER FUNCTIONS ****************************/

Base*	generate(void)
{
	switch(std::rand() % 3)
	{
		case 0:
			std::cout << "Class A instantiated.\n";
			return (new A);
		case 1:
			std::cout << "Class B instantiated.\n";
			return (new B);
		case 2:
			std::cout << "Class C instantiated.\n";
			return (new C);		
	}
	std::cout << "Error instantiating Class.\n";
	return (NULL);
}

void	identify(Base* p)
{
	if (dynamic_cast<A*>(p) != NULL)
		std::cout << "A\n";
	else if (dynamic_cast<B*>(p) != NULL)
		std::cout << "B\n";
	else if (dynamic_cast<C*>(p) != NULL)
		std::cout << "C\n";
	else
		std::cout << "Object type not identified.\n";
}

void	identify(Base& p)
{
	try
	{
		A &aux = dynamic_cast<A&>(p);
		static_cast<void>(aux);		
		std::cout << "A\n";
	}	
	catch(const std::exception& e)
	{
		try
		{
			B &aux = dynamic_cast<B&>(p);
			static_cast<void>(aux);
			std::cout << "B\n";
		}
		catch(const std::exception& e)
		{
			try
			{
				C &aux = dynamic_cast<C&>(p);
				static_cast<void>(aux);
				std::cout << "C\n";
			}
			catch(const std::exception& e)
			{
				std::cout << "Object type not identified.\n";
			}			
		}		
	}	
}
