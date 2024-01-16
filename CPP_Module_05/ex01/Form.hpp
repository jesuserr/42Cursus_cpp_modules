/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesuserr <jesuserr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 11:53:07 by jesuserr          #+#    #+#             */
/*   Updated: 2023/12/15 20:08:57 by jesuserr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_H
# define FORM_H

# include "Bureaucrat.hpp"

class	Bureaucrat;

class	Form
{
	private:
		std::string const	_formName;
		bool				_isSigned;
		int const			_gradeToSign;
		int const			_gradeToExec;
		void				checkGradeForm(void) const;
	public:
		Form(void);
		Form(std::string const name, int const gts, int const gte);
		Form(Form const & source);
		Form & operator=(Form const & source);
		~Form(void);
		
		void	beSigned(Bureaucrat const &bureaucrat);
				
		std::string		getFormName(void) const;
		bool			getIsSigned(void) const;		
		int				getGradeToSign(void) const;
		int				getGradeToExec(void) const;
		
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

std::ostream & operator<<(std::ostream & stream, Form const & source);

#endif
