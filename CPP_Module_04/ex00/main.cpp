/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesuserr <jesuserr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 12:31:29 by jesuserr          #+#    #+#             */
/*   Updated: 2023/11/24 14:07:25 by jesuserr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main(void)
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	const WrongAnimal* wrong = new WrongCat();

	std::cout << meta->getType() << "." << std::endl;
	std::cout << j->getType() << "." << std::endl;
	std::cout << i->getType() << "." << std::endl;
	std::cout << wrong->getType() << "." << std::endl;
	meta->makeSound();
	j->makeSound();
	i->makeSound();
	wrong->makeSound();
	delete(wrong);
	delete(i);
	delete(j);
	delete(meta);
	return (0);
}
