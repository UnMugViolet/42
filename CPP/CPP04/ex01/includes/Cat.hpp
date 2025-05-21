/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjaguin <pjaguin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 16:23:52 by pjaguin           #+#    #+#             */
/*   Updated: 2025/05/21 14:21:07 by pjaguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"
# include "Brain.hpp"
# include "dict.hpp"

class Cat: public Animal
{
	private:
		std::string _sound;
		Brain *_brain;
	public:
		Cat();
		virtual ~Cat();
		void makeSound() const;

		Cat &operator=(Cat const &other);
};

#endif
