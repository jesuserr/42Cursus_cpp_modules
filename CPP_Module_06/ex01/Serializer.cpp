/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesuserr <jesuserr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 11:11:10 by jesuserr          #+#    #+#             */
/*   Updated: 2023/12/24 13:34:31 by jesuserr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

/*********************** ORTHODOX CANONICAL CLASS FORM ************************/

Serializer::Serializer(void)
{
}

Serializer::Serializer(Serializer const & source)
{
	*this = source;
}

Serializer & Serializer::operator=(Serializer const & source)
{
	if (this != &source)
		return (*this);
	return (*this);    
}

Serializer::~Serializer(void)
{
}

/****************************** MEMBER FUNCTIONS ******************************/

uintptr_t Serializer::serialize(Data* ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}
	
Data* Serializer::deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data*>(raw));
}
