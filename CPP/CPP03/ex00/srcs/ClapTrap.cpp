/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjaguin <pjaguin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 16:21:12 by pjaguin           #+#    #+#             */
/*   Updated: 2025/05/19 18:13:43 by pjaguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(): _name("Didididiididiidier"), _health_points(10), _energy_points(10), _attack_damage(0)
{
}

ClapTrap::ClapTrap(std::string name): _name(name), _health_points(10), _energy_points(10), _attack_damage(0)
{
}

ClapTrap::~ClapTrap()
{
}

ClapTrap	&ClapTrap::operator=(ClapTrap const &other) 
{
	if (this != &other)
	{
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
	if (amount < 0)
		amount = 0;
	else if (amount > this->_health_points)
	{
		amount_lost = this->_health_points;
		this->_health_points = 0;
	}
	else if (this->_health_points <= 0)
	{
		std::cout	<< "ClapTrap" << this->_name 
					<< " was attacked and lost " << amount_lost
					<< " points of damage!" << std::endl;
		this->_health_points -= amount_lost;
	}
}

void	ClapTrap::attack(const std::string &target)
{
	if (this->_energy_points <= 0 && this->_health_points > 0)
	{
		std::cout << RED << "Cannot attack not enough energy" << NEUTRAL << std::endl; 
		return ;
	}
	std::cout	<< "ClapTrap " << this->_name 
				<< " attacks " << target 
				<< ", causing " << this->_attack_damage 
				<< " points of damage!" << std::endl;
	this->_energy_points--;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (amount < 0)
		amount = 0;
	if (this->_energy_points <= 0 && this->_health_points > 0)
	{
		std::cout << RED << "Cannot repair not enough energy" << NEUTRAL << std::endl; 
		return ;
	}
	std::cout	<< "ClapTrap" << this->_name 
				<< " has been repaired of " << amount
				<< ", now has " << this->_health_points << std::endl;
	this->_energy_points--;
}
