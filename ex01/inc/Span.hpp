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
	std::vector<int>	v; // ? vector is to search the shortest span
	std::set<int>		s; // ? set is to easily obtain the largest span

public:
	Span();
	Span(unsigned int N);
	Span(Span const& copy);
	Span &operator=(Span const& copy);
	~Span();
	void	addNumber(int num);
	void	addNumbers(std::vector<int>::const_iterator begin, std::vector<int>::const_iterator end);
	void	addNumbers(std::set<int>::const_iterator begin, std::set<int>::const_iterator end);
	int		shortestSpan() const;
	int		largestSpan() const;
};

#endif // __SPAN_HPP__