#pragma once 

#include <iostream>
#include <string>
#include <list>
#include <sstream>

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

class RPN
{
	private:
		std::list<float> list;
	public:
		RPN();
		~RPN();
		RPN(RPN const &other);
		RPN &operator=(RPN const &other);
		float calculate(std::string str);
};

