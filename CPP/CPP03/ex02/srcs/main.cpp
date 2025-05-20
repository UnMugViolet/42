/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjaguin <pjaguin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 16:20:36 by pjaguin           #+#    #+#             */
/*   Updated: 2025/05/20 13:04:19 by pjaguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int main(void)
{
	std::cout << "______________________Classic________________________" << std::endl;
	{	
		FragTrap a("A");
		FragTrap b("A-Clone");
		FragTrap c("C");

		b = a;

		a.highFivesGuys();
		a.highFivesGuys();
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
/* 	std::cout << "______________________For loop________________________" << std::endl;
	{
		FragTrap a("A");
		FragTrap c("C");

		for (int i = 0; i <= 50; i++)
		{			
			a.attack("C");
			c.takeDamage(90);
			c.beRepaired(90);
		}
	} */
}
