/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unmugviolet <unmugviolet@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 16:22:18 by unmugviolet       #+#    #+#             */
/*   Updated: 2025/09/16 17:13:57 by unmugviolet      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

// Orthodox Canonical Form
PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe& other) : _vectorData(other._vectorData), _dequeData(other._dequeData) {}

PmergeMe& PmergeMe::operator=(const PmergeMe& other) {
	if (this != &other) {
		_vectorData = other._vectorData;
		_dequeData = other._dequeData;
	}
	return *this;
}

PmergeMe::~PmergeMe() {}

// Utility functions
bool PmergeMe::isValidNumber(const std::string& str) {
	if (str.empty()) return false;
	
	for (size_t i = 0; i < str.length(); ++i) {
		if (!std::isdigit(str[i])) return false;
	}
	
	// Check for overflow
	std::istringstream iss(str);
	long long num;
	iss >> num;
	
	return num >= 0 && num <= std::numeric_limits<int>::max();
}

double PmergeMe::getTime() {
	struct timeval tv;
	gettimeofday(&tv, NULL);
	return tv.tv_sec * 1000000.0 + tv.tv_usec;
}

// Input parsing
void PmergeMe::parseInput(int ac, char** av) {
	if (ac < 2) {
		throw std::runtime_error("Error: No arguments provided");
	}
	
	for (int i = 1; i < ac; ++i) {
		if (!isValidNumber(av[i])) {
			throw std::runtime_error("Error: Invalid number: " + std::string(av[i]));
		}
		
		int num = std::atoi(av[i]);
		_vectorData.push_back(num);
		_dequeData.push_back(num);
	}
	
	// Check for duplicates
	std::vector<int> temp = _vectorData;
	std::sort(temp.begin(), temp.end());
	for (size_t i = 1; i < temp.size(); ++i) {
		if (temp[i] == temp[i-1]) {
			throw std::runtime_error("Error: Duplicate numbers not allowed");
		}
	}
}

// Ford-Johnson algorithm for vector

/*
** Generate Jacobsthal sequence for optimal insertion order
** Jacobsthal numbers: 1, 1, 3, 5, 11, 21, 43, 85, ...
** Formula: J(n) = J(n-1) + 2*J(n-2), with J(0) = 0, J(1) = 1
*/
std::vector<size_t> PmergeMe::generateJacobsthalIndices(size_t size) {
	if (size == 0) return std::vector<size_t>();
	
	std::vector<size_t> jacobsthal;
	jacobsthal.push_back(0);
	jacobsthal.push_back(1);
	
	size_t jacob_curr = 1;
	while (jacob_curr < size) {
		jacob_curr = jacobsthal[jacobsthal.size() - 1] + 2 * jacobsthal[jacobsthal.size() - 2];
		jacobsthal.push_back(jacob_curr);
	}
	
	// Generate insertion order based on Jacobsthal sequence
	std::vector<size_t> indices;
	std::vector<bool> added(size, false);
	
	// Add first element
	if (size > 0) {
		indices.push_back(0);
		added[0] = true;
	}
	
	// Add elements following Jacobsthal order
	for (size_t i = 2; i < jacobsthal.size() && jacobsthal[i] <= size; ++i) {
		size_t jacob_val = jacobsthal[i];
		
		// Add elements from previous Jacobsthal number to current in descending order
		size_t start = (i > 2) ? jacobsthal[i-1] : 1;
		for (size_t j = std::min(jacob_val - 1, size - 1); j >= start && j < size; --j) {
			if (!added[j]) {
				indices.push_back(j);
				added[j] = true;
			}
			if (j == 0) break;  // Prevent underflow
		}
	}
	
	// Add any remaining elements
	for (size_t i = 0; i < size; ++i) {
		if (!added[i]) {
			indices.push_back(i);
		}
	}
	
	return indices;
}

/*
** Inserting the value in the sorted array following Jacobsthal order
** We need to generate the most optimal order for insertion
** For each element, we check the size, and add the number at the right sorted position with lower_bound
** Finally, we insert it
*/
void PmergeMe::insertJacobsthal(std::vector<int>& sorted, const std::vector<int>& insertions) {
	std::vector<size_t> indices = generateJacobsthalIndices(insertions.size());
	for (size_t i = 0; i < indices.size(); ++i) {
		size_t index = indices[i];
		if (index >= insertions.size())
			continue;
		int val = insertions[index];
		std::vector<int>::iterator pos = std::lower_bound(sorted.begin(), sorted.end(), val);
		sorted.insert(pos, val);
	}
}

