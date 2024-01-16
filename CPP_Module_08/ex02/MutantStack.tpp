/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesuserr <jesuserr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 13:22:55 by jesuserr          #+#    #+#             */
/*   Updated: 2024/01/04 22:28:59 by jesuserr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_T
# define MUTANTSTACK_T

/*********************** ORTHODOX CANONICAL CLASS FORM ************************/

template<typename T>
MutantStack<T>::MutantStack() : std::stack<T>()
{
	// not necessary to call explicitly parent constructor, included for clarity
	std::cout << "MutantStack constructor called." << "\n";
}

template<typename T>
MutantStack<T>::MutantStack(const MutantStack& other) : std::stack<T>(other)
{
	std::cout << "MutantStack copy constructor called." << "\n";
}

template<typename T>
MutantStack<T>& MutantStack<T>::operator=(const MutantStack& other)
{
	if (this != &other)
		this->std::stack<T>::operator=(other);	// calls the assignment operator
												// of the parent class
		//this->c = other.c;					// similar effect as above
	std::cout << "MutantStack assigned new values." << "\n";
	return (*this);
}

template<typename T>
MutantStack<T>::~MutantStack()
{
	std::cout << "MutantStack destructor called." << "\n";
}

/****************************** MEMBER FUNCTIONS ******************************/

// In the context of the std::stack class, c is a protected member that
// represents the underlying container used by the stack.
template<typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin()
{
	return (this->c.begin());
}

template<typename T>
typename MutantStack<T>::iterator MutantStack<T>::end()
{
	return (this->c.end());
}

#endif
