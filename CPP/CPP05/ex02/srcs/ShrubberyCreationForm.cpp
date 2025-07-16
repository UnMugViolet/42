/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjaguin <pjaguin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 09:54:17 by pjaguin           #+#    #+#             */
/*   Updated: 2025/07/16 11:06:46 by pjaguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm (): AForm("ShrubberyCreationForm", 145, 137), _target("Default Target")
{
}


ShrubberyCreationForm::ShrubberyCreationForm (const std::string target): AForm("ShrubberyCreationForm", 145, 137), _target(target)
{
}

ShrubberyCreationForm::ShrubberyCreationForm (ShrubberyCreationForm const &other): AForm(other), _target(other._target)
{
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm const &other)
{
	if (this != &other)
	{
		AForm::operator=(other);
		this->_target = other._target;
	}
	return *this;
}

void	ShrubberyCreationForm::performAction() const
{
	std::ofstream ofs((this->_target + "_shrubbery").c_str());
	if (!ofs.is_open())
		throw OpenFileExeption();
	ofs << "                  *                  " << std::endl;
	ofs << "                 ***                 " << std::endl;
	ofs << "                *****                " << std::endl;
	ofs << "               *******               " << std::endl;
	ofs << "              *********              " << std::endl;
	ofs << "             ***********             " << std::endl;
	ofs << "            *************            " << std::endl;
	ofs << "           ***************           " << std::endl;
	ofs << "          *****************          " << std::endl;
	ofs << "         *******************         " << std::endl;
	ofs << "        *********************        " << std::endl;
	ofs << "       ***********************       " << std::endl;
	ofs << "      *************************      " << std::endl;
	ofs << "     ***************************     " << std::endl;
	ofs << "    *****************************    " << std::endl;
	ofs << "   *******************************   " << std::endl;
	ofs << "  *********************************  " << std::endl;
	ofs << " *********************************** " << std::endl;
	ofs << "*************************************" << std::endl;
	ofs << "            |           |            " << std::endl;
	ofs << "            |           |            " << std::endl;
	ofs.close();
}

ShrubberyCreationForm::~ShrubberyCreationForm ()
{
}

const char *ShrubberyCreationForm::OpenFileExeption::what() const throw()
{
	return "Cannot open file for writing";
}
