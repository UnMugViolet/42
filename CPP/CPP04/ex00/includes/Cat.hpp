/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjaguin <pjaguin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 16:23:52 by pjaguin           #+#    #+#             */
/*   Updated: 2025/05/23 10:47:54 by pjaguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"
# include "dict.hpp"

class Cat: public Animal
{
	private:
		std::string _sound;
	public:
		Cat();
		Cat(Cat const &other);
	
		~Cat();

		Cat &operator=(Cat const &other);

		void makeSound() const;
};

#endif
