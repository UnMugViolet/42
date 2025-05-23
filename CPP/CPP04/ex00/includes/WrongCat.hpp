/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjaguin <pjaguin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 16:56:51 by pjaguin           #+#    #+#             */
/*   Updated: 2025/05/23 10:37:28 by pjaguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

# include "WrongAnimal.hpp"
# include "dict.hpp"

class WrongCat: public WrongAnimal
{
	private:
		std::string _sound;
	public:
		WrongCat();
		~WrongCat();

		WrongCat(WrongCat const &other);

		WrongCat &operator=(WrongCat const &other);

		void makeSound() const;
};

#endif
