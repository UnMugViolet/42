/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjaguin <pjaguin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 12:29:35 by pjaguin           #+#    #+#             */
/*   Updated: 2025/07/15 17:34:47 by pjaguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(): _name("Default Bureaucrat"), _grade(150)
{
	std::cout << GREEN << "Bureaucrat default constructor called" << NEUTRAL << std::endl;
}

Bureaucrat::Bureaucrat(std::string const name, int grade): _name(name)
{
	if (grade < 1)
		throw GradeTooHighException();
	else if (grade > 150)
		throw GradeTooLowException();
	else
		this->_grade = grade;
}

Bureaucrat::Bureaucrat(Bureaucrat const &other): _name(other._name)
{
	this->_grade = other._grade;
	std::cout << YELLOW << "Bureaucrat copy constructor called" << NEUTRAL << std::endl;
}

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &other)
{
	if (this != &other)
	{
		this->_grade = other._grade;
	}
	std::cout << YELLOW << "Bureaucrat assignement operator called" << NEUTRAL << std::endl;
	return *this;
}

void Bureaucrat::signForm(Form &form)
{
	try
	{
		form.beSigned(*this);
		std::cout << GREEN << this->_name << " signs " << form.getName() << NEUTRAL << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << RED << this->_name << " cannot sign " << form.getName() 
				  << " because: " << e.what() << NEUTRAL << std::endl;
	}
}

Bureaucrat::~Bureaucrat()
{
}

std::string Bureaucrat::getName() const 
{
	return this->_name;
}

int		Bureaucrat::getGrade() const
{
	return this->_grade;
}

void	Bureaucrat::incrementGrade()
{
	if (this->_grade == 1)
		throw GradeTooHighException();
	else
		this->_grade--;
}

void	Bureaucrat::decrementGrade()
{
	if (this->_grade == 150)
		throw GradeTooLowException();
	else
		this->_grade++;
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Grade too high cannot be assigned";
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Grade too low cannot be assigned";
}

std::ostream &operator<<(std::ostream &os, Bureaucrat const &bureaucrat)
{
	os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << ".";
	return os;
}
