/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesuserr <jesuserr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 11:11:04 by jesuserr          #+#    #+#             */
/*   Updated: 2023/12/27 12:05:49 by jesuserr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include <iostream>
#include <iomanip>

void hexDump(const void *data, size_t length)
{
	const unsigned char *ptr = reinterpret_cast<const unsigned char*>(data);
	
	std::cout << "\n";
	for (size_t i = 0; i < length; ++i)
	{
		std::cout << std::hex << std::setw(2) << std::setfill('0');
		std::cout << static_cast<int>(ptr[i]) << " ";
		if ((i + 1) % 16 == 0 || i == length - 1)
		{
			std::cout << " ";
			for (size_t j = i - (i % 16); j <= i; ++j)
			{
				if (j == i / 2)
					std::cout << " ";
				if (j >= length)
					std::cout << "   ";
				else if (ptr[j] >= 32 && ptr[j] <= 126)
					std::cout << static_cast<char>(ptr[j]) << " ";
				else
					std::cout << ". ";
			}
			std::cout << "\n" << std::dec;
		}
	}
}

int main(void)
{
	Data		*player = new Data;
	Data		*retValues;
	uintptr_t	ptr;	//unsigned integer type capable of holding
						// a pointer to void
	
	player->level = 15;				//4 bytes
	player->health = 255;			//4 bytes
	player->initial = 'J';			//1 byte
	player->gameComplete = 1;		//1 byte
	player->xpPoints = 123.456;		//4 bytes
	
	std::cout << "Size of structure: " << sizeof(Data);
	std::cout << "\nSize of player pointer: " << sizeof(player);
	std::cout << "\nSize of ptr pointer: " << sizeof(player);
	std::cout << "\nSize of retValues pointer: " << sizeof(player);
	std::cout << "\n";
	
	std::cout << "\nLevel: " << player->level;
	std::cout << "\nHealth: " << player->health;
	std::cout << "\nLetter: " << player->initial;
	std::cout << "\nGames Completed: " << player->gameComplete;
	std::cout << "\nXP Points: " << player->xpPoints;
	std::cout << "\n";

	ptr = Serializer::serialize(player);
	retValues = Serializer::deserialize(ptr);
	//retValues = Serializer::deserialize(Serializer::serialize(player));
		
	std::cout << "\nPlayer address prior casts: " << player;
	hexDump(player, 16);
	std::cout << "\nuintptr_t address after first cast: 0x" << std::hex << ptr;
	hexDump((void*)ptr, 16);
	std::cout << "\nretValues address after second cast: " << retValues;
	hexDump(retValues, 16);
		
	std::cout << "\nLevel: " << retValues->level;
	std::cout << "\nHealth: " << retValues->health;
	std::cout << "\nLetter: " << retValues->initial;
	std::cout << "\nGames Completed: " << retValues->gameComplete;
	std::cout << "\nXP Points: " << retValues->xpPoints;
	std::cout << "\n";
	
	// struct reinterpreted as int
	std::cout << "\nuintptr_t as int (1): " << *reinterpret_cast<int*>((ptr));
	std::cout << "\nuintptr_t as int (2): " << *reinterpret_cast<int*>((ptr) + 4);
	std::cout << "\nuintptr_t as int (3): " << *reinterpret_cast<int*>((ptr) + 8);
	std::cout << "\nuintptr_t as int (4): " << *reinterpret_cast<int*>((ptr) + 12);
	std::cout << "\n";
	// struct reinterpreted as long
	std::cout << "\nuintptr_t as long (1): " << *reinterpret_cast<long*>((ptr));
	std::cout << "\nuintptr_t as long (2): " << *reinterpret_cast<long*>((ptr) + 8);
	std::cout << "\n";
	
	delete 	player;	
	return (0);
}
