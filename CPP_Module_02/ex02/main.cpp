/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesuserr <jesuserr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 11:54:39 by jesuserr          #+#    #+#             */
/*   Updated: 2023/10/21 15:44:56 by jesuserr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int	main(void)
{
	Fixed		a;
	Fixed const	b(Fixed(5.05f) * Fixed(2));
				
 	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
		
	std::cout << b << std::endl;
	
	std::cout << Fixed::max(a, b) << std::endl;
	
	/*********** MY TESTS ***********/

	std::cout << std::endl;
	std::cout << "My tests" << std::endl;
	std::cout << Fixed::min(a, b) << std::endl;

	Fixed	c(10.5f);
	Fixed	d(11);

	std::cout << (c > d) << std::endl;
	std::cout << (c < d) << std::endl;
	std::cout << (c == d) << std::endl;
	std::cout << (c != d) << std::endl;
	std::cout << (c >= d) << std::endl;
	std::cout << (c <= d) << std::endl;
	std::cout << Fixed::max(c, d) << std::endl;
	std::cout << Fixed::min(c, d) << std::endl;
	std::cout << std::endl;

	c = c + 0.5f;  // 0.5 is converted to fixed point
	//c++;		// this would ++ the whole number (including fract part)
			
	std::cout << (c > d) << std::endl;
	std::cout << (c < d) << std::endl;
	std::cout << (c == d) << std::endl;
	std::cout << (c != d) << std::endl;
	std::cout << (c >= d) << std::endl;
	std::cout << (c <= d) << std::endl;
	std::cout << Fixed::max(c, d) << std::endl;
	std::cout << Fixed::min(c, d) << std::endl;
	std::cout << std::endl;

	c = c + 1;
			
	std::cout << (c > d) << std::endl;
	std::cout << (c < d) << std::endl;
	std::cout << (c == d) << std::endl;
	std::cout << (c != d) << std::endl;
	std::cout << (c >= d) << std::endl;
	std::cout << (c <= d) << std::endl;
	std::cout << Fixed::max(c, d) << std::endl;
	std::cout << Fixed::min(c, d) << std::endl;
	std::cout << std::endl;
	
	std::cout << a << std::endl;
	std::cout << --a << std::endl;
	std::cout << a << std::endl;
	std::cout << a-- << std::endl;
	std::cout << a << std::endl;
	std::cout << std::endl;
	
	Fixed const	e(Fixed(5.05f) / Fixed(2));
	std::cout << e << std::endl;
	Fixed const	f(Fixed(5.05f) + Fixed(2));
	std::cout << f << std::endl;
	Fixed const	g(Fixed(5.05f) - Fixed(2));
	std::cout << g << std::endl;
	Fixed const	h(Fixed(5) / Fixed(0));
	std::cout << h << std::endl;
	Fixed const	i(Fixed(0) / Fixed(5));
	std::cout << i << std::endl;
	Fixed const	j(Fixed(3) - Fixed(5));
	std::cout << j << std::endl;

	return (0);
}
