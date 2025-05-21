/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjaguin <pjaguin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 16:20:36 by pjaguin           #+#    #+#             */
/*   Updated: 2025/05/21 17:50:04 by pjaguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"
#include <sstream>

#define N 1

std::string to_str(int number)
{
	std::stringstream ss;
	ss << number;
	return (ss.str());
}

int	main(void)
{
	Animal const	*animals[N];

	std::cout << "_______________________Animal creator_______________________" << std::endl;
	for (size_t i = 0; i < N; i++)
	{
		if (i % 2 == 0)
			animals[i] = new Dog();
		else
			animals[i] = new Cat();
	}		
	
	std::cout << "_______________________Animal sound_______________________" << std::endl;
	// Delete loop
	for (size_t i = 0; i < N; i++)
		delete animals[i];

	return 0;
}
