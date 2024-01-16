/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesuserr <jesuserr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 12:32:16 by jesuserr          #+#    #+#             */
/*   Updated: 2023/12/02 20:18:04 by jesuserr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_H
# define CURE_H

# include "AMateria.hpp"

class Cure : public AMateria
{
    public:
        Cure(void);
        Cure(Cure const & source);
        Cure & operator=(Cure const & source);
        ~Cure(void);
        
        AMateria*	clone(void) const;
};

#endif
