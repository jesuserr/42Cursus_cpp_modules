/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesuserr <jesuserr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 09:53:06 by jesuserr          #+#    #+#             */
/*   Updated: 2024/01/11 15:30:29 by jesuserr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_H
# define RPN_H

# include <iostream>
# include <stack>
# include <sstream>
# include <stdexcept>
# include <string>
# include <iomanip>

class RPN
{
	private:
		std::stack<float> 	_myStack;
								
		RPN(const RPN& source);				// not implemented
		RPN& operator=(const RPN& source);	// not impl.
		void	executeOperator(const char operation);
	public:
		RPN();
		~RPN();		
		void 	calculate(const std::string expression);
};

#endif
