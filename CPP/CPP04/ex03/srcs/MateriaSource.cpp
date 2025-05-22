/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjaguin <pjaguin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 15:08:11 by pjaguin           #+#    #+#             */
/*   Updated: 2025/05/22 15:_inventory19:00 by pjaguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "MateriaSource.hpp"
# include "dict.hpp"

MateriaSource::MateriaSource()
{
	for (size_t i = 0; i < MAX_MATERIA; i++)
		this->_inventory[i] = NULL;
}

MateriaSource::MateriaSource(MateriaSource const &other): IMateriaSource()
{
	if (this != &other)
	{
		for (size_t i = 0; i < MAX_MATERIA; i++)
		{
			if (other._inventory[i])
				this->_inventory[i] = other._inventory[i]->clone();
			else
				this->_inventory[i] = NULL;
		}
	}
}

MateriaSource::~MateriaSource()
{
	for (size_t i = 0; i < MAX_MATERIA; i++)
	{
		if (this->_inventory[i])
			delete this->_inventory[i];
	}
}

MateriaSource &MateriaSource::operator=(MateriaSource const &other)
{
	if (this != &other)
	{
		for (size_t i = 0; i < MAX_MATERIA; i++)
		{
			if (this->_inventory[i])
				delete this->_inventory[i];
			if (other._inventory[i])
				this->_inventory[i] = other._inventory[i]->clone();
			else
				this->_inventory[i] = NULL;
		}
	}
	return *this;
}

void MateriaSource::learnMateria(AMateria *materia)
{
	for (size_t i = 0; i < MAX_MATERIA; i++)
	{
		if (this->_inventory[i] == NULL)
		{
			this->_inventory[i] = materia;
			return ;
		}
	}
	std::cout << RED << "Inventory is full, cannot learn " << BOLD << UNDERLINE << materia->getType() << NEUTRAL << std::endl;
}

AMateria	*MateriaSource::createMateria(std::string const &type)
{
	for (size_t i = 0; i < MAX_MATERIA; i++)
	{
		if (this->_inventory[i] && this->_inventory[i]->getType() == type)
			return this->_inventory[i]->clone();
	}
	return NULL;
}
