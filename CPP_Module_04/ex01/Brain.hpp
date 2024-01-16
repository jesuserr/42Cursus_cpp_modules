/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesuserr <jesuserr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 14:20:08 by jesuserr          #+#    #+#             */
/*   Updated: 2023/11/27 11:49:37 by jesuserr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_H
# define BRAIN_H

# include <iostream>

class Brain
{
	private:
		std::string		_ideas[100];
	public:
		Brain(void);
		Brain(Brain const & source);
		Brain & operator=(Brain const & source);
		~Brain(void);

		std::string*	getIdeas(void);
		std::string		getIdea(int i) const;
		void			setIdea(int i, std::string idea);
};

#endif
