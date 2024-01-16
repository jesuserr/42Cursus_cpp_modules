/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesuserr <jesuserr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 12:27:04 by jesuserr          #+#    #+#             */
/*   Updated: 2023/11/24 11:45:12 by jesuserr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_H
# define ANIMAL_H

# include <iostream>

class Animal
{
	protected:
		std::string		_type;
	public:
		Animal(void);
		Animal(std::string const name);
		Animal(Animal const & source);
		Animal & operator=(Animal const & source);
		virtual ~Animal(void);
		
		std::string		getType(void) const;
		virtual void	makeSound(void) const;
};

#endif
