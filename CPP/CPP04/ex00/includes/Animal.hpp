/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjaguin <pjaguin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 16:20:19 by pjaguin           #+#    #+#             */
/*   Updated: 2025/05/23 10:38:55 by pjaguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>
# include <string>
# include "dict.hpp"


class Animal
{
	protected:
		std::string type;
	public:
		Animal();
		Animal(Animal const &other);

		virtual ~Animal();
		
		Animal &operator=(Animal const &other);

		virtual void makeSound() const;
		
		// Getters
		std::string getType() const;
};


#endif
