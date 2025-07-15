/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjaguin <pjaguin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 12:29:38 by pjaguin           #+#    #+#             */
/*   Updated: 2025/07/15 17:47:19 by pjaguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main(void)
{
	std::cout << YELLOW << "-----------------------------CREATION NORMAL-----------------------------" << NEUTRAL << std::endl;
	try
	{
		Bureaucrat bur1 = Bureaucrat("Guerandine", 5);
		Form form1("Formulaire 1", 5, 10);
		std::cout << BOLD << "Created :" << std::endl << NEUTRAL << GREEN << bur1 << NEUTRAL << std::endl;
		std::cout << BOLD << "Created :" << std::endl << NEUTRAL << GREEN << form1 << NEUTRAL << std::endl;
		bur1.signForm(form1);
		std::cout << BOLD << std::endl << "After signing :" << std::endl << NEUTRAL << GREEN << form1 << NEUTRAL << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << RED  << "Exception: " << e.what() << NEUTRAL << std::endl;
	}
	std::cout << std::endl << YELLOW << "------------------------CREATE FAILING BUREAUCRATS-------------------------" << NEUTRAL << std::endl;
	try {
		Bureaucrat bur1 = Bureaucrat("Guerandine", 0);	
	} catch (const std::exception &e) {
		std::cerr << RED  << "Exception: " << e.what() << NEUTRAL << std::endl;
	}
	try {
		Bureaucrat bur2 = Bureaucrat("Guerandine", 151);	
	} catch (const std::exception &e) {
		std::cerr << RED  << "Exception: " << e.what() << NEUTRAL << std::endl;
	}
	std::cout << std::endl << YELLOW << "---------------------------CREATE FAILING FORMS----------------------------" << NEUTRAL << std::endl;
	try {
		Form form1 = Form("Failing form", 151, 1);	
	} catch (const std::exception &e) {
		std::cerr << RED  << "Exception: " << e.what() << NEUTRAL << std::endl;
	}
	try {
		Form form1 = Form("Failing form", 0, 1);	
	} catch (const std::exception &e) {
		std::cerr << RED  << "Exception: " << e.what() << NEUTRAL << std::endl;
	}
	std::cout << std::endl << YELLOW << "---------------------------SIGN FORM LOW LEVEL------------------------------" << NEUTRAL << std::endl;
	try
	{
		Bureaucrat bur2 = Bureaucrat("Guerandine", 2);
		std::cout << BOLD << "Created :" << std::endl << NEUTRAL << GREEN << bur2 << NEUTRAL << std::endl;
		
		Form form2("Formulaire 2", 1, 10);
		std::cout << BOLD << "Created :" << std::endl << NEUTRAL << GREEN << form2 << NEUTRAL << std::endl;
		bur2.signForm(form2);
		std::cout << BOLD << "After signing :" << std::endl << NEUTRAL << GREEN << form2 << NEUTRAL << std::endl;
		std::cout << BOLD << "Getting a promotion" << NEUTRAL << std::endl;
		bur2.incrementGrade();
		bur2.signForm(form2);
		std::cout << BOLD << "After signing :" << std::endl << NEUTRAL << GREEN << form2 << NEUTRAL << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << RED << "Exception: " << e.what() << NEUTRAL << std::endl;
	}
}
