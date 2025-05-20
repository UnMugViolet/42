/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjaguin <pjaguin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 12:31:55 by pjaguin           #+#    #+#             */
/*   Updated: 2025/05/20 14:31:12 by pjaguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once


#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
{
	private:
		
	public:
		FragTrap();
		FragTrap(const FragTrap &other);
		FragTrap(std::string name);
		
		~FragTrap();

		FragTrap	&operator=(FragTrap const &other);
		
		void	highFivesGuys(void);
};


#endif
