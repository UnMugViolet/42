/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjaguin <pjaguin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 13:17:32 by pjaguin           #+#    #+#             */
/*   Updated: 2025/05/22 15:14:10 by pjaguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include "IMateriaSource.hpp"
# include "AMateria.hpp"
# include "Character.hpp"

# define MAX_MATERIA INVENTORY_SIZE
class	IMateriaSource;

class MateriaSource: public IMateriaSource
{
	private:
		AMateria *_inventory[MAX_MATERIA];
	public:
		MateriaSource();
		MateriaSource(MateriaSource const &other);

		~MateriaSource();

		MateriaSource &operator=(MateriaSource const &other);

		void learnMateria(AMateria*);
		AMateria* createMateria(std::string const & type);
};

#endif
