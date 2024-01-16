/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesuserr <jesuserr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 13:48:08 by jesuserr          #+#    #+#             */
/*   Updated: 2023/11/24 13:49:12 by jesuserr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONG_ANIMAL_H
# define WRONG_ANIMAL_H

# include <iostream>

class WrongAnimal
{
	protected:
		std::string		_type;
	public:
		WrongAnimal(void);
		WrongAnimal(std::string const name);
		WrongAnimal(WrongAnimal const & source);
		WrongAnimal & operator=(WrongAnimal const & source);
		virtual ~WrongAnimal(void);
		
		std::string	getType(void) const;
		void		makeSound(void) const;
};

#endif
