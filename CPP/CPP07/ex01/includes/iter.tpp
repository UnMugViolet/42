/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.tpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unmugviolet <unmugviolet@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 17:36:39 by unmugviolet       #+#    #+#             */
/*   Updated: 2025/09/30 11:05:55 by unmugviolet      ###   ########.fr       */
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

template <typename T>
void	increment(T &x) {
	x += 1;
}

template <typename T>
void	display(T &x) {
	std::cout << x << std::endl;
}

template <typename T>
void	display(T const &x) {
	std::cout << x << std::endl;
}

template <typename T>
void	print(const T &x, size_t len) {
	for (size_t i = 0; i < len; ++i) {
		std::cout << x[i] << " ";
	}
	std::cout << std::endl;
}

#endif
