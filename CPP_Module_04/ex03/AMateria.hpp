/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesuserr <jesuserr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 10:58:25 by jesuserr          #+#    #+#             */
/*   Updated: 2023/12/01 11:23:02 by jesuserr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_H
# define AMATERIA_H

# include <iostream>
# include "ICharacter.hpp"

class ICharacter;	// Forward declaration

class AMateria
{
	protected:
		std::string		_type;
	public:
		AMateria(void);
		AMateria(std::string const & type);
		AMateria(AMateria const & source);
		AMateria & operator=(AMateria const & source);
		virtual ~AMateria(void);
		
		std::string const & getType() const; 	//Returns the materia type
		
		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target);
};

#endif
