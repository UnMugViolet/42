/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjaguin <pjaguin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 12:29:38 by pjaguin           #+#    #+#             */
/*   Updated: 2025/07/15 14:01:06 by pjaguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main(void)
{
	std::cout << YELLOW << "--------------------CREATION NORMAL--------------------" << NEUTRAL << std::endl;
	try
	{
		Bureaucrat bur1 = Bureaucrat("Guerandine", 5);
		std::cout << BOLD << "Created :" << std::endl << NEUTRAL << GREEN << bur1 << NEUTRAL << std::endl;
		Bureaucrat bur2 = Bureaucrat("Christambert", 1);
		std::cout << BOLD << "Created :" << std::endl << NEUTRAL << GREEN << bur2 << NEUTRAL << std::endl;
			Bureaucrat bur3 = Bureaucrat("Chantery", 150);
		std::cout << BOLD << "Created :" << std::endl << NEUTRAL << GREEN << bur3 << NEUTRAL << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << RED << UNDERLINE << "Exception: " << e.what() << NEUTRAL << std::endl;
	}

	std::cout << YELLOW << "--------------------CREATION TESTS--------------------" << NEUTRAL << std::endl;
	try
	{
		Bureaucrat bur2 = Bureaucrat("Yvelon", 0);
	}
	catch (const std::exception &e)
	{
		std::cerr << RED << "Exception: " << e.what() << NEUTRAL << std::endl;
	}
	try
	{
		Bureaucrat bur2 = Bureaucrat("Yvelon", 151);
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << "Exception: " << e.what() << NEUTRAL << std::endl;
	}
	
	std::cout << YELLOW << "--------------------INCREMENT TESTS--------------------" << NEUTRAL << std::endl;
	try
	{
		Bureaucrat bur2 = Bureaucrat("Yvelon", 1);
		std::cout << BOLD << "Created :" << std::endl << NEUTRAL << GREEN << bur2 << NEUTRAL << std::endl;
		bur2.incrementGrade();
	}
	catch (const std::exception &e)
	{
		std::cerr << RED << "Exception: " << e.what() << NEUTRAL << std::endl;
	}
	
	std::cout << YELLOW << "--------------------DECREMENT TESTS--------------------" << NEUTRAL << std::endl;
	try
	{
		Bureaucrat bur2 = Bureaucrat("Yvelon", 149);
		std::cout << BOLD << "Created :" << std::endl << NEUTRAL << GREEN << bur2 << NEUTRAL << std::endl;
		bur2.decrementGrade();
		bur2.decrementGrade();
	}
	catch (const std::exception &e)
	{
		std::cerr << RED << "Exception: " << e.what() << NEUTRAL << std::endl;
	}

	std::cout << YELLOW << "--------------------COPY TESTS--------------------" << NEUTRAL << std::endl;
	try
	{
		Bureaucrat bur3 = Bureaucrat("Yvelon", 50);
		std::cout << BOLD << "Created :" << std::endl << NEUTRAL << GREEN << bur3 << NEUTRAL << std::endl;
		Bureaucrat bur4 = Bureaucrat(bur3);
		std::cout << BOLD << "Copied :" << std::endl << NEUTRAL << GREEN << bur4 << NEUTRAL << std::endl;
		bur4.incrementGrade();
		std::cout << BOLD << "After increment :" << std::endl << NEUTRAL << GREEN << bur4 << NEUTRAL << std::endl;
		bur3.decrementGrade();
		std::cout << BOLD << "After decrement :" << std::endl << NEUTRAL << GREEN << bur3 << NEUTRAL << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << RED << "Exception: " << e.what() << NEUTRAL << std::endl;
	}
}
