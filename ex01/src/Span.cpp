#include "Span.hpp"
#include <limits.h>
#include <stdexcept>
#include <iostream>

Span::Span() : size(0), shortest(INT_MAX, INT_MAX), largest(INT_MIN, INT_MIN), v(0, 0), s() {}

Span::Span(unsigned int N) : size(N), shortest(INT_MAX, INT_MAX), largest(INT_MIN, INT_MIN), v(0, 0), s() {}

Span::Span(Span const&copy)
{
	if (this != &copy)
	{
		this->size = copy.size;
		this->shortest.first = copy.shortest.first;
		this->shortest.second = copy.shortest.second;
		this->largest.first = copy.largest.first;
		this->largest.second = copy.largest.second;
		this->v = std::vector<int>(0,0);
		for (unsigned int i = 0; i < this->size; i++)
			this->v.push_back(copy.v[i]);
		this->s = std::set<int>();
		for (std::set<int>::const_iterator it = copy.s.begin(); it != copy.s.end(); it++)
			this->s.insert(*it);
	}
}

Span	&Span::operator=(Span const& copy)
{
	if (this != &copy)
	{
		this->size = copy.size;
		this->shortest.first = copy.shortest.first;
		this->shortest.second = copy.shortest.second;
		this->largest.first = copy.largest.first;
		this->largest.second = copy.largest.second;
		this->v = std::vector<int>(0,0);
		for (unsigned int i = 0; i < this->size; i++)
			this->v.push_back(copy.v[i]);
		this->s = std::set<int>();
		for (std::set<int>::const_iterator it = copy.s.begin(); it != copy.s.end(); it++)
			this->s.insert(*it);
	}
	return *this;
}

Span::~Span() {}

void	Span::addNumber(int num)
{
	int curr_size = (int)this->size;
	if (curr_size <= 0)
		throw std::runtime_error("No space left to add more numbers");
	this->v.push_back(num);
	this->s.insert(num);
	this->size--;
}

void	Span::addNumbers(std::vector<int>::const_iterator begin, std::vector<int>::const_iterator end)
{
	for (; begin != end; ++begin)
		this->addNumber(*begin);
}

void	Span::addNumbers(std::set<int>::const_iterator begin, std::set<int>::const_iterator end)
{
	for (; begin != end; ++begin)
		this->addNumber(*begin);
}

int	Span::shortestSpan() const
{
	std::cout << __func__ << ": ";
	if (this->v.size() <= 1 || this->s.size() <= 1)
		throw std::runtime_error("Not enough values");
	std::set<int>::iterator	it = this->s.begin();
	int		prev = *it;
	++it;
	int		minSpan = std::abs(prev - *it);
	for (; it != this->s.end(); ++it)
	{
		int	current = *it;
		int	span = std::abs(current - prev);
		minSpan = std::min(minSpan, span);
		prev = current;
	}
	return minSpan;
}

int	Span::largestSpan() const
{
	std::cout << __func__ << ": ";
	if (this->v.size() <= 1 || this->s.size() <= 1)
		throw std::runtime_error("Not enough values");
	return std::abs(*this->s.begin() - *this->s.rbegin());
}
