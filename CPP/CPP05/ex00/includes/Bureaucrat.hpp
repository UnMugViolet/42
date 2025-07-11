/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjaguin <pjaguin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 12:29:33 by pjaguin           #+#    #+#             */
/*   Updated: 2025/07/11 15:17:33 by pjaguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

# include <iostream>
# include <string>
# include "dict.hpp"

class Bureaucrat
{
private:
	std::string const	_name;
	int					_grade;
public:
	Bureaucrat(std::string const name, int grade);
	Bureaucrat(Bureaucrat const &other);

	~Bureaucrat();

	Bureaucrat &operator=(Bureaucrat const &other);

	std::string	getName() const;
	int			getGrade();
};

#endif
