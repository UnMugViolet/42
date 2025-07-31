/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unmugviolet <unmugviolet@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 11:12:16 by unmugviolet       #+#    #+#             */
/*   Updated: 2025/07/31 12:14:06 by unmugviolet      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(): _storage(10)
{
}

Span::Span(unsigned int N): _storage(N)
{
}

Span::Span(Span const &other)
{
	if (this != &other)
		*this = other;
}

Span &Span::operator=(Span const &other)
{
	if (this != &other)
		_storage = other._storage;
	return *this;
}

Span::~Span()
{
}

void	Span::addNumber(unsigned int toAdd)
{
	if (_container.size() >= _storage)
		throw StorageFullException();
	_container.push_back(toAdd);
}

void	Span::addNumbers(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
	if (_container.size() + std::distance(begin, end) > _storage)
		throw StorageFullException();
	_container.insert(_container.end(), begin, end);
}

int	Span::shortestSpan()
{
	if (_container.size() < 2)
		throw NotEnoughNumbersException();
	
	std::sort(_container.begin(), _container.end());
	int shortest = MAX_INT;

	for (size_t i = 1; i < _container.size(); i++)
	{
		int span = _container[i] - _container[i - 1];
		if (span < shortest)
			shortest = span;
	}
	return shortest;
}

int	Span::longestSpan()
{
	if (_container.size() < 2)
		throw NotEnoughNumbersException();
	std::vector<int> tmp = _container;
	std::sort(tmp.begin(), tmp.end());
	return (tmp[tmp.size() - 1] - tmp[0]);
}

const char *Span::StorageFullException::what() const throw()
{
	return "Container is full";
}

const char *Span::NotEnoughNumbersException::what() const throw()
{
	return "Not enough numbers in container";
}
