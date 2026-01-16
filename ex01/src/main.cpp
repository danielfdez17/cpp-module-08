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
		std::cout << BLUE << sp.shortestSpan() << "\n" RESET;
		std::cout << GREEN << sp.largestSpan() << "\n" RESET;
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
	} catch (std::runtime_error &e)
	{
		std::cerr << RED << e.what() << "\n" RESET;
	}
	std::cout << YELLOW "\n--- Valid case ---\n\n" RESET;
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
	}
	{
		(void)ac;
		(void)av;
	}
	return 0;
}