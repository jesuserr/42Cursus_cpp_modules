/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesuserr <jesuserr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 14:13:35 by jesuserr          #+#    #+#             */
/*   Updated: 2023/12/09 11:46:17 by jesuserr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_H
# define MATERIASOURCE_H

# include "IMateriaSource.hpp"
# include "AMateria.hpp"

class MateriaSource : public IMateriaSource
{
	private:
		AMateria*	_materia[4];
		int			_index;
	public:
		MateriaSource(void);
		MateriaSource(MateriaSource const & source);
		MateriaSource & operator=(MateriaSource const & source);
		~MateriaSource(void);
		
		void		learnMateria(AMateria* m);
		AMateria* 	createMateria(std::string const & type);
};

#endif