/*
** Creating pairs
** We separate min and max
** If we have an uneven number of element, we add the remaining one into maxs
** We sort the maxs and insert the min in the right order
*/
void PmergeMe::fordJohnsonSort(std::vector<int>& data) {
	if (data.size() <= 1)
		return;
	
	std::vector<int> maxs, mins;
	size_t i = 0;
	
	// Create pairs and separate min/max
	for (; i + 1 < data.size(); i += 2) {
		if (data[i] > data[i + 1]) {
			maxs.push_back(data[i]);
			mins.push_back(data[i + 1]);
		} else {
			maxs.push_back(data[i + 1]);
			mins.push_back(data[i]);
		}
	}
	
	// If odd number of elements, add the remaining one to maxs
	if (i < data.size())
		maxs.push_back(data[i]);
	
	// Recursively sort the larger elements
	fordJohnsonSort(maxs);
	
	// Insert smaller elements using Jacobsthal sequence
	insertJacobsthal(maxs, mins);
	
	data = maxs;
}

// Ford-Johnson algorithm for deque

/*
** Generate Jacobsthal sequence for optimal insertion order (deque version)
*/
std::vector<size_t> PmergeMe::generateJacobsthalIndicesDeque(size_t size) {
	if (size == 0) return std::vector<size_t>();
	
	// Generate Jacobsthal numbers
	std::vector<size_t> jacobsthal;
	jacobsthal.push_back(0);
	jacobsthal.push_back(1);
	
	size_t jacob_curr = 1;
	while (jacob_curr < size) {
		jacob_curr = jacobsthal[jacobsthal.size() - 1] + 2 * jacobsthal[jacobsthal.size() - 2];
		jacobsthal.push_back(jacob_curr);
	}
	
	// Generate insertion order based on Jacobsthal sequence
	std::vector<size_t> indices;
	std::vector<bool> added(size, false);
	
	// Add first element
	if (size > 0) {
		indices.push_back(0);
		added[0] = true;
	}
	
	// Add elements following Jacobsthal order
	for (size_t i = 2; i < jacobsthal.size() && jacobsthal[i] <= size; ++i) {
		size_t jacob_val = jacobsthal[i];
		
		// Add elements from previous Jacobsthal number to current in descending order
		size_t start = (i > 2) ? jacobsthal[i-1] : 1;
		for (size_t j = std::min(jacob_val - 1, size - 1); j >= start && j < size; --j) {
			if (!added[j]) {
				indices.push_back(j);
				added[j] = true;
			}
			if (j == 0) break;  // Prevent underflow
		}
	}
	
	// Add any remaining elements
	for (size_t i = 0; i < size; ++i) {
		if (!added[i]) {
			indices.push_back(i);
		}
	}
	
	return indices;
}

/*
** Inserting the value in the sorted array following Jacobsthal order (deque version)
*/
void PmergeMe::insertJacobsthal(std::deque<int>& sorted, const std::deque<int>& insertions) {
	std::vector<size_t> indices = generateJacobsthalIndicesDeque(insertions.size());
	for (size_t i = 0; i < indices.size(); ++i) {
		size_t index = indices[i];
		if (index >= insertions.size())
			continue;
		int val = insertions[index];
		std::deque<int>::iterator pos = std::lower_bound(sorted.begin(), sorted.end(), val);
		sorted.insert(pos, val);
	}
}

/*
** Ford-Johnson algorithm for deque
*/
void PmergeMe::fordJohnsonSort(std::deque<int>& data) {
	if (data.size() <= 1)
		return;
	
	std::deque<int> maxs, mins;
	size_t i = 0;
	
	// Create pairs and separate min/max
	for (; i + 1 < data.size(); i += 2) {
		if (data[i] > data[i + 1]) {
			maxs.push_back(data[i]);
			mins.push_back(data[i + 1]);
		} else {
			maxs.push_back(data[i + 1]);
			mins.push_back(data[i]);
		}
	}
	
	// If odd number of elements, add the remaining one to maxs
	if (i < data.size())
		maxs.push_back(data[i]);
	
	// Recursively sort the larger elements
	fordJohnsonSort(maxs);
	
	// Insert smaller elements using Jacobsthal sequence
	insertJacobsthal(maxs, mins);
	
	data = maxs;
}

void PmergeMe::sortWithVector() {
	fordJohnsonSort(_vectorData);
}

void PmergeMe::sortWithDeque() {
	fordJohnsonSort(_dequeData);
}

void PmergeMe::displayResults(double vectorTime, double dequeTime) {
	std::cout << "After: ";
	for (size_t i = 0; i < _vectorData.size(); ++i) {
		std::cout << _vectorData[i];
		if (i < _vectorData.size() - 1) std::cout << " ";
	}
	std::cout << " " << std::endl;
	
	std::cout << "Time to process a range of " << _vectorData.size() 
			  << " elements with std::vector : " << static_cast<int>(vectorTime + 0.5) 
			  << " us" << std::endl;
	std::cout << "Time to process a range of " << _dequeData.size() 
			  << " elements with std::deque  : " << static_cast<int>(dequeTime + 0.5)
			  << " us" << std::endl;
}

// Getters
const std::vector<int> &PmergeMe::getVector() const {
	return _vectorData;
}

const std::deque<int> &PmergeMe::getDeque() const {
	return _dequeData;
}

