/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjaguin <pjaguin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 16:20:36 by pjaguin           #+#    #+#             */
/*   Updated: 2025/05/23 15:10:40 by pjaguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"
#include <sstream>

# define NBR_AANIMALS 10

/* static void crash()
{
    AAnimal* meta = new AAnimal();
    std::cout << meta->getType() << " " << std::endl;
    meta->makeSound();
    delete meta;
} */

std::string to_str(int number)
{
	std::stringstream ss;
	ss << number;
	return (ss.str());
}

int	main(void)
{
    // crash();
	AAnimal	*animals[NBR_AANIMALS];

	std::cout << std::endl << YELLOW << "Testing Animal class creator:" << NEUTRAL << std::endl;

	for (size_t i = 0; i < NBR_AANIMALS; i++)
	{
		if (i % 2 == 0)
			animals[i] = new Dog();
		else
			animals[i] = new Cat();
	}		

	std::cout << std::endl << YELLOW << "Test methods from cat and dogs in animals array :" << NEUTRAL << std::endl;

	for (size_t i = 0; i < NBR_AANIMALS; i++)
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
	for (size_t i = 0; i < NBR_AANIMALS; i++)
		delete animals[i];

	return 0;
}
