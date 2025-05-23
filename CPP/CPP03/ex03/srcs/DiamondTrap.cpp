/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjaguin <pjaguin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 13:15:52 by pjaguin           #+#    #+#             */
/*   Updated: 2025/05/23 08:08:19 by pjaguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(): ClapTrap("Defaut_clap_trap")
{
	this->_name = "Default";
	this->_health_points = FragTrap::_health_points;
	this->_energy_points = ScavTrap::_energy_points;
	this->_attack_damage = FragTrap::_attack_damage;
}

DiamondTrap::DiamondTrap(std::string name): ClapTrap(name + "_clap_trap")
{
	this->_name = name;
	this->_health_points = FragTrap::_health_points;
	this->_energy_points = ScavTrap::_energy_points;
	this->_attack_damage = FragTrap::_attack_damage;
}

DiamondTrap::DiamondTrap(const DiamondTrap &other): ClapTrap(other), FragTrap(other), ScavTrap(other)
{
	std::cout << GREEN << "DiamondTrap copy constructor called" << NEUTRAL << std::endl;
	*this = other;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << RED << "DiamondTrap destructor called for " << this->_name << NEUTRAL << std::endl;
}

DiamondTrap	&DiamondTrap::operator=(DiamondTrap const &other)
{
	if (this != &other)
	{
		std::cout << GREEN  << "DiamondTrap Assignation operator called" << NEUTRAL  << std::endl;
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

size_t	DiamondTrap::getHealthPoints() const
{
	return this->_health_points;
}

size_t	DiamondTrap::getEnergyPoints() const
{
	return this->_energy_points;
}

size_t	DiamondTrap::getAttackDamage() const
{
	return this->_attack_damage;
}

std::string DiamondTrap::getName() const
{
    return this->_name;
}
