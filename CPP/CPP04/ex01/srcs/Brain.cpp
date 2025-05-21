/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjaguin <pjaguin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 17:35:21 by pjaguin           #+#    #+#             */
/*   Updated: 2025/05/21 16:20:14 by pjaguin          ###   ########.fr       */
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

Brain::Brain(Brain const &other)
{
	*this = other;
	std::cout << "Brain copy constructor called" << std::endl;
}

Brain &Brain::operator=(Brain const &other)
{
	if (this != &other)
	{
		for (int i = 0; i < 100; i++)
			this->ideas[i] = other.ideas[i];
	}
	std::cout << "Brain assignment operator called" << std::endl;
	return *this;
}

// Getters and Setters
std::string Brain::getIdeas() const
{
	return this->ideas[0];
}

void	Brain::setIdeas(std::string const &idea, size_t index)
{
	if (index < 100)
		this->ideas[index] = idea;
	else
		std::cout << RED << "Index out of range" << NEUTRAL << std::endl;
}
