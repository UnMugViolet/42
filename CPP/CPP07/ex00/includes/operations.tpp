/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.tpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unmugviolet <unmugviolet@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 17:36:39 by unmugviolet       #+#    #+#             */
/*   Updated: 2025/07/25 17:50:14 by unmugviolet      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef OPERATIONS_HPP
#define OPERATIONS_HPP

template <typename T>
void	swap(T &a, T &b)
{
	T	tmp;

	tmp = a;
	a = b;
	b = tmp;
};

template <typename T>
T	min(const T &a, const T &b)
{
	return (a < b ? a : b);
};

template <typename T>
T	max(const T &a, const T &b)
{
	return (a > b ? a : b);
};

#endif
