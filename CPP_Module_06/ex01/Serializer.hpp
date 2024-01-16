/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesuserr <jesuserr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 11:11:17 by jesuserr          #+#    #+#             */
/*   Updated: 2023/12/24 20:58:09 by jesuserr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_H
# define SERIALIZER_H

# include <stdint.h>	//for uintptr_t
# include "Data.hpp"

class  Serializer
{
	private:
		Serializer(void);
		Serializer(Serializer const & source);
		Serializer & operator=(Serializer const & source);
		~Serializer(void);
	public:
		static uintptr_t 	serialize(Data* ptr);
		static Data* 		deserialize(uintptr_t raw);
};

#endif
