/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesuserr <jesuserr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 18:05:34 by jesuserr          #+#    #+#             */
/*   Updated: 2023/11/27 18:06:16 by jesuserr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AANIMAL_H
# define AANIMAL_H

# include <iostream>

class AAnimal
{
	protected:
		std::string		_type;
	public:
		AAnimal(void);
		AAnimal(std::string const name);
		AAnimal(AAnimal const & source);
		AAnimal & operator=(AAnimal const & source);
		virtual ~AAnimal(void);
		
		std::string		getType(void) const;
		virtual void	makeSound(void) const = 0;
};

#endif
