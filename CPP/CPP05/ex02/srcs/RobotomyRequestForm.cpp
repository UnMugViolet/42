/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjaguin <pjaguin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 10:46:44 by pjaguin           #+#    #+#             */
/*   Updated: 2025/07/16 11:06:49 by pjaguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm (): AForm("RobotomyRequestForm", 72, 45), _target("Default Target")
{
}


RobotomyRequestForm::RobotomyRequestForm (const std::string target): AForm("RobotomyRequestForm", 72, 45), _target(target)
{
}

RobotomyRequestForm::RobotomyRequestForm (RobotomyRequestForm const &other)
{
	*this = other;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm const &other)
{
	if (this != &other)
	{
		AForm::operator=(other);
		this->_target = other._target;
		setIsSigned(other.isSigned());
	}
	return *this;
}

void RobotomyRequestForm::performAction() const
{
	std::cout << "Bzzzzzz... " << std::endl;
	srand(time(0));
	if (rand() % 2)
		std::cout << GREEN << BOLD << this->_target << " has been robotomized successfully." << NEUTRAL << std::endl;
	else
		throw RobotomyRequestForm::RobotomyFailureException();
}


const char *RobotomyRequestForm::RobotomyFailureException::what() const throw()
{
	return "Robotomy failed, not your fault, just bad luck.";
}

RobotomyRequestForm::~RobotomyRequestForm ()
{
}
