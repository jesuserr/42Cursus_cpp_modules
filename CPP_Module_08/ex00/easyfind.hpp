/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesuserr <jesuserr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 23:05:04 by jesuserr          #+#    #+#             */
/*   Updated: 2024/01/03 00:59:05 by jesuserr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_H
# define EASYFIND_H

# include <iostream>
# include <algorithm>
# include <stdexcept>

template<typename T>
void easyfind(const T& container, const int value)
{
	typename T::const_iterator it;

	std::cout << "Looking for value " << value << "...\t";
	it = std::find(container.begin(), container.end(), value);	
	if (it == container.end())
		throw std::runtime_error("Value not found.");
	std::cout << "Value found.\n";
	//std::cout << &(*container.begin()) << '\n';
	//std::cout << &(*it) << '\n';
	//std::cout << &(*container.end()) << '\n';	
}

#endif
