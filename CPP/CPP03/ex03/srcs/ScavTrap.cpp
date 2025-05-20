/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjaguin <pjaguin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 10:42:59 by pjaguin           #+#    #+#             */
/*   Updated: 2025/05/20 14:53:25 by pjaguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(): ClapTrap()
{
	this->_health_points = 100;
	this->_energy_points = 50;
	this->_attack_damage = 20;
	this->_guarding_mode = false;
	std::cout << GREEN << "Default constructor called" << NEUTRAL << std::endl; 
}

ScavTrap::ScavTrap(std::string name): ClapTrap(name)
{
	this->_health_points = 100;
	this->_energy_points = 50;
	this->_attack_damage = 20;
	this->_guarding_mode = false;
	std::cout << GREEN << "ScavTrap constructor with name: " << this->_name << " called" << NEUTRAL << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << RED << "ScavTrap destructor called for " << this->_name << NEUTRAL << std::endl;
}

ScavTrap	&ScavTrap::operator=(ScavTrap const &other) 
{
	if (this != &other)
	{
		std::cout << "ScavTrap Assignation operator called" << std::endl;
		this->ClapTrap::operator=(other);
		this->_guarding_mode = other._guarding_mode;
	}
	return *this;
}

void	ScavTrap::guardGate()
{
	if (this->_health_points == 0)
	{
		std::cout << "🪦 ScavTrap " << this->_name << " cannot guard, already dead" << std::endl; 
		return ;
	}
	else if (this->_guarding_mode)
	{
		std::cout << "ScavTrap " << this->_name << " is already guarding the gate" << std::endl; 
		return ;
	}
	std::cout << " 🛡️ ScavTrap " << this->_name << " is now guarding the gate" << std::endl;
	this->_guarding_mode = true;
}

void	ScavTrap::attack(const std::string &target)
{
	if (this->_health_points == 0)
	{
		std::cout << "🪦 ScavTrap " << this->_name << " cannot be attacked, already dead" << std::endl; 
		return ;
	}
	else if (this->_energy_points == 0)
	{
		std::cout << "🪫 ScavTrap " << this->_name << " cannot attack, not enough energy" << std::endl; 
		return ;
	}
	std::cout	<< "🗡️ ScavTrap " << this->_name 
				<< " attacks " << target
				<< std::endl;
	this->_energy_points--;
}
