/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjaguin <pjaguin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 17:35:37 by pjaguin           #+#    #+#             */
/*   Updated: 2025/05/20 17:39:36 by pjaguin          ###   ########.fr       */
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
		~Brain();
};

# endif
