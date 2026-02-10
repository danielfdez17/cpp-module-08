#pragma once
#ifndef __MUTANTSTACK_HPP__
#define __MUTANTSTACK_HPP__
#include <iostream>
#include <stack>

template <typename T>
class MutantStack : public std::stack<T>
{
private:
public:
	typedef typename std::stack<T>::container_type::iterator iterator;
	typedef typename std::stack<T>::container_type::const_iterator const_iterator;

	iterator begin() { return this->c.begin(); }
	iterator end() { return this->c.end(); }
	const_iterator cbegin() const { return this->c.begin(); }
	const_iterator cend() const { return this->c.end(); }
	
	MutantStack() : std::stack<T>() {}
	MutantStack(MutantStack const &copy) : std::stack<T>(copy)
	{
		if (this != &copy)
		{
			while (!this->empty())
				this->pop();
			const_iterator it = copy.cbegin();
			const_iterator ite = copy.cend();
			while (it != ite)
			{
				this->push(*it);
				++it;
			}
		}

	}
	MutantStack &operator=(MutantStack const &copy)
	{
		if (this != &copy)
		{
			while (!this->empty())
				this->pop();
			const_iterator it = copy.cbegin();
			const_iterator ite = copy.cend();
			while (it != ite)
			{
				this->push(*it);
				++it;
			}
		}
		return *this;
	}
	~MutantStack() {}
};

template <typename T>
std::ostream &operator<<(std::ostream &out, MutantStack<T> const &obj)
{
	typename MutantStack<T>::const_iterator it = obj.cbegin();
	typename MutantStack<T>::const_iterator ite = obj.cend();
	while (it != ite)
	{
		out << *it << " ";
		it++;
	}
	return out;
}

#endif // __MUTANTSTACK_HPP__