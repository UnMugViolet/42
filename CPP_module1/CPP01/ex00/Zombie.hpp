/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unmugviolet <unmugviolet@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 10:14:49 by unmugviolet       #+#    #+#             */
/*   Updated: 2025/05/07 10:29:58 by unmugviolet      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

class Zombie 
{
	private:
		std::string	name;
	public:
		Zombie();
		Zombie( std::string name );
		~Zombie();
		void 		announce(void);
};

Zombie	*newZombie( std::string name );
void 	randomChump( std::string name );
