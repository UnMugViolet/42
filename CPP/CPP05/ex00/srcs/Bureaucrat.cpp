/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjaguin <pjaguin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 12:29:35 by pjaguin           #+#    #+#             */
/*   Updated: 2025/07/11 15:22:13 by pjaguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Bureaucrat.hpp"


Bureaucrat::Bureaucrat(std::string const name, int grade): _name(name)
{
	if (grade < 1 || grade > 150)
		this->_grade = grade;
	else
		std::cout << "Naaaah" << std::endl;
}

Bureaucrat::Bureaucrat(Bureaucrat const &other)
{
	this->_grade = other._grade;
	std::cout << GREEN << "Bureaucrat copy constructor called" << NEUTRAL << std::endl;
}

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &other)
{
	if (this != &other)
	{
		this->_grade = other._grade;
	}
	std::cout << GREEN << "Bureaucrat assignement operator called" << NEUTRAL << std::endl;
	return *this;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << RED << "Bureauctrat destructor called" << NEUTRAL << std::endl;
}

std::string Bureaucrat::getName() const 
{
	return this->_name;
}

int		Bureaucrat::getGrade()
{
	return this->_grade;
}
