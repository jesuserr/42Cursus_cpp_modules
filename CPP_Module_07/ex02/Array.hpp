/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesuserr <jesuserr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 13:20:50 by jesuserr          #+#    #+#             */
/*   Updated: 2024/01/02 01:22:07 by jesuserr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_H
# define ARRAY_H

# include <iostream>

template<typename T>
class Array
{
	private:
		unsigned int _size;        
		T *			 _array;
	public:
		Array();
		Array(unsigned int n);
		Array(Array const & source);
		Array & operator=(Array const & source);
		~Array();

		unsigned int	size() const;
		
		T & operator[](unsigned int index);
		T const & operator[](unsigned int index) const;

		class IndexOutOfBoundsException: public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
};

template<typename T>
std::ostream & operator<<(std::ostream & stream, Array<T> const & source);

# include "Array.tpp"

#endif

