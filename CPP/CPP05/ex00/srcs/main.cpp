/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjaguin <pjaguin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 12:29:38 by pjaguin           #+#    #+#             */
/*   Updated: 2025/07/11 15:24:35 by pjaguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main(void)
{
	std::string const name = "QWERTYUIOP";
	Bureaucrat *a = new Bureaucrat(name, 151);

	std::cout << UNDERLINE << a->getName() << NEUTRAL << std::endl;
	std::cout << UNDERLINE << a->getGrade() << NEUTRAL << std::endl;
	
	delete a;
}
