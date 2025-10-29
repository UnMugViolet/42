#include "PmergeMe.hpp"

size_t g_compares = 0;

int main(int argc, char **av)
{
	try
	{
		PmergeMe sorter;
		sorter.parseInput(argc, av);

		std::vector<int> original = sorter.getVector();

		std::cout << YELLOW BOLD << "Before: " << std::endl << NEUTRAL;
		for (size_t i = 0; i < original.size(); ++i)
		{
			std::cout << original[i];
			if (i < original.size() - 1)
				std::cout << " ";
		}
		std::cout << std::endl << std::endl;

		g_compares = 0;
		// Sort with vector and measure time
		double startTime = sorter.getTime();
		sorter.sortWithVector();
		double vectorTime = sorter.getTime() - startTime;

		size_t compares_vector = g_compares;
		g_compares = 0;

		// Sort with deque and measure time
		startTime = sorter.getTime();
		sorter.sortWithDeque();
		double dequeTime = sorter.getTime() - startTime;


		sorter.displayResults(vectorTime, dequeTime, compares_vector, g_compares);
	}
	catch (const std::exception &e)
	{
		std::cerr << RED << e.what() << NEUTRAL << std::endl;
		return 1;
	}

	return 0;
}
