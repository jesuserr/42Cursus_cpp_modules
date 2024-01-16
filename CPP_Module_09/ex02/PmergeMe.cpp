/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesuserr <jesuserr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 10:55:50 by jesuserr          #+#    #+#             */
/*   Updated: 2024/01/16 13:45:06 by jesuserr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

/*********************** ORTHODOX CANONICAL CLASS FORM ************************/

PmergeMe::PmergeMe(void)
{
	//std::cout << "PmergeMe constructor called" << '\n';	
}

PmergeMe::PmergeMe(const PmergeMe& source)
{
	(void)source;
}

PmergeMe& PmergeMe::operator=(const PmergeMe& source)
{
	(void)source;
	return (*this);
}

PmergeMe::~PmergeMe(void)
{
	//std::cout << "PmergeMe destructor called" << '\n';
}

/******************************** MAIN FUNCTION *******************************/

void	PmergeMe::sortNumbers(int argc, char **argv)
{
	checkArgumentsAndDigits(argc, argv);
	checkLimitsAndSorted(argc, argv);
	generateJacobsthalTable(JACOBSTAHL_MAX);
	sortContainer(_vectorPair, _finalVector, argc, argv);
	printSortingResults(argc, argv, "VECTOR");
	//sortContainer(_dequePair, _finalDeque, argc, argv);
	//printSortingResults(argc, argv, "DEQUE");
	timer(START_TIMER);
	sortContainer(_vectorPair, _finalVector, argc, argv);
	timer(STOP_TIMER_VECTOR);
	verifySortedContainer(_finalVector);
	timer(START_TIMER);
	sortContainer(_dequePair, _finalDeque, argc, argv);
	timer(STOP_TIMER_DEQUE);	
	verifySortedContainer(_finalDeque);
}

/****************************** PARSING FUNCTIONS *****************************/

void	PmergeMe::checkArgumentsAndDigits(int argc, char **argv)
{
	std::cout << BLUE << "Parsing arguments..." << '\n' << RED;	
	if (argc == 1)
		throw std::invalid_argument("Error: integer sequence not provided.");
	if (argv[1][0] == '\0')
			throw std::invalid_argument("Error: empty argument.");
	for (int i = 1; i < argc; i++)
	{
		for (size_t j = 0; j < strlen(argv[i]); j++)
		{
			if (!isdigit(argv[i][j]))
				throw std::invalid_argument("Error: only positive int allowed.");
		}
	}	
}

void	PmergeMe::checkLimitsAndSorted(int argc, char **argv)
{
	bool	sorted = true;
	int		i = argc;
	
	while (i-- > 1)
	{
		if (std::atoi(argv[i]) > INT_MAX || std::atoi(argv[i]) < 0 || \
		strlen(argv[i]) > 10 || (strlen(argv[i]) == 10 && argv[i][0] > '2'))
			throw std::invalid_argument("Error: number out of range found.");
	}
	for (i = 1; i < (argc - 1); i++)
	{
		if (std::atoi(argv[i]) > std::atoi(argv[i + 1]))
		{
			sorted = false;
			break;
		}
	}
	if (sorted)
		throw std::invalid_argument("Error: integer sequence already sorted.");
	std::cout << BLUE;
}

/***************************** PRINTING FUNCTIONS *****************************/

void	PmergeMe::printSortingResults(int argc, char **argv, std::string cont)
{
	std::cout << BLUE << "Before:\t" << DEFAULT;
	for (int i = 1; i < argc; i++)
			std::cout << argv[i] << " ";
	std::cout << BLUE << "\nAfter:\t" << DEFAULT;
	if (cont == "VECTOR")
	{
		for (size_t i = 0; i < _finalVector.size(); i++)
			std::cout << _finalVector[i] << " ";
	}
	else if (cont == "DEQUE")
	{
		for (size_t i = 0; i < _finalDeque.size(); i++)
			std::cout << _finalDeque[i] << " ";
	}
	std::cout << "\n" << BLUE;
}

void	PmergeMe::timer(int timerAction)
{
	static struct timeval	start;
	static struct timeval	end;
	long					secs_used;
	long					micros_used;

	if (timerAction == START_TIMER)
		gettimeofday(&start, NULL);
	else
	{
		gettimeofday(&end, NULL);
		secs_used = end.tv_sec - start.tv_sec;
		micros_used = ((secs_used * 1000000) + end.tv_usec) - (start.tv_usec);
		if (timerAction == STOP_TIMER_VECTOR)
		{
			std::cout << "Time to process a range of " << _finalVector.size()
			<< " elements with std::vector : " << micros_used << " us\n";
		}
		else if (timerAction == STOP_TIMER_DEQUE)
		{
			std::cout << "Time to process a range of " << _finalDeque.size()
			<< " elements with std::deque  : " << micros_used << " us\n";
		}			
	}
}

/************************* JACOBSTHAL TABLE GENERATOR *************************/

// Jacobsthal numbers are a sequence of integers where each number is the sum
// of twice the previous-previous number plus the previous number.
// Ex: 0, 1, 1, 3, 5, 11, 21, 43, 85, 171, 341, 683, 1365, 2731, 5461, 10923, 
// 21845, 43691, 87381, 174763, 349525, 699051, 1398101, 2796203, 5592405, ...
void PmergeMe::generateJacobsthalTable(int numbers)
{
	std::vector<int> table(numbers);
		
	table[0] = 0;
	table[1] = 1;
	for (int i = 2; i < numbers; i++)
		table[i] = 2 * table[i - 2] + table[i - 1];
	//for (size_t i = 0; i < table.size(); i++)
	//	std::cout << table[i] << " ";	
	std::vector<int>::iterator it1 = table.begin() + 2;
	std::vector<int>::iterator it2 = table.begin() + 3;
	_jacobsthalTable.push_back(*it2 - 1);
	while (it2 != table.end())
	{
		int i = *it2 - 1;
		while (i > *it1 && i < *it2)
		{
			_jacobsthalTable.push_back(i - 1);
			i--;
		}
		it2++;
		if (it2 == table.end())
			break;
		_jacobsthalTable.push_back(*it2 - 1);
		it1++;
	}
	//for (size_t i = 0; i < _jacobsthalTable.size(); i++)
	//	std::cout << _jacobsthalTable[i] << " ";	
}
