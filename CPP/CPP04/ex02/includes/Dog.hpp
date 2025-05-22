/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjaguin <pjaguin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 16:22:07 by pjaguin           #+#    #+#             */
/*   Updated: 2025/05/22 10:56:48 by pjaguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef DOG_HPP
# define DOG_HPP

# include "AAnimal.hpp"
# include "Brain.hpp"
# include "dict.hpp"

class Dog: public AAnimal
{
	private:
		std::string _sound;
		Brain *_brain;
	public:
		Dog();
		Dog(Dog const &other);

		~Dog();
		
		void makeSound() const;

		Dog &operator=(Dog const &other);

		Brain *getBrain() const;
		virtual std::string getType();
};

#endif
