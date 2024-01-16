/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesuserr <jesuserr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 13:40:58 by jesuserr          #+#    #+#             */
/*   Updated: 2023/12/16 13:19:26 by jesuserr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_H
# define SHRUBBERYCREATIONFORM_H

# include "AForm.hpp"
# include <fstream>

class	ShrubberyCreationForm : public AForm
{
    public:
		ShrubberyCreationForm(void);
		ShrubberyCreationForm(std::string const target);
		ShrubberyCreationForm(ShrubberyCreationForm const & source);
		ShrubberyCreationForm & operator=(ShrubberyCreationForm const & source);
		~ShrubberyCreationForm(void);
		
		void    execute(Bureaucrat const & executor) const;
};

#endif
