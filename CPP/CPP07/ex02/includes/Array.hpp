/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unmugviolet <unmugviolet@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 08:59:45 by unmugviolet       #+#    #+#             */
/*   Updated: 2025/07/27 09:55:43 by unmugviolet      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <stdexcept>

template <typename T>
class Array
{
	private:
		T*				_elements;
		unsigned int	_size;
	public:
		Array();
		Array(unsigned int n);
		Array(Array const &other);
		Array			&operator=(Array const &other);
		T				&operator[](unsigned int index);
		const T			&operator[](unsigned int index) const;
		unsigned int	size() const;
		~Array();
};

#include "Array.tpp"

#endif
