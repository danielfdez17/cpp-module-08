#pragma once
#ifndef __MUTANTSTACK_HPP__
#define __MUTANTSTACK_HPP__
#include <vector>
#include <set>
#include <cmath>
#include <stack>
#include <deque>

template <typename T>
class MutantStack : public std::stack<T>
{
private:

public:
	MutantStack();
	MutantStack(MutantStack const& copy);
	MutantStack &operator=(MutantStack const& copy);
	~MutantStack();

	typedef typename std::stack<T>::container_type::iterator iterator;
	typedef typename std::stack<T>::container_type::const_iterator const_iterator;
	iterator begin() { return this->c.begin(); }
	iterator end() { return this->c.end(); }
	const_iterator begin() const { return this->c.begin(); }
	const_iterator end() const { return this->c.end(); }
};

#include "MutantStack.tpp"

#endif // __MUTANTSTACK_HPP__