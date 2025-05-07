/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unmugviolet <unmugviolet@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 12:30:05 by unmugviolet       #+#    #+#             */
/*   Updated: 2025/05/07 12:51:29 by unmugviolet      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

#include "HumanB.hpp"
#include "Weapon.hpp"

#include <iostream>
#include <string>

class HumanB
{
	private:
		std::string name;
		Weapon		*weapon;
	public:
		HumanB(std::string name);
		~HumanB();

		void attack() const;
		void setWeapon(Weapon &weapon);
};

#endif
