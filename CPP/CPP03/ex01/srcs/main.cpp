/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjaguin <pjaguin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 16:20:36 by pjaguin           #+#    #+#             */
/*   Updated: 2025/05/23 07:07:02 by pjaguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main(void)
{
	std::cout << "______________________Classic________________________" << std::endl;
	{	
		ScavTrap a("A");
		ScavTrap b("A-Clone");
		ScavTrap c("C");
		ScavTrap d(c);

		b = a;

		a.guardGate();
		a.guardGate();
		a.attack("C");
		c.takeDamage(9);
		c.attack("A");
		a.takeDamage(10);
		// a A just died cannot perform any other action
		a.attack("C");
		c.takeDamage(0);
		a.beRepaired(1);
		c.beRepaired(9);
		
		// a is dead b is kepping up
		b.attack("C");
		c.takeDamage(11);
		b.beRepaired(1);		
	}
	std::cout << "______________________For loop________________________" << std::endl;
	{
		ScavTrap a("A");
		ScavTrap c("C");

		for (int i = 0; i <= 50; i++)
		{			
			a.attack("C");
			c.takeDamage(90);
			c.beRepaired(90);
		}
	}
}
