#include <exception>
#include <iostream>
#include "easyfind.hpp"

template <typename Container>
bool easyfind(const Container &c, int idx)
{
	typename Container::const_iterator it;
	for (it = c.begin(); it != c.end(); it++)
	{
		if (*it == idx)
			return true;
	}
	return false;
}