/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjaguin <pjaguin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 16:20:36 by pjaguin           #+#    #+#             */
/*   Updated: 2025/05/20 17:40:25 by pjaguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int	main(void)
{
	const Animal	*j = new Dog();
	const Animal	*i = new Cat();

	for (int i = 0; i <= 100; i++)
	{
		Cat *cat = new Cat();
		Dog *dog = new Dog();
		
	}
	delete	j; // should not create a leak
	delete	i;

	return (0);
}
