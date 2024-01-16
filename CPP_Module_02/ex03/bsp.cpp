/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesuserr <jesuserr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 22:24:17 by jesuserr          #+#    #+#             */
/*   Updated: 2023/10/22 16:35:49 by jesuserr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Fixed triangle_signed_area(Point const p1, Point const p2, Point const p3)
{
	return (p1.get_fp_x() - p3.get_fp_x()) * (p2.get_fp_y() - p3.get_fp_y()) -\
	(p2.get_fp_x() - p3.get_fp_x()) * (p1.get_fp_y() - p3.get_fp_y());
}

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
	Fixed	area1, area2, area3;
	bool	all_negatives, all_positives;
	
	area1 = triangle_signed_area(point, a, b);
	area2 = triangle_signed_area(point, b, c);
	area3 = triangle_signed_area(point, c, a);
	all_negatives = (area1 < 0) && (area2 < 0) && (area3 < 0);
	all_positives = (area1 > 0) && (area2 > 0) && (area3 > 0);
	return (all_negatives || all_positives);
}
