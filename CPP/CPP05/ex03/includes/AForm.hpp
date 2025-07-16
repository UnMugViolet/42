/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjaguin <pjaguin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 14:02:25 by pjaguin           #+#    #+#             */
/*   Updated: 2025/07/16 10:59:05 by pjaguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef AFORM_HPP
#define AFORM_HPP

# include "Bureaucrat.hpp"
# include <iostream>

class Bureaucrat;

class AForm
{
	private:
		std::string const	_name;
		bool				_is_signed;
		int const			_grade_to_sign;
		int const			_grade_to_exec;
		virtual void		performAction() const = 0;
	public:
		AForm();
		AForm(std::string const name, int const grade_to_sign, int const grade_to_exec);
		AForm(AForm const &other);
		AForm &operator=(AForm const &other);
		~AForm();

		std::string getName() const;
		int 		getGradeToSign() const;
		int 		getGradeToExec() const;
		bool		isSigned() const;
		
		void		beSigned(const Bureaucrat &bureaucrat);
		void		execute(Bureaucrat const &executor) const;
		void		setIsSigned(bool is_signed);

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
		
		class IsNotSignedException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
};

std::ostream &operator<<(std::ostream &os, AForm const &form);

#endif
