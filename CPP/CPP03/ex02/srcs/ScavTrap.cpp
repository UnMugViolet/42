/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjaguin <pjaguin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 10:42:59 by pjaguin           #+#    #+#             */
/*   Updated: 2025/05/23 07:14:16 by pjaguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(): ClapTrap()
{
	this->ClapTrap::setHealthPoints(100);
	this->ClapTrap::setEnergyPoints(50);
	this->ClapTrap::setAttackDamage(20);
	this->_guarding_mode = false;
	std::cout << GREEN << "Default constructor called" << NEUTRAL << std::endl; 
}

ScavTrap::ScavTrap(std::string name): ClapTrap(name)
{
	this->ClapTrap::setHealthPoints(100);
	this->ClapTrap::setEnergyPoints(50);
	this->ClapTrap::setAttackDamage(20);
	this->_guarding_mode = false;
	std::cout << GREEN << "ScavTrap constructor with name: " << this->ClapTrap::getName() << " called" << NEUTRAL << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &other): ClapTrap(other)
{
	std::cout << GREEN << "ScavTrap copy constructor called" << NEUTRAL << std::endl;
	*this = other;
}

ScavTrap::~ScavTrap()
{
	std::cout << RED << "ScavTrap destructor called for " << this->ClapTrap::getName() << NEUTRAL << std::endl;
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
	if (this->ClapTrap::getHealthPoints() == 0)
	{
		std::cout << "🪦 ScavTrap " << this->ClapTrap::getName() << " cannot guard, already dead" << std::endl; 
		return ;
	}
	else if (this->_guarding_mode)
	{
		std::cout << "ScavTrap " << this->ClapTrap::getName() << " is already guarding the gate" << std::endl; 
		return ;
	}
	std::cout << " 🛡️ ScavTrap " << this->ClapTrap::getName() << " is now guarding the gate" << std::endl;
	this->_guarding_mode = true;
}

void	ScavTrap::attack(const std::string &target)
{
	size_t energy_points = this->ClapTrap::getEnergyPoints();

	if (this->ClapTrap::getHealthPoints() == 0)
	{
		std::cout << "🪦 ScavTrap " << this->ClapTrap::getName() << " cannot be attacked, already dead" << std::endl; 
		return ;
	}
	else if (this->ClapTrap::getEnergyPoints() == 0)
	{
		std::cout << "🪫 ScavTrap " << this->ClapTrap::getName() << " cannot attack, not enough energy" << std::endl; 
		return ;
	}
	std::cout	<< "🗡️ ScavTrap " << this->ClapTrap::getName() 
				<< " attacks " << target
				<< std::endl;
	this->ClapTrap::setEnergyPoints(energy_points--);
}
