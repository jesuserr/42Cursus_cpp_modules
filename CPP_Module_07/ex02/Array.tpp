/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesuserr <jesuserr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 13:20:54 by jesuserr          #+#    #+#             */
/*   Updated: 2024/01/02 01:22:28 by jesuserr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_T
# define ARRAY_T

/*********************** ORTHODOX CANONICAL CLASS FORM ************************/

template<typename T>
Array<T>::Array() : _size(0), _array(new T[0])
{
	std::cout << "Default Array created." << std::endl;
}

template<typename T>
Array<T>::Array(unsigned int n) : _size(n), _array(new T[n])
{
 	for (unsigned int i = 0; i < this->_size; i++)
		this->_array[i] = T();	// Inits each element to default value of type T
								// if int, 0; if char, '\0'; if string, ""
	std::cout << "Array created." << std::endl;
}

template<typename T>
Array<T>::Array(Array const & source)
{
	this->_size = source._size;
	this->_array = new T[this->_size];
	for (unsigned int i = 0; i < this->_size; i++)
		this->_array[i] = source._array[i];
	std::cout << "Array cloned." << std::endl;
}

template<typename T>
Array<T> & Array<T>::operator=(Array const & source)
{
	if (this != &source)
	{
		this->_size = source._size;
		delete [] this->_array;
		this->_array = new T[this->_size];
		for (unsigned int i = 0; i < this->_size; i++)
			this->_array[i] = source._array[i];
	}
	std::cout << "Array assigned with new values." << std::endl;
	return *this;
}

template<typename T>
Array<T>::~Array()
{
	delete [] this->_array;
	std::cout << "Array destroyed." << std::endl;
}

/****************************** MEMBER FUNCTIONS ******************************/

template<typename T>
unsigned int	Array<T>::size() const
{
	return this->_size;
}

/***************************** OPERATOR OVERLOAD ******************************/

template<typename T>
T & Array<T>::operator[](unsigned int index)
{
	//std::cout << "Non-const operator[] called." << std::endl;
	if (index >= this->_size)
		throw Array<T>::IndexOutOfBoundsException();
	return this->_array[index];
}

template<typename T>
T const & Array<T>::operator[](unsigned int index) const
{
	//std::cout << "Const operator[] called." << std::endl;
	if (index >= this->_size)
		throw Array<T>::IndexOutOfBoundsException();
	return this->_array[index];
}

/****************************** NESTED CLASSES ********************************/

template<typename T>
const char* Array<T>::IndexOutOfBoundsException::what() const throw()
{
	return ("Index out of bounds.");
}

/***************************** NON-MEMBER FUNCTIONS ***************************/

template<typename T>
std::ostream & operator<<(std::ostream & stream, Array<T> const & source)
{
	for (unsigned int i = 0; i < source.size(); ++i)
		stream << source[i] << ' ';
	return stream;
}

#endif
