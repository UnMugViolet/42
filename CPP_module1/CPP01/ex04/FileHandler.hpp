/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FileHandler.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjaguin <pjaguin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 14:59:26 by pjaguin           #+#    #+#             */
/*   Updated: 2025/05/13 17:56:53 by pjaguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_HPP
#define MAIN_HPP

#include "dictionnary.hpp"

class FileHandler
{
	private:
		std::fstream src;
		std::fstream dst;
	public:
		FileHandler();
		~FileHandler();
		void	open(char *file);
		void	replace(char *file, char *to_replace, char *replacer);
};

#endif
