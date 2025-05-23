/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjaguin <pjaguin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 12:50:44 by pjaguin           #+#    #+#             */
/*   Updated: 2025/05/23 07:22:41 by pjaguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(): ClapTrap()
{
	this->_health_points = 100;
	this->_energy_points = 100;
	this->_attack_damage = 30;
	std::cout << GREEN << "Default constructor called" << NEUTRAL << std::endl; 
}

FragTrap::FragTrap(std::string name): ClapTrap(name)
{
	this->_health_points = 100;
	this->_energy_points = 100;
	this->_attack_damage = 30;
	std::cout << GREEN << "FragTrap constructor with name: " << this->_name  << " called" << NEUTRAL << std::endl;
}

FragTrap::FragTrap(const FragTrap &other): ClapTrap(other)
{
	std::cout << GREEN << "FragTrap copy constructor called" << NEUTRAL << std::endl;
	*this = other;
}

FragTrap::~FragTrap()
{
	std::cout << RED << "FragTrap destructor called for " << this->_name  << NEUTRAL << std::endl;
}

FragTrap	&FragTrap::operator=(FragTrap const &other) 
{
	if (this != &other)
	{
		std::cout << GREEN << "FragTrap Assignation operator called" << NEUTRAL << std::endl;
		this->ClapTrap::operator=(other);
	}
	return *this;
}

void	FragTrap::highFivesGuys(void)
{
	std::cout << "🤚 FragTrap " << this->_name  << " is asking for a high five!" << std::endl;
}
