/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesuserr <jesuserr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 21:02:36 by jesuserr          #+#    #+#             */
/*   Updated: 2023/10/21 22:44:58 by jesuserr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_H
# define POINT_H

# include "Fixed.hpp"

class Point
{
	private:
		Fixed const	_fp_x;
		Fixed const	_fp_y;
	public:
		Point(void);
		Point(float const x, float const y);
		Point(Point const & source);
		Point & operator=(Point const & source);
		~Point(void);
		Fixed	get_fp_x(void) const;
		Fixed	get_fp_y(void) const;
};

bool bsp(Point const a, Point const b, Point const c, Point const point);

#endif
