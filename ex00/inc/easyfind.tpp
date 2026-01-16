#include <exception>
#include <iostream>
#include "easyfind.hpp"

template <typename Container>
int easyfind(const Container &c, int idx)
{
	typename Container::const_iterator it;
	for (it = c.begin(); it != c.end(); it++)
	{
		if (idx == 0)
			return *it;
		idx--;
	}
	return 0;
}