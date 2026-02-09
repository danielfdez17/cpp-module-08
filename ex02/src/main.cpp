#include "MutantStack.hpp"
#include "colors.hpp"
#include <iostream>
#include <list>
#include <stack>

int main()
{
	{
		std::cout << YELLOW << "----- MutantStack Test -----\n" RESET;
		MutantStack<std::string> mstack_str;
		mstack_str.push("Hola,");
		mstack_str.push("cómo");
		mstack_str.push("estas?");
		mstack_str.printStack();
		MutantStack<std::string> mstack_str_copy = mstack_str;
		std::cout << "\n";
		mstack_str_copy.printStack();
		mstack_str_copy.push("patata");
		MutantStack<std::string> mstack_str_copy_constructor(mstack_str_copy);
		std::cout << "\n";
		mstack_str_copy_constructor.printStack();
	}
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
		// ? check that iterator 'it' is constant and 'ite' is not constant
		// *it = 1;
		// *ite = 10;
		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << "\n";
			++it;
		}
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