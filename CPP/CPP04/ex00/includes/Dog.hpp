/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjaguin <pjaguin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 16:22:07 by pjaguin           #+#    #+#             */
/*   Updated: 2025/05/23 10:39:13 by pjaguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"
# include "dict.hpp"

class Dog: public Animal
{
	private:
		std::string _sound;
	public:
		Dog();
		Dog(Dog const &other);
	
		~Dog();
	
		Dog &operator=(Dog const &other);
		
		void makeSound() const;
};

#endif
