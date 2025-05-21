/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjaguin <pjaguin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 16:22:07 by pjaguin           #+#    #+#             */
/*   Updated: 2025/05/21 14:20:55 by pjaguin          ###   ########.fr       */
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
		virtual ~Dog();
		void makeSound() const;

		Dog &operator=(Dog const &other);
};

#endif
