/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unmugviolet <unmugviolet@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 14:16:34 by pjaguin           #+#    #+#             */
/*   Updated: 2025/07/31 13:52:29 by unmugviolet      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include "dict.hpp"

int main()
{
	std::cout << BOLD YELLOW << "---------------1. TESTS FROM SUBJECTS------------" << NEUTRAL << std::endl;

	MutantStack<int> mstack;
	
	mstack.push(5);
	mstack.push(17);
	
	std::cout << BOLD << "1. showing top: " << NEUTRAL << std::endl;
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	
	std::cout << BOLD << "2. showing size: " << NEUTRAL << std::endl;
	std::cout << mstack.size() << std::endl;
	
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);
	
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	
	++it;
	--it;
	
	std::cout << BOLD << "3. listing all stack: " << NEUTRAL << std::endl;
	while (it != ite)
	{
		std::cout << *it << " ";
		++it;
	}
	std::cout << std::endl;
	std::stack<int> s(mstack);

	std::cout << BOLD YELLOW << "---------------2. TESTING REVERS--------------" << NEUTRAL << std::endl;
	
	MutantStack<int>::reverse_iterator rit = mstack.rbegin();
	MutantStack<int>::reverse_iterator rite = mstack.rend();

	std::cout << BOLD << "1. listing all stack: " << NEUTRAL << std::endl;
	while (rit != rite)
	{
		std::cout << *rit << " ";
		++rit;
	}
	std::cout << std::endl;
	
	return 0;
}
