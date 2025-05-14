/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FileHandler.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjaguin <pjaguin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 18:29:29 by pjaguin           #+#    #+#             */
/*   Updated: 2025/05/13 18:29:40 by pjaguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FileHandler.hpp"

FileHandler::FileHandler()
{
}

FileHandler::~FileHandler()
{
	if (this->dst.is_open())
		this->dst.close();
	if (this->src.is_open())
		this->src.close();
}

void	FileHandler::open(char *file)
{
	std::string	dst_file = file + std::string(".replace");
	
	this->src.open(file, std::fstream::in | std::fstream::out);
	this->dst.open(dst_file.c_str(), std::fstream::out);
	if (!this->src.is_open() || !this->dst.is_open())
	{
		std::cout << ERR_OPEN << std::endl;
		exit(EXIT_FAILURE);
	}
}

void	FileHandler::replace(char *file, char *to_replace, char *replacer)
{
	std::string		line;
	std::string		new_line;
	
	if (strlen(to_replace) == 0 || strlen(replacer) == 0)
	{
		std::cout << ERR_EMPTY << std::endl;
		return ;
	}
	this->open(file);
	while (std::getline(this->src, line))
	{
		size_t pos = 0;
		if (line.find(to_replace) != std::string::npos)
		{
			while ((pos = line.find(to_replace, pos)) != std::string::npos)
			{
				new_line += line.substr(0, pos) + replacer;
				pos += strlen(to_replace);
				line.erase(0, pos);
			}
			new_line += line + "\n";
			this->dst << new_line;
			new_line.clear();
		}
		else
			this->dst << line << "\n";
	}
}
