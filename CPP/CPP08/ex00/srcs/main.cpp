/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unmugviolet <unmugviolet@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 14:16:34 by pjaguin           #+#    #+#             */
/*   Updated: 2025/07/31 11:09:57 by unmugviolet      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include "dict.hpp"

#include <vector>
#include <list>
#include <deque>

int main()
{
	std::cout << BOLD YELLOW << "-----------------1. TESTING VECTOR-----------------" << NEUTRAL << std::endl;
	std::vector<int> vec;
	
	for (int i = 0; i < 10; ++i)
		vec.push_back(i);

	try {
		std::cout << "Found: " << *easyfind(vec, 5) << std::endl;
		std::cout << "Found: " << *easyfind(vec, 10) << std::endl; // Exception expected
	} catch (std::exception &e) {
		std::cerr << RED << e.what() << NEUTRAL << std::endl;
	}

	std::cout << BOLD YELLOW << "-----------------2. TESTING LIST-----------------" << NEUTRAL << std::endl;
	std::list<int> lst;

	for (int i = 0; i < 10; ++i)
		lst.push_back(i);
		
	try {
		std::cout  << "Found: " << *easyfind(lst, 0) << std::endl;
		std::cout  << "Found: " << *easyfind(lst, 10) << std::endl; // Expect error
	} catch (std::exception &e) {
		std::cerr << RED << e.what() << NEUTRAL << std::endl;
	}

	std::cout << BOLD YELLOW << "-----------------3. TESTING DEQUE-----------------" << NEUTRAL << std::endl;
	std::deque<int> deq;
	
	for (int i = 0; i < 150; ++i)
		deq.push_back(i);

	try {
		std::cout << "Found: " << *easyfind(deq, 3) << std::endl;
		std::cout << "Found: " << *easyfind(deq, 1500) << std::endl; // Expect error
	} catch (std::exception &e) {
		std::cerr << RED << e.what() << NEUTRAL << std::endl;
	}
	return 0;
}

