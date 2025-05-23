/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjaguin <pjaguin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 16:21:12 by pjaguin           #+#    #+#             */
/*   Updated: 2025/05/23 07:04:40 by pjaguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(): _name("Default"), _health_points(10), _energy_points(10), _attack_damage(0)
{
	std::cout << GREEN << "Default constructor called" << NEUTRAL << std::endl; 
}

ClapTrap::ClapTrap(std::string name): _name(name), _health_points(10), _energy_points(10), _attack_damage(0)
{
	std::cout << GREEN << "ClapTrap constructor with name: " << _name << " called" << NEUTRAL << std::endl;
}

ClapTrap::ClapTrap(ClapTrap const &other)
{
	std::cout << GREEN << "ClapTrap copy constructor called" << NEUTRAL << std::endl;
	*this = other;
}

ClapTrap::~ClapTrap()
{
	std::cout << RED << "ClapTrap destructor called for " << _name << NEUTRAL << std::endl;
}

ClapTrap	&ClapTrap::operator=(ClapTrap const &other) 
{
	if (this != &other)
	{
		std::cout << "ClapTrap Assignation operator called" << std::endl;
		this->_name = other._name;
		this->_health_points = other._health_points;
		this->_energy_points = other._energy_points;
		this->_attack_damage = other._attack_damage;
	}
	return *this;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	unsigned int amount_lost = amount;

	if (this->_health_points == 0)
	{
		std::cout << "🪦 Claptrap " << this->_name << " cannot take more damage, already dead" << std::endl;
		return ;
	}
	else if (this->_energy_points == 0)
	{
		std::cout << "🪫 ClapTrap " << this->_name << " cannot take damage, not enough energy" << std::endl; 
		return ;
	}
	else if (amount > this->_health_points && this->_health_points != 0)
	{
		amount_lost = this->_health_points;
		this->_health_points = 0;
	}
	else if (amount > this->_health_points)
	{
		amount_lost = this->_health_points;
		this->_health_points = 0;
	}
	else
        this->_health_points -= amount_lost;
	std::cout	<< "💥 ClapTrap " << this->_name 
				<< " was hit and lost " << amount_lost
				<< " points of damage! Leaving him with "
				<< this->_health_points << " health points" 
				<< std::endl;
}

void	ClapTrap::attack(const std::string &target)
{
	if (this->_health_points == 0)
	{
		std::cout << "🪦 ClapTrap " << _name << " cannot be attacked, already dead" << std::endl; 
		return ;
	}
	std::cout	<< "🗡️ ClapTrap " << this->_name 
				<< " attacks " << target << std::endl;
	this->_energy_points--;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_energy_points == 0)
	{
		std::cout << "🪫 ClapTrap " << this->_name << " cannot be repaired, not enough energy" << std::endl; 
		return ;
	}
	else if (this->_health_points == 0)
	{
		std::cout << "🪦 ClapTrap " << this->_name << " cannot be repaired, already dead" << std::endl; 
		return ;
	}
	this->_health_points += amount;
	std::cout	<< "🧑‍🔧 ClapTrap " << this->_name 
				<< " has been repaired of " << amount
				<< ", now has " << this->_health_points << std::endl;
	this->_energy_points--;
}
