/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjaguin <pjaguin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 17:35:37 by pjaguin           #+#    #+#             */
/*   Updated: 2025/05/21 16:20:40 by pjaguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef BRAIN_HPP
# define BRAIN_HPP

#include "Animal.hpp"
#include "dict.hpp"

class Brain
{
	private:
		std::string ideas[100];
	public:
		Brain();
		virtual ~Brain();
		Brain(Brain const &other);
		
		Brain &operator=(Brain const &other);
	
		std::string getIdeas() const;
		void setIdeas(std::string const &idea, size_t index);
};

# endif
