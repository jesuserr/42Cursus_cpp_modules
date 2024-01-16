/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesuserr <jesuserr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 11:39:31 by jesuserr          #+#    #+#             */
/*   Updated: 2024/01/03 21:10:57 by jesuserr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_H
# define SPAN_H

# include <iostream>
# include <vector>
# include <algorithm>

class Span
{
	private:
		unsigned int								_size;
		std::vector<int> 							_vector;
		typedef std::vector<int>::const_iterator	iterator;
	public:
		Span();
		Span(unsigned int size);
		Span(const Span& source);
		Span& operator=(const Span& source);
		~Span();
		
		void			addNumber(int number);
		unsigned int	shortestSpan() const;
		unsigned int	longestSpan() const;
		void			addRange(iterator begin, iterator end);
		void			printVector() const;
				
		unsigned int	getCurrentSize() const;		
		
		class FullVectorException: public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
		
		class NotEnoughNumbersException: public std::exception
		{
			public:
				virtual const char* what() const throw();
		};		
};

#endif
