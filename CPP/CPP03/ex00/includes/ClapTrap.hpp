/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjaguin <pjaguin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 16:25:48 by pjaguin           #+#    #+#             */
/*   Updated: 2025/05/19 18:08:37 by pjaguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <iostream>

#define GREEN "\033[0;92m"
#define RED "\033[0;31m"
#define NEUTRAL "\033[0m"

class ClapTrap
{
	private:
		std::string _name;
		size_t	_health_points;
		size_t	_energy_points;
		size_t	_attack_damage;
	public:
		ClapTrap();
		ClapTrap(std::string name);
		~ClapTrap();
		
		ClapTrap	&operator=(ClapTrap const &other);

		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
};


# endif
