/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjaguin <pjaguin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 11:41:51 by pjaguin           #+#    #+#             */
/*   Updated: 2025/05/22 16:43:38 by pjaguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include "ICharacter.hpp"
# include "AMateria.hpp"
# include "dict.hpp"

#define INVENTORY_SIZE 4

class ICharacter;

class Character: virtual public ICharacter
{
	private:
		std::string _name;
		AMateria *_inventory[INVENTORY_SIZE];
	public:
		Character();
		Character(std::string const &name);
		Character(Character const &other);

		~Character();

		Character &operator=(Character const &other);
		
		void equip(AMateria* m);
		void unequip(int idx);
		void use(int idx, ICharacter& target);
		
		std::string const &getName() const;
		AMateria*	getMateria(int idx) const;

		size_t getInventorySize() const;
};

#endif
