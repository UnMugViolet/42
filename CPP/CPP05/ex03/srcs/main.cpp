/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjaguin <pjaguin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 12:29:38 by pjaguin           #+#    #+#             */
/*   Updated: 2025/07/16 13:17:34 by pjaguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Intern.hpp"


int main(void)
{
	Bureaucrat bur1 = Bureaucrat("Guerandine", 150);
	Bureaucrat bur2 = Bureaucrat("Yvelon", 5);

	
	Intern intern;

	std::cout << YELLOW << "-----------------------------TESTS INTERM FORMS-----------------------------" << NEUTRAL << std::endl;
	AForm *form1 = intern.makeForm("ShrubberyCreationForm", "Terrasse");
	AForm *form2 = intern.makeForm("RobotomyRequestForm", "Robot");
	AForm *form3 = intern.makeForm("PresidentialPardonForm", "STEEEEEEEEEEEEEEEVEN");
	intern.makeForm("UnknownForm", "Target");


	try 
	{
		bur2.signForm(*form1);
		bur2.executeForm(*form1);

		bur2.signForm(*form2);
		bur2.executeForm(*form2);

		bur2.signForm(*form3);
		bur2.executeForm(*form3);

	} catch (const std::exception &e) 
	{
		std::cerr << RED  << "Exception: " << e.what() << NEUTRAL << std::endl;
	}
	
}
