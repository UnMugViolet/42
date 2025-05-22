/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjaguin <pjaguin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 16:20:36 by pjaguin           #+#    #+#             */
/*   Updated: 2025/05/22 11:13:34 by pjaguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"
#include <sstream>

#define N 10

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
	
	std::cout << "____________________Animal sound and type____________________" << std::endl;
	for (size_t i = 0; i < N; i++)
	{
		std::cout << "Animal " << to_str(i) << ": ";
		animals[i]->makeSound();
		std::cout << "His type is: " << animals[i]->getType() << std::endl;
	}
	
	// Delete loop
	for (size_t i = 0; i < N; i++)
		delete animals[i];

	return 0;
}
