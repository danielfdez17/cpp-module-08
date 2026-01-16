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
	// MutantStack();
	// MutantStack(MutantStack const& copy);
	// MutantStack &operator=(MutantStack const& copy);
	// ~MutantStack();
	// typename MutantStack<T>::iterator begin () { return this->c.begin(); }
	// typename MutantStack<T>::iterator end () { return this->c.end(); }

    using container_type = typename std::stack<T>::container_type;
    using iterator = typename container_type::iterator;
    using const_iterator = typename container_type::const_iterator;

    iterator begin() { return this->c.begin(); }
    iterator end()   { return this->c.end(); }

    const_iterator begin() const { return this->c.begin(); }
    const_iterator end()   const { return this->c.end(); }
	
};

#endif // __MUTANTSTACK_HPP__