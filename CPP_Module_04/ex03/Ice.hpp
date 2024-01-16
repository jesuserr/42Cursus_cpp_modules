/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesuserr <jesuserr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 12:32:11 by jesuserr          #+#    #+#             */
/*   Updated: 2023/12/02 12:21:56 by jesuserr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_H
# define ICE_H

# include "AMateria.hpp"

class Ice : public AMateria
{
    public:
        Ice(void);
        Ice(Ice const & source);
        Ice & operator=(Ice const & source);
        ~Ice(void);
        
        AMateria*	clone(void) const;
};

#endif
