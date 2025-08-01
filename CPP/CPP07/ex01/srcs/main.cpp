/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unmugviolet <unmugviolet@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 14:16:34 by pjaguin           #+#    #+#             */
/*   Updated: 2025/07/27 08:56:57 by unmugviolet      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include "dict.hpp"

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

int main() 
{	
	size_t		arraysSize = 5;
	int			arrInt[] = {1, 2, 3, MAX_INT, MIN_INT};
	int const	arrConstInt[] = {4, 152, -2145, 45, 1221};
	int			arrNonConstInt[] = {4, 152, -2145, 45, 1221};
	float		arrFloat[] = {2.12, 4.15, 13.12, MAX_FLOAT, MIN_FLOAT};
	std::string arrStr[] = {"Verneuil", "Limoges", "Plougastel", "Arzon", "Grenoble"};

	std::cout << BOLD YELLOW << "---------------------INT----------------------" << NEUTRAL << std::endl;
	std::cout << BOLD << "INTEGERS BEFORE : " << NEUTRAL << std::endl;
	print(arrInt, arraysSize);
	iter(arrInt, arraysSize, increment);
	std::cout << std::endl;
	std::cout << BOLD << "INTEGERS AFTER: " << NEUTRAL << std::endl;
	print(arrInt, arraysSize);

	std::cout << BOLD YELLOW<< "-------------------STRINGS--------------------" << NEUTRAL << std::endl;
	std::cout << BOLD << "STRINGS BEFORE : " << NEUTRAL << std::endl;
	print(arrStr, arraysSize);
	iter(arrStr, arraysSize, increment);
	std::cout << std::endl;
	std::cout << BOLD << "STRINGS AFTER: " << NEUTRAL << std::endl;
	print(arrStr, arraysSize);

	std::cout << BOLD YELLOW << "--------------------FLOATS---------------------" << NEUTRAL << std::endl;
	std::cout << BOLD << "FLOATS BEFORE : " << NEUTRAL << std::endl;
	print(arrFloat, arraysSize);
	iter(arrFloat, arraysSize, increment);
	std::cout << std::endl;
	std::cout << BOLD << "FLOATS AFTER: " << NEUTRAL << std::endl;
	print(arrFloat, arraysSize);

	std::cout << BOLD YELLOW << "----------------CONST DISPLAY------------------" << NEUTRAL << std::endl;
	iter(arrConstInt, arraysSize, display);
	std::cout << std::endl;

	std::cout << BOLD YELLOW << "---------------NON CONST DISPLAY---------------" << NEUTRAL << std::endl;
	iter(arrNonConstInt, arraysSize, display);
	
	return 0;
}

