/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unmugviolet <unmugviolet@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 16:22:20 by unmugviolet       #+#    #+#             */
/*   Updated: 2025/09/16 17:06:09 by unmugviolet      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int argc, char** av) {
	try {
		PmergeMe sorter;
		sorter.parseInput(argc, av);
		
		std::vector<int> original = sorter.getVector();
		
		std::cout << "Before: ";
		for (size_t i = 0; i < original.size(); ++i) {
			std::cout << original[i];
			if (i < original.size() - 1) std::cout << " ";
		}
		std::cout << std::endl;
		
		// Sort with vector and measure time
		double startTime = sorter.getTime();
		sorter.sortWithVector();
		double vectorTime = sorter.getTime() - startTime;
		
		// Sort with deque and measure time
		startTime = sorter.getTime();
		sorter.sortWithDeque();
		double dequeTime = sorter.getTime() - startTime;
		
		sorter.displayResults(vectorTime, dequeTime);
		
	} catch (const std::exception &e) {
		std::cerr << RED << e.what() << NEUTRAL << std::endl;
		return 1;
	}
	
	return 0;
}
