/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unmugviolet <unmugviolet@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 14:16:34 by pjaguin           #+#    #+#             */
/*   Updated: 2025/07/27 10:01:44 by unmugviolet      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dict.hpp"
#include "Array.hpp"

int main() 
{	
	std::cout << BOLD << "========== ARRAY TEMPLATE TESTS ==========" << NEUTRAL << std::endl;
	
	try {
		std::cout << BOLD << "\n1. Testing default constructor:" << NEUTRAL << std::endl;
		Array<int> empty;
		std::cout << "Empty array size: " << empty.size() << std::endl;
		
		std::cout << BOLD << "\n2. Testing parameterized constructor:" << NEUTRAL << std::endl;
		Array<int> numbers(5);
		std::cout << "Numbers array size: " << numbers.size() << std::endl;
		
		std::cout << BOLD << "\n3. Filling array with values:" << NEUTRAL << std::endl;
		for (unsigned int i = 0; i < numbers.size(); ++i) {
			numbers[i] = i * 10;
		}
		
		std::cout << "Array contents: ";
		for (unsigned int i = 0; i < numbers.size(); ++i) {
			std::cout << numbers[i] << " ";
		}
		std::cout << std::endl;
		
		std::cout << BOLD << "\n4. Testing copy constructor:" << NEUTRAL << std::endl;
		Array<int> copy(numbers);
		std::cout << "Copy array size: " << copy.size() << std::endl;
		std::cout << "Copy contents: ";
		for (unsigned int i = 0; i < copy.size(); ++i) {
			std::cout << copy[i] << " ";
		}
		std::cout << std::endl;
		
		std::cout << BOLD << "\n5. Testing assignment operator:" << NEUTRAL << std::endl;
		Array<int> assigned;
		assigned = numbers;
		std::cout << "Assigned array size: " << assigned.size() << std::endl;
		std::cout << "Assigned contents: ";
		for (unsigned int i = 0; i < assigned.size(); ++i) {
			std::cout << assigned[i] << " ";
		}
		std::cout << std::endl;
		
		std::cout << BOLD << "\n6. Testing deep copy (modifying original):" << NEUTRAL << std::endl;
		numbers[0] = 999;
		std::cout << "Original first element: " << numbers[0] << std::endl;
		std::cout << "Copy first element: " << copy[0] << std::endl;
		std::cout << "Assigned first element: " << assigned[0] << std::endl;
		
		std::cout << BOLD << "\n7. Testing with strings:" << NEUTRAL << std::endl;
		Array<std::string> strings(3);
		strings[0] = "Argenton";
		strings[1] = "Sur";
		strings[2] = "Creuse";
		
		std::cout << "String array: ";
		for (unsigned int i = 0; i < strings.size(); ++i) {
			std::cout << strings[i] << " ";
		}
		std::cout << std::endl;
		
		std::cout << BOLD << "\n8. Testing const array access:" << NEUTRAL << std::endl;
		const Array<int> constArray(numbers);
		std::cout << "Const array first element: " << constArray[0] << std::endl;
		
		std::cout << BOLD << "\n9. Testing exception handling:" << NEUTRAL << std::endl;
		try {
			std::cout << "Trying to access index 100 in array of size " << numbers.size() << std::endl;
			numbers[100] = 42;
		}
		catch (const std::exception& e) {
			std::cout << RED << "Exception caught: " << e.what() << NEUTRAL << std::endl;
		}
		
		try {
			std::cout << "Trying to access index 0 in empty array" << std::endl;
			empty[0] = 42;
		}
		catch (const std::exception& e) {
			std::cout << RED << "Exception caught: " << e.what() << NEUTRAL << std::endl;
		}
		
	}
	catch (const std::exception& e) {
		std::cout << RED BOLD << "Unexpected exception: " << e.what() << "Exercice KO" << NEUTRAL << std::endl;
		return 1;
	}
	
	std::cout << BOLD GREEN << "\n========== ALL TESTS COMPLETED SUCCESSFULLY ==========" << NEUTRAL << std::endl;
	return 0;
}

