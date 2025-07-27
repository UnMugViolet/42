/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unmugviolet <unmugviolet@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 09:15:34 by unmugviolet       #+#    #+#             */
/*   Updated: 2025/07/27 09:54:32 by unmugviolet      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Array.hpp"

template <typename T>
Array<T>::Array(): _elements(NULL), _size(0)
{
}

template <typename T>
Array<T>::Array(unsigned int n): _elements(new T[n]()), _size(n)
{
}

template <typename T>
Array<T>::Array(Array const &other): _elements(new T[other._size]), _size(other._size)
{
	for (unsigned int i = 0; i < _size; ++i)
		_elements[i] = other._elements[i];	
}

template <typename T>
Array<T>::~Array()
{
	delete[] _elements;
}

template <typename T>
Array<T> &Array<T>::operator=(Array const &other)
{
	if (this != &other) 
	{
		delete[] _elements;

		_size = other._size;
		_elements = new T[_size];
		
		for (unsigned int i = 0; i < _size; ++i)
			_elements[i] = other._elements[i];
	}
	return *this;
}

template <typename T>
T &Array<T>::operator[](unsigned int index)
{
	if (index >= _size)
		throw std::out_of_range("Index out of range");
	return _elements[index];
}

template <typename T>
T const &Array<T>::operator[](unsigned int index) const
{
	if (index >= _size)
		throw std::out_of_range("Index out of range");
	return _elements[index];
}

template <typename T>
unsigned int Array<T>::size() const
{
    return _size;
}
