/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unmugviolet <unmugviolet@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 14:16:34 by pjaguin           #+#    #+#             */
/*   Updated: 2025/07/31 13:17:53 by unmugviolet      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include "dict.hpp"

#include <cstdlib>

int main()
{
	std::cout << BOLD YELLOW << "--------------1. TEST SUBJECT MAIN--------------" << NEUTRAL << std::endl;
	
	Span sp = Span(6);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);

	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
	
	std::cout << BOLD YELLOW << "---------------2. TESTS EXCEPTIONS--------------" << NEUTRAL << std::endl;
	std::cout << BOLD << "1. add too much: " << NEUTRAL << std::endl;
	try {
		Span sp2 = Span(2);
		sp2.addNumber(MIN_UINT);
		sp2.addNumber(MAX_UINT);
		sp2.addNumber(3); // throw StorageFullException
	}
	catch (const std::exception &e) {
		std::cout << RED BOLD << e.what() << NEUTRAL << std::endl;
	}
	std::cout << BOLD << "2. shortest span of one: " << NEUTRAL << std::endl;
	try {
		Span sp2 = Span(10);
		sp2.addNumber(1);
		sp2.shortestSpan(); // throw NotEnoughNumbersException
	} catch (const std::exception &e) {
		std::cout << RED BOLD << e.what() << NEUTRAL << std::endl;
	}
	
	std::cout << BOLD << "3. longest span of one: " << NEUTRAL << std::endl;
	try {
		Span sp2 = Span(10);
		sp2.addNumber(1);
		sp2.longestSpan(); // throw NotEnoughNumbersException
	} catch (const std::exception &e) {
		std::cout << RED BOLD << e.what() << NEUTRAL << std::endl;
	}

	std::cout << BOLD << "4. addNumbers overflow: " << NEUTRAL << std::endl;
	try {
		Span sp2 = Span(100);
		std::vector<int> vec;
		for (int i = 0; i < 101; ++i) // Fill it too much
			vec.push_back(i);
		sp2.addNumbers(vec.begin(), vec.end());
	} catch (const std::exception &e) {
		std::cout << RED BOLD << e.what() << NEUTRAL << std::endl;
	}
	
	std::cout << BOLD YELLOW << "---------------3. ALL IS WELL--------------" << NEUTRAL << std::endl;

	int sp3_storage = 10;
	Span sp3 = Span(sp3_storage);
	std::vector<int> vec;
	std::srand(time(NULL));
		
	std::cout << BOLD << "Vector numbers: " << std::endl;
	for (int i = 0; i < sp3_storage; i++)
	{
		int rand_int = rand() % 10;
		vec.push_back(rand_int);
		std::cout << rand_int << std::endl;
	}
	try {	
		sp3.addNumbers(vec.begin(), vec.end());
		std::cout << BOLD << "shortest span: " << sp3.shortestSpan() << std::endl;
		std::cout << BOLD << "Longest span: " << sp3.longestSpan() << std::endl;
	} catch (const std::exception &e) {
		std::cout << RED BOLD << e.what() << NEUTRAL << std::endl;
	}
	return 0;
}

