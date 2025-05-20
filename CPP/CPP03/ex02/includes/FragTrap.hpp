/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjaguin <pjaguin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 12:31:55 by pjaguin           #+#    #+#             */
/*   Updated: 2025/05/20 13:04:50 by pjaguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
	private:
		
	public:
		FragTrap();
		FragTrap(const FragTrap &other);
		FragTrap(std::string name);
		virtual ~FragTrap();
		
		FragTrap	&operator=(FragTrap const &other);
		
		void	highFivesGuys(void);
};


#endif
