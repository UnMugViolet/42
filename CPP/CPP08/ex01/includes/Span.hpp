/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unmugviolet <unmugviolet@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 11:12:19 by unmugviolet       #+#    #+#             */
/*   Updated: 2025/07/31 13:04:59 by unmugviolet      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "dict.hpp"

#include <iostream>
#include <vector>
#include <algorithm>
#include <exception>

class Span
{
	private:
		unsigned int 				_storage; 
		std::vector<int>			_container;
	public:
		Span();
		Span(unsigned int N);
		Span(Span const &other);
		Span &operator=(Span const &other);
		~Span();
		
		void addNumber(unsigned int toAdd);
		int shortestSpan();
		int longestSpan();
		void addNumbers(std::vector<int>::iterator begin, std::vector<int>::iterator end);

		class StorageFullException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};

		class NotEnoughNumbersException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
};


