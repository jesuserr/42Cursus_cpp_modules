/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesuserr <jesuserr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 12:44:19 by jesuserr          #+#    #+#             */
/*   Updated: 2023/12/15 21:28:24 by jesuserr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_H
# define AFORM_H

# include "Bureaucrat.hpp"

class	Bureaucrat;

class	AForm
{
	private:
		std::string const	_formName;
		bool				_isSigned;
		int const			_gradeToSign;
		int const			_gradeToExec;
		std::string const	_target;
		void				checkGradeForm(void) const;
	public:
		AForm(void);
		AForm(std::string const name, int const gts, int const gte, std::string const target);
		AForm(AForm const & source);
		AForm & operator=(AForm const & source);
		virtual ~AForm(void);
		
		void			beSigned(Bureaucrat const &bureaucrat);
		virtual void	execute(Bureaucrat const & executor) const = 0;
		void			checkExecute(Bureaucrat const & executor) const;
				
		std::string		getFormName(void) const;
		bool			getIsSigned(void) const;
		int				getGradeToSign(void) const;
		int				getGradeToExec(void) const;
		std::string		getTarget(void) const;
				
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
		class FormNotSignedException: public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
	protected:
		void	setSignature(bool sign);
};

std::ostream & operator<<(std::ostream & stream, AForm const & source);

#endif
