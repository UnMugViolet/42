/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjaguin <pjaguin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 17:35:37 by pjaguin           #+#    #+#             */
/*   Updated: 2025/05/23 12:25:05 by pjaguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef BRAIN_HPP
# define BRAIN_HPP

#include "dict.hpp"
#include <iostream>
#include <string>

class Brain
{
	private:
		std::string ideas[100];
	public:
		Brain();
		Brain(Brain const &other);

		virtual ~Brain();
		
		Brain &operator=(Brain const &other);
	
		// Getters and Setters
		std::string getIdeas(int index);
		void setIdeas(std::string const &idea, size_t index);
};

# endif
