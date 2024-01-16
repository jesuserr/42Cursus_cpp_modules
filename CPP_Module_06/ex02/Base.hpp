/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesuserr <jesuserr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 11:03:08 by jesuserr          #+#    #+#             */
/*   Updated: 2023/12/25 11:31:11 by jesuserr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_H
# define BASE_H

# include <iostream>
# include <ctime>
# include <cstdlib>

class  Base
{
	public:
		virtual ~Base(void);
};

Base*	generate(void);
void	identify(Base* p);
void	identify(Base& p);

#endif
