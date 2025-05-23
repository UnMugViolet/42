/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjaguin <pjaguin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 17:00:33 by pjaguin           #+#    #+#             */
/*   Updated: 2025/05/23 10:50:17 by pjaguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <iostream>
# include <string>
# include "dict.hpp"

class WrongAnimal
{
	protected:
		std::string type;
	public:
		WrongAnimal();
		WrongAnimal(WrongAnimal const &other);
		
		virtual ~WrongAnimal();
		
		WrongAnimal &operator=(WrongAnimal const &other);

		std::string getType() const;
		void makeSound() const;
};


#endif
