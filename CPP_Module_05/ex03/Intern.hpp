/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesuserr <jesuserr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 13:32:37 by jesuserr          #+#    #+#             */
/*   Updated: 2023/12/17 17:41:54 by jesuserr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_H
# define INTERN_H

# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"

class	Intern
{
	private:
		AForm * createShrubberyCreationForm(std::string const target) const;
		AForm * createRobotomyRequestForm(std::string const target) const;
		AForm * createPresidentialPardonForm(std::string const target) const;
	public:
		Intern(void);
		Intern(Intern const & source);
		Intern & operator=(Intern const & source);
		~Intern(void);

		AForm * makeForm(std::string const formName, std::string const target) const;

		class FormNotCreatedException: public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
};

#endif
