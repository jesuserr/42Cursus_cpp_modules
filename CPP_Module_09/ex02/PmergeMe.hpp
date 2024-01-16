/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesuserr <jesuserr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 11:00:20 by jesuserr          #+#    #+#             */
/*   Updated: 2024/01/16 13:59:23 by jesuserr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_H
# define PMERGEME_H

# define	JACOBSTAHL_MAX		25					// Jacobsthal number 5592405
# define	START_TIMER			0
# define	STOP_TIMER_VECTOR	1
# define	STOP_TIMER_DEQUE	2
# define	DEFAULT				"\001\033[0;39m\002"
# define	RED					"\001\033[1;91m\002"
# define	BLUE				"\001\033[1;94m\002"

# include <iostream>
# include <cstring>
# include <climits>
# include <cstdlib>
# include <vector>
# include <deque>
# include <sys/time.h>

class PmergeMe
{
	private:
		std::vector<std::pair<int, int> >	_vectorPair;
		std::vector<int>					_finalVector;
		std::deque<std::pair<int, int> >	_dequePair;
		std::deque<int>						_finalDeque;
		std::vector<int>					_jacobsthalTable;

		PmergeMe(const PmergeMe& source);					// not implemented
		PmergeMe& operator=(const PmergeMe& source);		// not implemented

		void	checkArgumentsAndDigits(int argc, char **argv);
		void	checkLimitsAndSorted(int argc, char **argv);
		void	printSortingResults(int argc, char **argv, std::string cont);
		void	timer(int timerAction);
		void	generateJacobsthalTable(int number);	
		
		template <typename T, typename U>
		void	sortContainer(T& containerPair, U& finalContainer, int argc, char **argv);
		template <typename T>
		void	quickSortContainer(T& array, int start, int end);
		template <typename T>
		int		partitionContainer(T& array, int start, int end);
		template <typename T>
		void	binaryInsertionSortContainer(T& array, int value, int end);
		template <typename T>
		void	verifySortedContainer(T& finalContainer);
	public:
		PmergeMe();
		~PmergeMe();
		void	sortNumbers(int argc, char** argv);
};

template <typename T, typename U>
void PmergeMe::sortContainer(T& containerPair, U& finalContainer, int argc, char **argv)
{
	containerPair.clear();
	finalContainer.clear();
	for (int i = 1; i < argc; i += 2)										// step 1
	{
		if (i == argc - 1)
			containerPair.push_back(std::make_pair(std::atoi(argv[i]), -1));
		else
			containerPair.push_back(std::make_pair(std::atoi(argv[i]), \
			std::atoi(argv[i + 1])));
	}
	for (size_t i = 0; i < containerPair.size(); i++)						// step 2
		if (containerPair[i].first < containerPair[i].second)
			std::swap(containerPair[i].first, containerPair[i].second);
	quickSortContainer(containerPair, 0, containerPair.size() - 1);			// step 3
	for (size_t i = 0; i < containerPair.size(); i++)						// step 4
		finalContainer.push_back(containerPair[i].first);
	if (containerPair[0].second != -1)
		finalContainer.insert(finalContainer.begin(), containerPair[0].second);
	int j = 0;
	for (size_t i = 1; i < containerPair.size(); i++)						// step 5
	{
		while (_jacobsthalTable[j] >= (int)containerPair.size())
			j++;
		binaryInsertionSortContainer(finalContainer, \
		containerPair[_jacobsthalTable[j]].second, _jacobsthalTable[j] + i);
		j++;
	}
}

template <typename T>
void	PmergeMe::quickSortContainer(T& container, int start, int end)
{
	if (start < end)
	{
		int partitionIndex = partitionContainer(container, start, end);
		quickSortContainer(container, start, partitionIndex - 1);
		quickSortContainer(container, partitionIndex + 1, end);
	}
}

template <typename T>
int PmergeMe::partitionContainer(T& container, int start, int end)
{
	int	pivot = container[end].first;
	int partitionIndex = start;
	
	for (int i = start; i < end; i++)
	{
		if (container[i].first <= pivot)
		{
			std::swap(container[i].first, container[partitionIndex].first);
			std::swap(container[i].second, container[partitionIndex].second);
			partitionIndex++;
		}
	}
	std::swap(container[partitionIndex].first, container[end].first);
	std::swap(container[partitionIndex].second, container[end].second);
	return (partitionIndex);	
}

template <typename T>
void PmergeMe::binaryInsertionSortContainer(T& container, int value, int end)
{
	size_t	left = 0;
	size_t	right = end;

	if (value == -1)
		return;
	while (left < right)
	{
		size_t	mid = left + ((right - left) / 2);
		if (value < container[mid])
			right = mid;
		else
			left = mid + 1;
	}
	container.insert(container.begin() + left, value);
}

template <typename T>
void	PmergeMe::verifySortedContainer(T& finalContainer)
{
	for (size_t i = 0; i < finalContainer.size() - 1 ; i++)
	{
		if (finalContainer[i] > finalContainer[i + 1])
		{
			std::cout << RED << "Error: contained non sorted.\n" << BLUE;
			return;
		}
	}
	std::cout << "Container is sorted." << '\n';
}

#endif
