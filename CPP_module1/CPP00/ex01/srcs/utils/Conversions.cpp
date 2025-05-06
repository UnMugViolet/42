/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Conversions.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjaguin <pjaguin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 09:20:16 by pjaguin           #+#    #+#             */
/*   Updated: 2025/05/06 09:22:29 by pjaguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <sstream>

std::string int_to_str(int number)
{
	std::stringstream ss;
	ss << number;
	return ss.str();
}
