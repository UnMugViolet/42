/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unmugviolet <unmugviolet@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 12:22:39 by unmugviolet       #+#    #+#             */
/*   Updated: 2025/05/07 13:09:30 by unmugviolet      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include "HumanB.hpp"

int main(void)
{
	Weapon napkin = Weapon("napkin");
	Weapon fork = Weapon("fork");
	HumanA Dididier("Dididier", napkin);
	HumanB Tututututu("Tututututu");
	
	Dididier.attack();
	napkin.setType("feather");
	Dididier.attack();

	Tututututu.setWeapon(fork);
	Tututututu.attack();
	fork.setType("spoon");
	Tututututu.attack();
	Dididier.attack();
}

