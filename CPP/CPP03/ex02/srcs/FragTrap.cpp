/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjaguin <pjaguin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 12:50:44 by pjaguin           #+#    #+#             */
/*   Updated: 2025/05/23 07:14:07 by pjaguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(): ClapTrap()
{
	this->ClapTrap::setHealthPoints(100);
	this->ClapTrap::setEnergyPoints(100);
	this->ClapTrap::setAttackDamage(30);
	std::cout << GREEN << "Default constructor called" << NEUTRAL << std::endl; 
}

FragTrap::FragTrap(std::string name): ClapTrap(name)
{
	this->ClapTrap::setHealthPoints(100);
	this->ClapTrap::setEnergyPoints(100);
	this->ClapTrap::setAttackDamage(30);
	std::cout << GREEN << "FragTrap constructor with name: " << this->ClapTrap::getName() << " called" << NEUTRAL << std::endl;
}

FragTrap::FragTrap(const FragTrap &other): ClapTrap(other)
{
	std::cout << GREEN << "FragTrap copy constructor called" << NEUTRAL << std::endl;
	*this = other;
}

FragTrap::~FragTrap()
{
	std::cout << RED << "FragTrap destructor called for " << this->ClapTrap::getName() << NEUTRAL << std::endl;
}

FragTrap	&FragTrap::operator=(FragTrap const &other) 
{
	if (this != &other)
	{
		std::cout << "FragTrap Assignation operator called" << std::endl;
		this->ClapTrap::operator=(other);
	}
	return *this;
}

void	FragTrap::highFivesGuys(void)
{
	std::cout << "🤚 FragTrap " << this->ClapTrap::getName() << " is asking for a high five!" << std::endl;
}
