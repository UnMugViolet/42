/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjaguin <pjaguin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 10:42:59 by pjaguin           #+#    #+#             */
/*   Updated: 2025/05/20 11:29:00 by pjaguin          ###   ########.fr       */
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

ScavTrap::~ScavTrap()
{
	std::cout << RED << "ScavTrap destructor called for " << this->ClapTrap::getName() << NEUTRAL << std::endl;
}

