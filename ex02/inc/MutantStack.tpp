#include "MutantStack.hpp"
#include <iostream>

template <typename T>
MutantStack<T>::MutantStack() : std::stack<T>() {}

template <typename T>
MutantStack<T>::MutantStack(MutantStack const&copy) : std::stack<T>(copy)
{
	if (this != &copy)
	{

	}
}

template <typename T>
MutantStack<T>	&MutantStack<T>::operator=(MutantStack const& copy)
{
	if (this != &copy)
	{

	}
	return *this;
}

template <typename T>
MutantStack<T>::~MutantStack() { std::cout << __func__ << " destructor\n"; }

// template <typename T>
// typename MutantStack<T>::iterator begin () { return this->c.begin(); }

// template <typename T>
// typename MutantStack<T>::iterator end () { return this->c.end(); }

// template <typename T>
// typename std::stack<T>::container_type::iterator begin() { return this->c.begin(); }
// template <typename T>
// typename std::stack<T>::container_type::iterator end() { return this->c.end(); }
