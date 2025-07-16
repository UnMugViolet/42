/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjaguin <pjaguin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 12:29:38 by pjaguin           #+#    #+#             */
/*   Updated: 2025/07/16 12:11:49 by pjaguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main(void)
{
	Bureaucrat bur1 = Bureaucrat("Guerandine", 150);
	Bureaucrat bur2 = Bureaucrat("Yvelon", 5);

	ShrubberyCreationForm form1("Yvelon");
	RobotomyRequestForm form2("Robotomy");
	PresidentialPardonForm form3("STEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEVEN");
	std::cout << YELLOW << "-----------------------------CREATION NORMAL-----------------------------" << NEUTRAL << std::endl;
	try
	{
		std::cout << BOLD << "Created :" << std::endl << NEUTRAL 
					<< bur1 << std::endl << std::endl
					<< bur2 << std::endl;
		std::cout << BOLD << "Created :" << std::endl 
			<< NEUTRAL << form1 << std::endl
			<< form2 << std::endl
			<< form3 << NEUTRAL << std::endl;
		bur2.signForm(form1);
		bur2.executeForm(form1);
		std::cout << BOLD << std::endl << "After signing :" << std::endl << NEUTRAL << form1 << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << RED  << "Exception: " << e.what() << NEUTRAL << std::endl;
	}

	std::cout << std::endl << YELLOW << "------------------------FAILING SIGN FORM-------------------------" << NEUTRAL << std::endl;
	try {
		ShrubberyCreationForm form1("Shrubbery");
		std::cout << BOLD << "Created :" << std::endl 
					<< NEUTRAL << form1 << std::endl;
		bur1.signForm(form1);
	}
	catch (const std::exception &e) {
		std::cerr << RED  << "Exception: " << e.what() << NEUTRAL << std::endl;
	}

	std::cout << std::endl << YELLOW << "------------------------FAILING EXEC FORM-------------------------" << NEUTRAL << std::endl;
	try {
		bur2.signForm(form1); // 5
		bur1.executeForm(form1); // 150
	}
	catch (const std::exception &e) {
		std::cerr << RED  << "Exception: " << e.what() << NEUTRAL << std::endl;
	}
	
	try {
		bur2.signForm(form1);
		bur1.executeForm(form1);
	}
	catch (const std::exception &e) {
		std::cerr << RED  << "Exception: " << e.what() << NEUTRAL << std::endl;
	}

	std::cout << std::endl << YELLOW << "------------------------SUCCESS SIGN FORM-------------------------" << NEUTRAL << std::endl;
	try
	{
		for (int i = 0; i < 5; i++)
			bur1.incrementGrade();
		ShrubberyCreationForm form1("Formulaire 1");
		bur1.signForm(form1);
	}
	catch (const std::exception &e)
	{
		std::cerr << RED  << "Exception: " << e.what() << NEUTRAL << std::endl;
	}

	std::cout << std::endl << YELLOW << "------------------------SUCCESS EXEC FORM-------------------------" << NEUTRAL << std::endl;
	try
	{
		for (int i = 0; i < 13; i++)
			bur1.incrementGrade();
		ShrubberyCreationForm form1("Shrubbery");
		bur1.signForm(form1);
		bur1.executeForm(form1);
	}
	catch (const std::exception &e)
	{
		std::cerr << RED  << "Exception: " << e.what() << NEUTRAL << std::endl;
	}
	
	std::cout << std::endl << YELLOW << "------------------------TEST ROBOTOMY FORM-------------------------" << NEUTRAL << std::endl;
	try
	{
		bur2.signForm(form2);
		bur2.executeForm(form2);
	}
	catch (const std::exception &e)
	{
		std::cerr << RED  << "Exception: " << e.what() << NEUTRAL << std::endl;
	}

	std::cout << std::endl << YELLOW << "------------------------TEST PRESIDENTIAL FORM-------------------------" << NEUTRAL << std::endl;
	try
	{
		bur2.signForm(form3);
		bur2.executeForm(form3);
	}
	catch (const std::exception &e)
	{
		std::cerr << RED  << "Exception: " << e.what() << NEUTRAL << std::endl;
	}
}
