/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjaguin <pjaguin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 16:20:36 by pjaguin           #+#    #+#             */
/*   Updated: 2025/05/20 12:30:21 by pjaguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main(void)
{
	std::cout << "______________________Classic________________________" << std::endl;
	{	
		ScavTrap a("A");
		ScavTrap b("B");
		ScavTrap c;

		c = a;
		
		a.guardGate();
		a.guardGate();
		a.attack("B");
		b.takeDamage(90);
		b.beRepaired(1);
		a.attack("B");
		b.takeDamage(11);
		b.attack("A");
		a.takeDamage(100);
		b.guardGate();
		b.attack("A");
		a.takeDamage(1);
		a.beRepaired(1);
		a.attack("B");
		a.takeDamage(1);
	}
}
