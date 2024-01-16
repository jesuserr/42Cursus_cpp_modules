/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesuserr <jesuserr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 14:13:23 by jesuserr          #+#    #+#             */
/*   Updated: 2023/12/03 12:15:40 by jesuserr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_H
# define CHARACTER_H

# include "ICharacter.hpp"

class Character : public ICharacter
{
	private:
		std::string		_name;
		AMateria* 		_inventory[4];
		int 			_count;
	public:
		Character(void);
		Character(std::string const & type);
		Character(Character const & source);
		Character & operator=(Character const & source);
		~Character(void);
		
		std::string const & getName() const;
		void equip(AMateria* m);
		void unequip(int idx);
		void use(int idx, ICharacter& target);
		
		void printMaterias(void) const;		//tester
};

#endif
