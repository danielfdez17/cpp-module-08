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
		for (unsigned int i = 0; i < this->size; i++) // ! copy set
			this->v.push_back(copy.v[i]);
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
		for (unsigned int i = 0; i < this->size; i++) // ! copy set
			this->v.push_back(copy.v[i]);
	}
	return *this;
}

Span::~Span() {}

void	Span::addNumber(int num)
{
	this->v.push_back(num);
	this->s.insert(num);
}

template <typename Container>
void	Span::addNumbers(typename Container::const_iterator begin, typename Container::const_iterator end)
{
	for (; begin != end; ++begin)
		this->addNumber(*begin);
}

int	Span::shortestSpan() const
{
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
	if (this->v.size() <= 1 || this->s.size() <= 1)
		throw std::runtime_error("Not enough values");
	// for (std::set<int>::iterator it = this->s.begin(); it != this->s.end(); ++it)
	// 	std::cout << *it << " ";
	// std::cout << "\n";
	return std::abs(*this->s.begin() - *this->s.rbegin());
}
