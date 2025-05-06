/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjaguin <pjaguin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 09:20:28 by pjaguin           #+#    #+#             */
/*   Updated: 2025/05/06 12:35:57 by pjaguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_HPP
#define UTILS_HPP

#include <sstream>\

std::string					int_to_str(int nbr);
std::string					format_string(std::string str, int len);
std::string					format_field(std::string field, char c);

#endif
