/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unmugviolet <unmugviolet@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 11:25:37 by unmugviolet       #+#    #+#             */
/*   Updated: 2025/05/07 12:10:26 by unmugviolet      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <stdlib.h>

int main(int ac, char **av)
{
	std::string name = "Zombie";
	if (ac != 2 && ac != 3)
	{
		std::cout << "Usage: " << av[0] << " <number_of_zombies> " << "[option] <name>" << std::endl;
		return (1);
	}
	int N = std::atoi(av[1]);
	if (N <= 0 || N > 1000)
	{
		std::cout << "Com on you child... put a serious number" << std::endl;
		return (1);
	}
	if (ac == 3)
		name = av[2];

	Zombie* horde = zombieHorde(N, name);
	
	for (int i = 0; i < N; i++)
		horde[i].announce();
		
	delete[] horde;
	std::cout << "Horde nuked. " << N << " Zombies killed." << std::endl;
	return (0);
}
