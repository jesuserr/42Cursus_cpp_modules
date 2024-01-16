/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesuserr <jesuserr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 23:04:53 by jesuserr          #+#    #+#             */
/*   Updated: 2023/12/29 11:05:34 by jesuserr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_H
# define WHATEVER_H

template<typename T>
void swap(T &a, T &b)
{
	T temp = a;
	a = b;
	b = temp;
}

template<typename T>
T const min(T const a, T const b)
{
	if (a < b)
		return(a);
	return(b);
}

template<typename T>
T const max(T const a, T const b)
{
	if (a > b)
		return(a);
	return(b);
}

#endif
