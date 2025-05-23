/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjaguin <pjaguin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 13:10:54 by pjaguin           #+#    #+#             */
/*   Updated: 2025/05/23 08:03:19 by pjaguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# include "ScavTrap.hpp"
# include "FragTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap
{
	private:
		std::string _name;
	public:
		DiamondTrap();
		DiamondTrap(std::string name);
		DiamondTrap(const DiamondTrap &other);

		~DiamondTrap();
		
		DiamondTrap	&operator=(DiamondTrap const &other);
		
		void attack(const std::string &target);
		void whoAmI();

		// Getters
		size_t getHealthPoints() const;
		size_t getEnergyPoints() const;
		size_t getAttackDamage() const;
		std::string getName() const;
};

#endif
