/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjaguin <pjaguin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 16:20:36 by pjaguin           #+#    #+#             */
/*   Updated: 2025/05/23 08:13:50 by pjaguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int main(void)
{
	std::cout << "______________________Classic________________________" << std::endl;

	DiamondTrap a("A");
	DiamondTrap b("A-Clone");
	DiamondTrap *c = new DiamondTrap("C");
	DiamondTrap d(*c);
	DiamondTrap e;
	
	b = a;

	std::cout << std::endl << BOLD YELLOW << "Show stats of: " << a.getName() << NEUTRAL << std::endl;
	std::cout << "Health points: "  << a.getHealthPoints() << std::endl;
	std::cout << "Energy points: "  << a.getEnergyPoints() << std::endl;
	std::cout << "Attack damage: "  << a.getAttackDamage() << std::endl;

	std::cout << std::endl << BOLD YELLOW << "Test WhoamI: " << b.getName() << NEUTRAL << std::endl;
	b.whoAmI();

	std::cout << std::endl << BOLD YELLOW << "Test guard twice" << NEUTRAL << std::endl;
	c->guardGate();
	c->guardGate();

	std::cout << std::endl << BOLD YELLOW << "Test guard after death" << NEUTRAL << std::endl;
	a.attack("C");
	c->takeDamage(90);
	a.attack("C");
	c->takeDamage(90);
	c->guardGate();

/* 	std::cout << std::endl << BOLD YELLOW << "Test run out of energy on attacking self " << NEUTRAL << std::endl;
	for (int i = 0; i <= 24; i++)
	{
		a.attack("E");
		a.takeDamage(90);
		a.beRepaired(90);
	} */
	std::cout << std::endl;
	delete c;
}
