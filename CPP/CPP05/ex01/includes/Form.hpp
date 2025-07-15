/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjaguin <pjaguin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 14:02:25 by pjaguin           #+#    #+#             */
/*   Updated: 2025/07/15 17:16:02 by pjaguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef FORM_HPP
#define FORM_HPP

# include "Bureaucrat.hpp"
# include <iostream>

class Bureaucrat;

class Form
{
	private:
		std::string const	_name;
		bool				_is_signed;
		int const			_grade_to_sign;
		int const			_grade_to_exec;
	public:
		Form();
		Form(std::string const name, int const grade_to_sign, int const grade_to_exec);
		Form(Form const &other);
		Form &operator=(Form const &other);
		~Form();

		std::string getName() const;
		int 		getGradeToSign() const;
		int 		getGradeToExec() const;
		
		void		beSigned(const Bureaucrat &bureaucrat);

		class	GradeTooHighException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};

		class	GradeTooLowException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
};

std::ostream &operator<<(std::ostream &os, Form const &form);

#endif
