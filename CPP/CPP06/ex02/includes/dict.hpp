
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjaguin <pjaguin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 17:11:35 by pjaguin           #+#    #+#             */
/*   Updated: 2025/05/23 10:40:08 by pjaguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef DICT_HPP
# define DICT_HPP

#include <iostream>
#include <limits>

#define GREEN "\033[0;92m"
#define YELLOW "\033[0;33m"
#define RED "\033[0;31m"
#define NEUTRAL "\033[0m"

#define BOLD "\033[1m"
#define UNDERLINE "\033[4m"
#define ITALIC "\033[3m"

#define MAX_INT std::numeric_limits<int>::max()
#define MIN_INT std::numeric_limits<int>::min()
#define MAX_FLOAT std::numeric_limits<float>::max()
#define MIN_FLOAT std::numeric_limits<float>::min()
#define MAX_DOUBLE std::numeric_limits<double>::max()
#define MIN_DOUBLE std::numeric_limits<double>::min()

#endif
