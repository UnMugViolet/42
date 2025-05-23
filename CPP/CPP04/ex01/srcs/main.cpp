/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjaguin <pjaguin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 16:20:36 by pjaguin           #+#    #+#             */
/*   Updated: 2025/05/23 14:52:18 by pjaguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"
#include <sstream>

#define NBR_ANIMALS 10

std::string to_str(int number)
{
	std::stringstream ss;
	ss << number;
	return (ss.str());
}

int	main(void)
{
	Animal	*animals[NBR_ANIMALS];

	std::cout << std::endl << YELLOW << "Testing Animal class creator:" << NEUTRAL << std::endl;

	for (size_t i = 0; i < NBR_ANIMALS; i++)
	{
		if (i % 2 == 0)
			animals[i] = new Dog();
		else
			animals[i] = new Cat();
	}		

	std::cout << std::endl << YELLOW << "Test methods from cat and dogs in animals array :" << NEUTRAL << std::endl;

	for (size_t i = 0; i < NBR_ANIMALS; i++)
	{
		std::cout << "Animal " << to_str(i) << ": ";
		animals[i]->makeSound();
		std::cout << "His type is: " << animals[i]->getType() << std::endl;
	}


	std::cout << std::endl << YELLOW << "Test setting idea for an animal" << NEUTRAL << std::endl;
	Dog *dog = new Dog();
	dog->getBrain()->setIdeas("I want to play", 0);
	dog->getBrain()->setIdeas("I want to eat", 1);
	dog->getBrain()->setIdeas("I want to sleep", 101);
	
	std::cout << "Dog created first idea: " << BOLD << dog->getBrain()->getIdeas(0) << NEUTRAL << std::endl;
	std::cout << "Dog created second idea: " << BOLD << dog->getBrain()->getIdeas(1) << NEUTRAL << std::endl;
	std::cout << dog->getBrain()->getIdeas(101) << std::endl;
	delete dog;
	
	
	std::cout << std::endl << YELLOW << "Deleting all animals :" << NEUTRAL << std::endl;

	// Delete loop
	for (size_t i = 0; i < NBR_ANIMALS; i++)
		delete animals[i];

	return 0;
}
