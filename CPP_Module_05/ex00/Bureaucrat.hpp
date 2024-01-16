/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesuserr <jesuserr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 22:33:27 by jesuserr          #+#    #+#             */
/*   Updated: 2023/12/12 23:23:59 by jesuserr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_H
# define BUREAUCRAT_H

# include <iostream>

class  Bureaucrat
{
	private:
		std::string const	_name;
		int					_grade;
		void				checkGrade(void) const;
	public:
		Bureaucrat(void);
		Bureaucrat(std::string const name, int grade);
		Bureaucrat(Bureaucrat const & source);
		Bureaucrat & operator=(Bureaucrat const & source);
		~Bureaucrat(void);
		
		void	incrementGrade(void);
		void	decrementGrade(void);
		
		std::string		getName(void) const;
		int				getGrade(void) const;
		
		class GradeTooHighException: public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
		class GradeTooLowException: public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
};

std::ostream & operator<<(std::ostream & stream, Bureaucrat const & source);

#endif
