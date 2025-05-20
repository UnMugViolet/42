/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjaguin <pjaguin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 13:15:52 by pjaguin           #+#    #+#             */
/*   Updated: 2025/05/20 15:29:08 by pjaguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(): ScavTrap(), FragTrap()
{
	this->_name += "_clap_name";
	this->_health_points = FragTrap::_health_points;
	this->_energy_points = ScavTrap::_energy_points;
	this->_attack_damage = FragTrap::_attack_damage;
}

DiamondTrap::DiamondTrap(std::string name): ScavTrap(), FragTrap()
{
	this->_name += name + "_clap_name";
	this->_health_points = FragTrap::_health_points;
	this->_energy_points = ScavTrap::_energy_points;
	this->_attack_damage = FragTrap::_attack_damage;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << RED << "DiamondTrap destructor called for " << this->_name << NEUTRAL << std::endl;
}

DiamondTrap	&DiamondTrap::operator=(DiamondTrap const &other)
{
	if (this != &other)
	{
		std::cout << "DiamondTrap Assignation operator called" << std::endl;
		this->ScavTrap::operator=(other);
		this->FragTrap::operator=(other);
		this->_name = other._name;
		this->_health_points = other._health_points;
		this->_energy_points = other._energy_points;
		this->_attack_damage = other._attack_damage;
	}
	return *this;
}

void	DiamondTrap::attack(std::string const &other)
{
	ScavTrap::attack(other);
}
 
void	DiamondTrap::whoAmI()
{
	std::cout << "DiamondTrap name: " << this->_name << std::endl;
}
