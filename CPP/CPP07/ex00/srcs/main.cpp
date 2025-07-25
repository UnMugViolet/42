/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unmugviolet <unmugviolet@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 14:16:34 by pjaguin           #+#    #+#             */
/*   Updated: 2025/07/25 17:49:18 by unmugviolet      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.tpp"
#include "dict.hpp"

int main()
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
}
