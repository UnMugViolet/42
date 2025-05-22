/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjaguin <pjaguin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 13:44:47 by pjaguin           #+#    #+#             */
/*   Updated: 2025/05/22 15:55:53 by pjaguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character(): _name("NoName")
{
	for (size_t i = 0; i < INVENTORY_SIZE; i++)
		this->_inventory[i] = NULL;
}

Character::Character(std::string const &name): _name(name)
{
	for (size_t i = 0; i < INVENTORY_SIZE; i++)
		this->_inventory[i] = NULL;
}

Character::Character(Character const &other)
{
	if (this != &other)
	{
		this->_name = other._name;
		for (size_t i = 0; i < INVENTORY_SIZE; i++)
		{
			this->_inventory[i] = other._inventory[i]->clone();
			if (other._inventory[i] == NULL)
				this->_inventory[i] = NULL;
			else
				this->_inventory[i] = other._inventory[i]->clone();
			
		}
	}
}

Character::~Character()
{
	for (size_t i = 0; i < INVENTORY_SIZE; i++)
	{
		if (this->_inventory[i])
			delete this->_inventory[i];
	}
}

Character &Character::operator=(Character const &other)
{
	if (this != &other)
	{
		this->_name = other._name;
		for (size_t i = 0; i < INVENTORY_SIZE; i++)
		{
			if (this->_inventory[i])
				delete this->_inventory[i];
			if (other._inventory[i] == NULL)
				this->_inventory[i] = NULL;
			else
				this->_inventory[i] = other._inventory[i]->clone();
		}
	}
	return *this;
}

void Character::equip(AMateria *m)
{
	if (m == NULL)
		return;
	for (size_t i = 0; i < INVENTORY_SIZE; i++)
	{
		if (this->_inventory[i] == NULL)
		{
			this->_inventory[i] = m;
			std::cout << this->_name << " equipped " << m->getType() << std::endl;
			return ;
		}
	}
	std::cout << RED << "Inventory is full cannot equip " << BOLD << UNDERLINE << m->getType() << NEUTRAL << std::endl; 
}

void Character::unequip(int idx)
{
	if (idx < 0 || idx >= INVENTORY_SIZE)
	{
		std::cout	<< RED << BOLD << UNDERLINE <<  idx  << NEUTRAL << RED
					<< " is an invalid index" << NEUTRAL << std::endl;
		return ;
	}
	if (this->_inventory[idx] == NULL)
	{
		std::cout << RED << "No materia to unequip at index " << BOLD << UNDERLINE << idx << NEUTRAL << std::endl;
		return ;
	}
	this->_inventory[idx] = NULL;
	std::cout << this->_name << " unequipped from inventory " << BOLD << UNDERLINE << _inventory[idx]->getType() << std::endl;
}

void	Character::use(int idx, ICharacter &target)
{
	if (this->_inventory[idx] && idx >= 0 && idx < INVENTORY_SIZE)
	{
		this->_inventory[idx]->use(target);
		return ;
	}
	std::cout << RED << "No materia to use at index " << BOLD << UNDERLINE << idx << NEUTRAL << std::endl;
}

// Getters

const std::string &Character::getName() const
{
	return this->_name;
}

AMateria *Character::getMateria(int idx) const
{
	if (idx < 0 || idx >= INVENTORY_SIZE)
	{
		std::cout << RED << "No materia to get at index " << BOLD << UNDERLINE << idx << NEUTRAL << std::endl;
		return NULL;
	}
	return this->_inventory[idx];
}
