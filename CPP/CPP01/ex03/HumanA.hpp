/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unmugviolet <unmugviolet@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 12:30:50 by unmugviolet       #+#    #+#             */
/*   Updated: 2025/05/07 12:56:17 by unmugviolet      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

#include "Weapon.hpp"
#include <iostream>
#include <string>

class	HumanA
{
	private :
		std::string name;
		Weapon		&weapon;

	public :
		HumanA();
		HumanA(std::string name, Weapon &weapon);
		~HumanA();
		void attack() const;
};

#endif
