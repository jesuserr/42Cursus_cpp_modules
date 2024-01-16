/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesuserr <jesuserr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 11:11:17 by jesuserr          #+#    #+#             */
/*   Updated: 2023/12/22 22:38:29 by jesuserr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_H
# define SCALARCONVERTER_H

# include <iostream>
# include <cstdlib>
# include <iomanip>
# include <climits>
# include <limits>

# define	IS_CHAR		0;
# define	IS_INT		1;
# define	IS_FLOAT	2;
# define	IS_DOUBLE	3;
# define	IS_ERROR	4;

class  ScalarConverter
{
	private:
		ScalarConverter(void);
		ScalarConverter(ScalarConverter const & source);
		ScalarConverter & operator=(ScalarConverter const & source);
		~ScalarConverter(void);
		
		static int	detectType(std::string str);
		static void	printCastFromChar(std::string str);
		static void	printCastFromInt(std::string str);
		static void	printCastFromFloat(std::string str);
		static void	printCastFromDouble(std::string str);
		
	public:
		static void convert(std::string const str);
		class InvalidFormat: public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
};

#endif
