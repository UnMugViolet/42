#pragma once

#include <iostream>
#include <vector>
#include <deque>
#include <string>
#include <sstream>
#include <algorithm>
#include <ctime>
#include <sys/time.h>
#include <stdexcept>
#include <limits>
#include <iomanip>


#define MAX_INT std::numeric_limits<int>::max()
#define MIN_INT std::numeric_limits<int>::min()
#define MAX_FLOAT std::numeric_limits<float>::max()
#define MIN_FLOAT -std::numeric_limits<float>::max()
#define MAX_DOUBLE std::numeric_limits<double>::max()
#define MIN_DOUBLE -std::numeric_limits<double>::max()

#define GREEN "\033[0;92m"
#define YELLOW "\033[0;33m"
#define RED "\033[0;31m"
#define NEUTRAL "\033[0m"

#define BOLD "\033[1m"
#define UNDERLINE "\033[4m"
#define ITALIC "\033[3m"

extern size_t g_compares;

class PmergeMe
{
	private:
		std::vector<int>	_vectorData;
		std::deque<int>		_dequeData;
		
		// Ford-Johnson algorithm for vector
		void	fordJohnsonSort(std::vector<int> &arr);
		void	insertJacobsthal(std::vector<int>& sorted, const std::vector<int>& insertions);
		std::vector<size_t> generateJacobsthalIndices(size_t size);
		
		// Ford-Johnson algorithm for deque
		void	fordJohnsonSort(std::deque<int> &arr);
		void	insertJacobsthal(std::deque<int>& sorted, const std::deque<int>& insertions);
		std::vector<size_t> generateJacobsthalIndicesDeque(size_t size);
		
		// Utility functions
		bool	isValidNumber(std::string const &str);

	public:
		PmergeMe();
		PmergeMe(PmergeMe const &other);
		PmergeMe &operator=(PmergeMe const &other);
		~PmergeMe();
		
		// Main functions
		void	parseInput(int ac, char** av);
		void	sortWithVector();
		void	sortWithDeque();
		void	displayResults(double vectorTime, double dequeTime, size_t compares_vector, size_t compares_deque);
		double	getTime();
		
		// Getters
		const std::vector<int> &getVector() const;
		const std::deque<int> &getDeque() const;
};

