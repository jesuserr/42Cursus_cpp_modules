/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesuserr <jesuserr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 12:31:29 by jesuserr          #+#    #+#             */
/*   Updated: 2023/11/27 18:44:27 by jesuserr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int	main(void)
{
	/*********************** SUBJECT TEST ************************/
	const AAnimal* j = new Dog();
	const AAnimal* i = new Cat();
	delete j;
	delete i;

	/*********************** SUBJECT TEST ************************/
	AAnimal*   animals[4];

	animals[0] = new Dog();
	animals[1] = new Cat();
	animals[2] = new Dog();
	animals[3] = new Cat();
	for (int i = 0; i < 4; i++)
		animals[i]->makeSound();
	for (int i = 0; i < 4; i ++)
		delete animals[i];
		
	/********************* DEEP COPIES TEST **********************/
	Cat*	cat_even = new Cat();

	for (int i = 0; i < 100; i += 2)
		cat_even->getBrain()->setIdea(i, "I am a cat with even ideas");

	Cat*	cat_all = new Cat(*cat_even);

	for (int i = 1; i < 100; i += 2)
		cat_all->getBrain()->setIdea(i, "I am a cat with odd ideas too");
	std::cout << std::endl;

	std::cout << cat_all->getBrain()->getIdeas() << std::endl;
	std::cout << cat_even->getBrain()->getIdeas() << std::endl;

	for (int i = 0; i < 100; i++)
		std::cout << "Idea: " << i << " - " << cat_even->getBrain()->getIdea(i) \
		<< std::endl;
	std::cout << std::endl;
	for (int i = 0; i < 100; i++)
		std::cout << "Idea: " << i << " - " << cat_all->getBrain()->getIdea(i) \
		<< std::endl;
	std::cout << std::endl;

	delete cat_all;
	delete cat_even;

	return (0);
}
