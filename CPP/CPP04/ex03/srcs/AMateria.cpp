/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjaguin <pjaguin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 12:03:34 by pjaguin           #+#    #+#             */
/*   Updated: 2025/05/22 14:19:30 by pjaguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria(): type("No type")
{
}

AMateria::AMateria(std::string const &type): type(type)
{
}

AMateria::AMateria(AMateria const &other)
{
	if (this != &other)
		this->type = other.type;
}

AMateria::~AMateria()
{
}

AMateria &AMateria::operator=(AMateria const &other)
{
	if (this != &other)
		this->type = other.type;
	return *this;
}
