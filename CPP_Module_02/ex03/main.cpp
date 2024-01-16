/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesuserr <jesuserr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 11:54:39 by jesuserr          #+#    #+#             */
/*   Updated: 2023/10/22 16:33:47 by jesuserr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

int	main(void)
{
	// Test Triangle A
	Point a(0, 0);
	Point b(10, 0);
	Point c(5, 10);
	Point point(5, 5);
	// Test Triangle B
/* 	Point a(2, 4);
	Point b(11, 6);
	Point c(7, 12);
	Point point(8.9,8.9); */
	// Test Triangle C
/* 	Point a(-2.4, 3);
	Point b(8, -12);
	Point c(23, -3.1415);
	Point point(8, 6); */

	std::cout << "Point [" << point.get_fp_x() << "," << point.get_fp_y();
	if (bsp(a, b, c, point))
		std::cout << "] is inside the triangle" << std::endl;
	else
		std::cout << "] is outside the triangle" << std::endl;
	return (0);
}
