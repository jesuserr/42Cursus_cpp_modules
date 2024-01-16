/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesuserr <jesuserr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 23:04:53 by jesuserr          #+#    #+#             */
/*   Updated: 2023/12/31 18:38:23 by jesuserr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_H
# define ITER_H

# include <iostream>

template<typename T>
void iter(T const *array, int len, void(*func)(T const &))
{
	std::cout << "call to 'print' with const arguments" << std::endl;
	if (array && func && len >= 0)
		for (int i = 0; i < len; i++)
			func(array[i]);
}

template<typename T>
void iter(T *array, int len, void(*func)(T &))
{
	std::cout << "call to 'twoTimes' with non-const arguments" << std::endl;
	if (array && func && len >= 0)
		for (int i = 0; i < len; i++)
			func(array[i]);
}

template<typename T>
void print(T const & element)
{
	std::cout << element << "\n";
}

template<typename T>
void twoTimes(T & element)
{
	element *= 2;
}

#endif
