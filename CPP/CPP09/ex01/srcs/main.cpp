#include "RPN.hpp"

int main(int ac, char **av)
{ 
	if (ac != 2) {
		std::cerr << RED << "Error: Invalid number of arguments" << NEUTRAL << std::endl;
		return 1;
	}

	RPN rpn;

	try 
	{
		float result = rpn.calculate(av[1]);
		std::cout << GREEN << "Result: " << result << NEUTRAL << std::endl;
	} 
	catch (const std::exception &e) {
		std::cerr << RED << e.what() << NEUTRAL << std::endl;
		return 1;
	}
	return 0;
}
