/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesuserr <jesuserr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 21:26:57 by jesuserr          #+#    #+#             */
/*   Updated: 2024/01/13 20:40:43 by jesuserr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_H
# define BITCOINEXCHANGE_H

# include <iostream>
# include <map>
# include <fstream>
# include <sstream>
# include <iomanip>
# include <cstdlib>
# include <algorithm>

typedef std::map<std::string, float> myMap;
class BitcoinExchange
{
	private:
		myMap 	_exchangeRates;
						
		BitcoinExchange(const BitcoinExchange& source);		// not implemented
		BitcoinExchange& operator=(const BitcoinExchange& source);	// not impl.
		myMap	csvToMap();
		void	conversion(const std::string line);
		bool	isValidDate(const std::string date);
		bool	isValidValue(const float value, const std::stringstream& ss);
		float	valueAtDate(const std::string date);
	public:
		BitcoinExchange();
		~BitcoinExchange();		
		void 	convert(const std::string filename);
};

#endif
