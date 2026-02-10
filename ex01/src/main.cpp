#include "Span.hpp"
#include "colors.hpp"
#include <iostream>
#include <exception>
#include <stdexcept>

int main(int ac, char **av)
{
	try
	{
		Span sp = Span(5);
		// std::cout << BLUE << sp.shortestSpan() << "\n" RESET;
		// std::cout << GREEN << sp.largestSpan() << "\n" RESET;
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		// sp.addNumber(12);
		std::cout << BLUE << sp.shortestSpan() << "\n" RESET;
		std::cout << GREEN << sp.largestSpan() << "\n" RESET;
	} catch (std::runtime_error &e)
	{
		std::cerr << RED << e.what() << "\n" RESET;
	}
	std::cout << YELLOW "\n--- Valid case ---\n\n" RESET;
	{
		try
		{
			Span sp = Span(5);
			sp.addNumber(17);
			sp.addNumber(6);
			std::cout << BLUE << sp.shortestSpan() << "\n" RESET;
			std::cout << GREEN << sp.largestSpan() << "\n" RESET;
			sp.addNumber(9);
			std::cout << BLUE << sp.shortestSpan() << "\n" RESET;
			std::cout << GREEN << sp.largestSpan() << "\n" RESET;
			sp.addNumber(11);
			std::cout << BLUE << sp.shortestSpan() << "\n" RESET;
			std::cout << GREEN << sp.largestSpan() << "\n" RESET;
			sp.addNumber(3);
			std::cout << BLUE << sp.shortestSpan() << "\n" RESET;
			std::cout << GREEN << sp.largestSpan() << "\n" RESET;
		} catch (std::runtime_error &e)
		{
			std::cerr << RED << e.what() << "\n" RESET;
		}
	}
	{
		try
		{
			if (ac == 1)
				return 0;
			(void)ac;
			(void)av;
			std::cout << YELLOW "\n--- Large case ---\n\n" RESET;
			// Span sp;
			Span sp((ac - 1) * 2);
			std::vector<int>	v;
			for (int i = 1; i <= ac - 1; i++)
				v.push_back(atoi(av[i]));
			sp.addNumbers(v.begin(), v.end());
			std::cout << BLUE << sp.shortestSpan() << "\n" RESET;
			std::cout << GREEN << sp.largestSpan() << "\n" RESET;
			std::set<int>		s;
			for (int i = 1; i < ac - 1; i++)
				s.insert(-i * 2);
			sp.addNumbers(s.begin(), s.end());
			std::cout << BLUE << sp.shortestSpan() << "\n" RESET;
			std::cout << GREEN << sp.largestSpan() << "\n" RESET;
		} catch (std::runtime_error &e)
		{
			std::cerr << RED << e.what() << "\n" RESET;
		}
	}
	return 0;
}