/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjaguin <pjaguin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 10:42:34 by pjaguin           #+#    #+#             */
/*   Updated: 2025/05/23 07:16:27 by pjaguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
	private:
		bool _guarding_mode;
	public:
		ScavTrap();
		ScavTrap(const ScavTrap &other);
		ScavTrap(std::string name);
		
		virtual ~ScavTrap();
		
		ScavTrap	&operator=(ScavTrap const &other);

		void attack(const std::string &target);
		void guardGate();
};

#endif
