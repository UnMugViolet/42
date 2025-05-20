/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjaguin <pjaguin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 17:35:21 by pjaguin           #+#    #+#             */
/*   Updated: 2025/05/20 17:39:26 by pjaguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
	std::cout << GREEN << "Brain default constructor called" << NEUTRAL << std::endl;
}

Brain::~Brain()
{
	std::cout << RED << "Brain destructor called" << NEUTRAL << std::endl;
}

