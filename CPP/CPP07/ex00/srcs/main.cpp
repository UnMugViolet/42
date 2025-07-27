/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unmugviolet <unmugviolet@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 14:16:34 by pjaguin           #+#    #+#             */
/*   Updated: 2025/07/27 07:40:02 by unmugviolet      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.tpp"
#include "dict.hpp"

int main( void ) {

	int a = 2;
	int b = 3;
	
	::swap( a, b );
	
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
	std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;

	std::string c = "chaine1";
	std::string d = "chaine2";

	::swap(c, d);

	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
	std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
	
	return 0;
}

/* int main()
{
	double	A = -12.7845;
	double	B = 4862.1754;

	std::cout << BOLD << "Min: " << NEUTRAL << min(A, B) << std::endl;
	std::cout << BOLD << "Max: " << NEUTRAL << max(A, B) << std::endl;

	std::cout << BOLD << "A value: " << NEUTRAL << A << std::endl;
	std::cout << BOLD << "B value: " << NEUTRAL << B << std::endl;
	
	std::cout << std::endl << BOLD << "Swapping" << NEUTRAL << std::endl;
	swap(A, B);

	std::cout << BOLD << "A value: " << NEUTRAL << A << std::endl;
	std::cout << BOLD << "B value: " << NEUTRAL << B << std::endl;

	std::cout << std::endl << BOLD << "Swapping" << NEUTRAL << std::endl;
	
	swap(B, A);
	
	std::cout << BOLD << "A value: " << NEUTRAL << A << std::endl;
	std::cout << BOLD << "B value: " << NEUTRAL << B << std::endl;

	return 0;

} */
