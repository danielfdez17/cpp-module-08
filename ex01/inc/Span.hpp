#pragma once
#ifndef __SPAN_HPP__
#define __SPAN_HPP__
#include <vector>
#include <set>
#include <cmath>

class Span
{
private:
	unsigned int		size;
	std::pair<int, int>	shortest;
	std::pair<int, int>	largest;
	std::vector<int>	v;
	std::set<int>		s;

public:
	Span();
	Span(unsigned int N);
	Span(Span const& copy);
	Span &operator=(Span const& copy);
	~Span();
	void	addNumber(int num);
	template <typename Container>
	void	addNumbers(typename Container::const_iterator begin, typename Container::const_iterator end);
	int		shortestSpan() const;
	int		largestSpan() const;
};

#endif // __SPAN_HPP__