/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjaguin <pjaguin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 16:22:07 by pjaguin           #+#    #+#             */
/*   Updated: 2025/05/22 10:58:01 by pjaguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"
# include "Brain.hpp"
# include "dict.hpp"

class Dog: public Animal
{
	private:
		std::string _sound;
		Brain *_brain;
	public:
		Dog();
		Dog(Dog const &other);

		~Dog();
	
		Dog &operator=(Dog const &other);

		void makeSound() const;
		
		// Getters
		Brain *getBrain() const;
};

#endif
