/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjaguin <pjaguin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 14:51:29 by pjaguin           #+#    #+#             */
/*   Updated: 2025/07/16 11:10:11 by pjaguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Form.hpp"

Form::Form(): _name("Default name"), _is_signed(false), _grade_to_sign(150), _grade_to_exec(150)
{
}

Form::Form(std::string const name, int const grade_to_sign, int const grade_to_exec): _name(name), _grade_to_sign(grade_to_sign), _grade_to_exec(grade_to_exec)
{
	if (grade_to_sign < 1 || grade_to_exec < 1)
		throw GradeTooHighException();
	else if (grade_to_sign > 150 || grade_to_exec > 150)
		throw GradeTooLowException();
}

Form::Form(Form const &other): _name(other._name), _is_signed(other._is_signed), _grade_to_sign(other._grade_to_sign), _grade_to_exec(other._grade_to_exec)
{
}

Form &Form::operator=(Form const &other)
{
	if (this != &other)
	{
		this->_is_signed = other._is_signed;
	}
	std::cout << YELLOW << "Form assignement operator called" << NEUTRAL << std::endl;
	return *this;
}

Form::~Form()
{
}

void	Form::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() <= _grade_to_sign)
		_is_signed = true;
	else
		throw GradeTooLowException();
}

std::string	Form::getName() const
{
	return this->_name;
}

int	Form::getGradeToSign() const
{
	return this->_grade_to_sign;
}

int	Form::getGradeToExec() const
{
	return this->_grade_to_exec;
}

bool Form::isSigned() const
{
	return this->_is_signed;
}

const char *Form::GradeTooHighException::what() const throw()
{
	return "Grade is too high, form cannot be created";
}

const char *Form::GradeTooLowException::what() const throw()
{
	return "Grade is too low, form cannot be created";
}

std::ostream &operator<<(std::ostream &os, Form const &form)
{
	os << form.getName() << " is_signed : " << form.isSigned() << " grade_to_sign: " << form.getGradeToSign() << " grade_to_exec: " << form.getGradeToExec() << std::endl;
	return os;
}

