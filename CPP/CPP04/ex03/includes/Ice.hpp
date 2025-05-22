/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjaguin <pjaguin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 11:53:14 by pjaguin           #+#    #+#             */
/*   Updated: 2025/05/22 11:55:51 by pjaguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef ICE_HPP
# define ICE_HPP

# include "AMateria.hpp"

class Ice: public AMateria
{
	protected:
		std::string type;
		std::string effect;
		std::string target;
	public:
		Ice();
		Ice(Ice const &other);
		~Ice();

		Ice &operator=(Ice const &other);

		// Getters
		std::string const &getType() const;
};

#endif
