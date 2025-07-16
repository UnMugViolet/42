/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjaguin <pjaguin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 14:51:29 by pjaguin           #+#    #+#             */
/*   Updated: 2025/07/16 11:41:52 by pjaguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "AForm.hpp"

AForm::AForm(): _name("Default name"), _is_signed(false), _grade_to_sign(150), _grade_to_exec(150)
{
}

AForm::AForm(std::string const name, int const grade_to_sign, int const grade_to_exec): _name(name), _grade_to_sign(grade_to_sign), _grade_to_exec(grade_to_exec)
{
	if (grade_to_sign < 1 || grade_to_exec < 1)
		throw GradeTooHighException();
	else if (grade_to_sign > 150 || grade_to_exec > 150)
		throw GradeTooLowException();
}

AForm::AForm(AForm const &other): _name(other._name), _is_signed(other._is_signed), _grade_to_sign(other._grade_to_sign), _grade_to_exec(other._grade_to_exec)
{
}

AForm &AForm::operator=(AForm const &other)
{
	if (this != &other)
	{
		this->_is_signed = other._is_signed;
	}
	std::cout << YELLOW << "AForm assignement operator called" << NEUTRAL << std::endl;
	return *this;
}

AForm::~AForm()
{
}

void	AForm::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() <= _grade_to_sign)
		_is_signed = true;
	else
		throw GradeTooLowException();
}

void AForm::execute(Bureaucrat const &executor) const
{
	if (!isSigned())
		throw GradeTooLowException();
	if (executor.getGrade() > _grade_to_exec)
		throw GradeTooLowException();
	performAction();
}

std::string	AForm::getName() const
{
	return this->_name;
}

int	AForm::getGradeToSign() const
{
	return this->_grade_to_sign;
}

int	AForm::getGradeToExec() const
{
	return this->_grade_to_exec;
}

bool AForm::isSigned() const
{
	return this->_is_signed;
}

void AForm::setIsSigned(bool is_signed)
{
	this->_is_signed = is_signed;
}

const char *AForm::GradeTooHighException::what() const throw()
{
	return "Grade is too high";
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return "Grade is too low";
}

const char *AForm::IsNotSignedException::what() const throw()
{
	return "Form is not signed, cannot be executed";
}

std::ostream &operator<<(std::ostream &os, AForm const &form)
{
	os << form.getName() << " is_signed : " << form.isSigned() << " grade_to_sign: " << form.getGradeToSign() << " grade_to_exec: " << form.getGradeToExec() << std::endl;
	return os;
}

