/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesuserr <jesuserr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 23:04:49 by jesuserr          #+#    #+#             */
/*   Updated: 2023/12/29 11:15:13 by jesuserr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "whatever.hpp"

int main(void)
{
	std::cout << "******** SUBJECT TESTS *********\n";
	int a = 2;
	int b = 3;
	std::cout << "\nInt before swap a = " << a << ", b = " << b << "\n";
	::swap( a, b );
	std::cout << "Int after swap a = " << a << ", b = " << b << "\n";
	std::cout << "min( a, b ) = " << ::min( a, b ) << "\n";
	std::cout << "max( a, b ) = " << ::max( a, b ) << "\n";
	
	std::string c = "chaine1";
	std::string d = "chaine2";
	std::cout << "\nString before swap c = " << c << ", d = " << d << "\n";
	::swap(c, d);
	std::cout << "String after c = " << c << ", d = " << d << "\n";
	std::cout << "min( c, d ) = " << ::min( c, d ) << "\n";
	std::cout << "max( c, d ) = " << ::max( c, d ) << "\n";
	
	std::cout << "\n********* OTHER TESTS **********\n";
	char e = 'a';
	char f = 'b';
	std::cout << "\nChar before swap e = " << e << ", f = " << f << "\n";
	::swap( e, f );
	std::cout << "Char after swap e = " << e << ", f = " << f << "\n";
	std::cout << "min( e, f ) = " << ::min( e, f ) << "\n";
	std::cout << "max( e, f ) = " << ::max( e, f ) << "\n";
	
	float g = 12.34f;
	float h = 56.78f;
	std::cout << "\nFloat before swap g = " << g << ", h = " << h << "\n";
	::swap( g, h );
	std::cout << "Float after swap g = " << g << ", h = " << h << "\n";
	std::cout << "min( g, h ) = " << ::min( g, h ) << "\n";
	std::cout << "max( g, h ) = " << ::max( g, h ) << "\n";
	
	double i = 12.34f;
	double j = 56.78f;
	std::cout << "\nDouble before swap i = " << i << ", j = " << j << "\n";
	::swap( i, j );
	std::cout << "Double after swap i = " << i << ", j = " << j << "\n";
	std::cout << "min( i, j ) = " << ::min( i, j ) << "\n";
	std::cout << "max( i, j ) = " << ::max( i, j ) << "\n";
	
	return 0;
}
