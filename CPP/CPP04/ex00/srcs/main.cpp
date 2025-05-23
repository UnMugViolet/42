/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjaguin <pjaguin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 16:20:36 by pjaguin           #+#    #+#             */
/*   Updated: 2025/05/23 11:12:09 by pjaguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "WrongCat.hpp"
#include "Dog.hpp"

int	main(void)
{
	const Animal		*animal = new Animal();
	const Animal		*st_animal = new Dog();
	const Animal		*nd_animal = new Cat();
	const Animal		*copy_nd_animal = new Cat();
	const WrongAnimal	*wrong_cat = new WrongCat();

	copy_nd_animal = nd_animal;

	std::cout << std::endl << YELLOW << "Tests for getting type:" << NEUTRAL << std::endl;
	std::cout << "Animal type: " << UNDERLINE << animal->getType() << NEUTRAL << std::endl;
	std::cout << "First animal type: " << UNDERLINE << st_animal->getType() << NEUTRAL << std::endl;
	std::cout << "Copy second animal type: " << UNDERLINE << nd_animal->getType() << NEUTRAL << std::endl;
	std::cout << "Copy third animal type: " << UNDERLINE << copy_nd_animal->getType() << NEUTRAL << std::endl;
	std::cout << "Wrong animal type: " << UNDERLINE << wrong_cat->getType() << NEUTRAL << std::endl;

	std::cout << std::endl << YELLOW << "Tests for makeSound for all animals:" << NEUTRAL << std::endl;
	std::cout << UNDERLINE << "Animal sound:" << NEUTRAL << std::endl;
	animal->makeSound();
	std::cout << std::endl;

	std::cout << UNDERLINE << "First animal sound:" << NEUTRAL << std::endl;
	st_animal->makeSound();
	std::cout << std::endl;

	std::cout << UNDERLINE << "Second animal sound:" << NEUTRAL << std::endl;
	nd_animal->makeSound();
	std::cout << std::endl;

	std::cout << UNDERLINE << "Copy third animal sound:" << NEUTRAL << std::endl;
	copy_nd_animal->makeSound();
	std::cout << std::endl;

	std::cout << UNDERLINE << "Wrong cat sound:" << NEUTRAL << std::endl;
	wrong_cat->makeSound();
	std::cout << std::endl;


	delete animal;
	delete st_animal;
	delete nd_animal;
	delete wrong_cat;

	return (0);
}
