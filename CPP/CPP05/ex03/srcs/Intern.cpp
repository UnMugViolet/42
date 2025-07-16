/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjaguin <pjaguin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 12:18:14 by pjaguin           #+#    #+#             */
/*   Updated: 2025/07/16 13:12:57 by pjaguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Intern.hpp"

Intern::Intern()
{
}

Intern::Intern(const Intern &other)
{
	(void)other;
}

Intern &Intern::operator=(const Intern &other)
{
	(void)other;
	return *this;
}

Intern::~Intern()
{
}

AForm *Intern::makeForm(const std::string &form_name, const std::string &form_target) const
{
	int index = 0;
	std::string forms[3] = {"ShrubberyCreationForm", "RobotomyRequestForm", "PresidentialPardonForm"};
	
	while (index < 3 && forms[index] != form_name)
		index++;
	switch (index)
	{
		case 0:
			std::cout << GREEN << "Intern creates a ShrubberyCreationForm" << NEUTRAL << std::endl;
			return new ShrubberyCreationForm(form_target);
		case 1:
			std::cout << GREEN << "Intern creates a RobotomyRequestForm" << NEUTRAL << std::endl;
			return new RobotomyRequestForm(form_target);
		case 2:
			std::cout << GREEN << "Intern creates a PresidentialPardonForm" << NEUTRAL << std::endl;
			return new PresidentialPardonForm(form_target);
		default:
			std::cout << RED << "Intern cannot create form: " << form_name << NEUTRAL << std::endl;
			return NULL;
	}
	return NULL;
}
