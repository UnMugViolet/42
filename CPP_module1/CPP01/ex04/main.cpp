/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjaguin <pjaguin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 14:31:47 by pjaguin           #+#    #+#             */
/*   Updated: 2025/05/13 18:29:12 by pjaguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FileHandler.hpp"

int main(int ac, char **av)
{
	FileHandler fileHandler;

	if (ac == 1)
		return (std::cout << ERR_USAGE << std::endl, 1);
	else if (ac != 4)
		return (std::cout << ERR_ARGS << std::endl, 1);
	fileHandler.replace(av[1], av[2], av[3]);
}
