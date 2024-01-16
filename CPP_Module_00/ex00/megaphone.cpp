/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesuserr <jesuserr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 13:24:49 by jesuserr          #+#    #+#             */
/*   Updated: 2023/10/05 16:56:53 by jesuserr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>

int	main(int argc, char **argv)
{
	int i;
	int j;
	
	if (argc >= 2)
	{
		j = 1;
		while (argv[j])
		{
			i = 0;
			while (argv[j][i])
			{
				std::cout << (char) toupper(argv[j][i]);
				i++;
			}
		j++;
		}		
	}
	else
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	std::cout << std::endl;
	return (0);
}
