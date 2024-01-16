/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesuserr <jesuserr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 11:18:57 by jesuserr          #+#    #+#             */
/*   Updated: 2023/10/21 14:53:43 by jesuserr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_H
# define FIXED_H

# include <iostream>
# include <cmath>

class Fixed
{
	private:
		int					_fp_value;
		static int const	_fraction_bits;
	public:
		Fixed(void);
		Fixed(int const value);
		Fixed(float const value);
		Fixed(Fixed const & source);
		~Fixed(void);
		
		Fixed & operator=(Fixed const & source);
		Fixed 	operator*(Fixed const & source);
		Fixed 	operator+(Fixed const & source);
		Fixed 	operator-(Fixed const & source);
		Fixed 	operator/(Fixed const & source);

		bool	operator>(Fixed const & source) const;
		bool	operator<(Fixed const & source) const;
		bool	operator==(Fixed const & source) const;
		bool	operator!=(Fixed const & source) const;
		bool	operator>=(Fixed const & source) const;
		bool	operator<=(Fixed const & source) const;

		Fixed 	operator++(void);
		Fixed 	operator++(int);
		Fixed 	operator--(void);
		Fixed 	operator--(int);

		static Fixed & min(Fixed & a, Fixed & b);
		static Fixed & max(Fixed & a, Fixed & b);
		static Fixed const & min(Fixed const & a, Fixed const & b);
		static Fixed const & max(Fixed const & a, Fixed const & b);

		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		float	toFloat(void) const;
		int		toInt(void) const;		
};

std::ostream & operator<<(std::ostream & stream, Fixed const & source);

#endif
