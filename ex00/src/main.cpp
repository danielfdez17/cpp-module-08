#include "easyfind.hpp"
#include <vector>
#include <list>
#include <map>

// ! No need to handle associative containers (map...)
int main(void)
{
	std::vector<int> v;
	v.push_back(-12);
	v.push_back(18672);
	v.push_back(172);
	v.push_back(-1892);
	v.push_back(2312);
	v.push_back(152);
	v.push_back(12);
	v.push_back(1223);
	std::cout << BLUE << "std::vector<int>:\n";
	for (int i = 0; i < (int)v.size(); ++i)
		std::cout << "\tValue found at intex " << i << " : " << easyfind(v, i) << "\n";

	std::list<int> list;
	list.push_back(-230);
	list.push_back(0);
	list.push_back(65);
	list.push_back(24);
	list.push_back(537498);
	std::cout << GREEN << "std::list<int>:\n";
	for (int i = 0; i < (int)list.size(); i++)
		std::cout << "\tValue found at intex " << i << " : " << easyfind(list, i) << "\n";

	return 0;
}