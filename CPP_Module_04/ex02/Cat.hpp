/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesuserr <jesuserr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 12:14:49 by jesuserr          #+#    #+#             */
/*   Updated: 2023/11/27 18:08:49 by jesuserr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_H
# define CAT_H

# include "AAnimal.hpp"
# include "Brain.hpp"

class Cat : public AAnimal
{
	private:
		Brain*	_brain;
	public:
		Cat(void);
		Cat(Cat const & source);
		Cat & operator=(Cat const & source);
		virtual ~Cat(void);
		
		void	makeSound(void) const;
		Brain*	getBrain(void) const;
};

#endif
