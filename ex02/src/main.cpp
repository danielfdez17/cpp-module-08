#include "MutantStack.hpp"
#include "colors.hpp"
#include <iostream>
#include <list>

int main()
{
	{
		std::cout << YELLOW << "----- MutantStack Test -----\n" RESET;
		MutantStack<int> mstack;
		std::cout << "is mstack empty? " << (mstack.empty() ? "yes" : "no") << "\n";
		mstack.push(5);
		mstack.push(17);
		std::cout << "top: " << mstack.top() << "\n";
		mstack.pop();
		std::cout << "size: " << mstack.size() << "\n";
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		//[...]
		mstack.push(0);
		std::cout << "is mstack empty? " << (mstack.empty() ? "yes" : "no") << "\n";
		MutantStack<int>::const_iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();
		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << "\n";
			++it;
		}
		MutantStack<std::string> mstack_str;  // ! default constructor
		std::stack<int> s(mstack);			  // ! copy constructor
		MutantStack<int> mstack_int = mstack; // ! assignment operator
	}
	{
		std::cout << YELLOW << "----- List Test Comparison -----\n" RESET;
		std::list<int> list;
		std::cout << "is list empty? " << (list.empty() ? "yes" : "no") << "\n";
		list.push_back(5);
		list.push_back(17);
		std::cout << "top(back): " << list.back() << "\n";
		list.pop_back();
		std::cout << "size: " << list.size() << "\n";
		list.push_back(3);
		list.push_back(5);
		list.push_back(737);
		//[...]
		list.push_back(0);
		std::cout << "is list empty? " << (list.empty() ? "yes" : "no") << "\n";
		std::list<int>::const_iterator it = list.begin();
		std::list<int>::iterator ite = list.end();
		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << "\n";
			++it;
		}
	}
	return 0;
}