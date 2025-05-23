/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjaguin <pjaguin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 16:20:36 by pjaguin           #+#    #+#             */
/*   Updated: 2025/05/23 07:06:00 by pjaguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main(void)
{
	std::cout << "______________________Classic________________________" << std::endl;
	{	
		ClapTrap a("A");
		ClapTrap b("A-Clone");
		ClapTrap c("C");
		ClapTrap d(c);

		b = a;

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
		ClapTrap a("A");
		ClapTrap b("B");

		for (int i = 0; i <= 10; i++)
		{			
			a.attack("C");
			b.takeDamage(9);
			b.beRepaired(9);
		}
	}
}
