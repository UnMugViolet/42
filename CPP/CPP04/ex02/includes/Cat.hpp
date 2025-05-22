/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjaguin <pjaguin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 16:23:52 by pjaguin           #+#    #+#             */
/*   Updated: 2025/05/22 10:57:13 by pjaguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef CAT_HPP
# define CAT_HPP

# include "AAnimal.hpp"
# include "Brain.hpp"
# include "dict.hpp"

class Cat: public AAnimal
{
	private:
		std::string _sound;
		Brain *_brain;
	public:
		Cat();
		Cat(Cat const &other);
	
		~Cat();

		Cat &operator=(Cat const &other);
		
		void makeSound() const;

		// Getters
		Brain *getBrain() const;
		virtual std::string getType();
};

#endif
