/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesuserr <jesuserr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 11:18:57 by jesuserr          #+#    #+#             */
/*   Updated: 2023/10/21 15:20:29 by jesuserr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_H
# define FIXED_H

# include <iostream>

class Fixed
{
	private:
		int					_fp_value;
		static int const	_fraction_bits;
	public:
		Fixed(void);
		Fixed(Fixed const & source);
		Fixed & operator=(Fixed const & source);
		~Fixed(void);
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
};

#endif
