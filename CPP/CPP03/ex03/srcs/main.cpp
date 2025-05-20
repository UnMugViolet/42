/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjaguin <pjaguin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 16:20:36 by pjaguin           #+#    #+#             */
/*   Updated: 2025/05/20 15:49:21 by pjaguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int main(void)
{
	std::cout << "______________________Classic________________________" << std::endl;

	DiamondTrap a("A");
	DiamondTrap b("A-Clone");
	DiamondTrap c("C");

	b.whoAmI();
	b = a;
	b.whoAmI();
	a.attack("C");
	c.takeDamage(90);
}
