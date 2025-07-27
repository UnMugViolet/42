/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unmugviolet <unmugviolet@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 17:36:39 by unmugviolet       #+#    #+#             */
/*   Updated: 2025/07/27 08:37:07 by unmugviolet      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>
#include <math.h>

template <typename T>
void	iter(T *array, size_t lenght, void (*function)(T &)) {
	for (size_t i = 0; i < lenght; ++i) {
		function(array[i]);
	}
}

template <typename T>
void	iter(const T *array, size_t lenght, void (*function)(const T &)) {
	for (size_t i = 0; i < lenght; ++i) {
		function(array[i]);
	}
}

#endif
