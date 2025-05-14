/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unmugviolet <unmugviolet@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 10:17:29 by unmugviolet       #+#    #+#             */
/*   Updated: 2025/05/07 10:58:08 by unmugviolet      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	std::cout << "/*------------------ Creating zombies on Heap ------------------*/" << std::endl;
	Zombie	*zombie1 = newZombie("Dididier");
	Zombie	*zombie2 = newZombie("Tututuututututu");
	
	zombie1->announce();
	zombie2->announce();
	
	delete zombie1;
	delete zombie2;

	std::cout << "-------------------------------------------------------------------" << std::endl << std::endl;

	std::cout << "/*------------------ Creating zombies on Stack ------------------*/" << std::endl;
	Zombie	zombie3;
	Zombie	zombie4("Dididier la legende");
	
	zombie3.announce();
	zombie4.announce();
	randomChump("Dididier2 la legende");
	std::cout << "-------------------------------------------------------------------" << std::endl;

}
