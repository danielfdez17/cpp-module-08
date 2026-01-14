#pragma once
#ifndef __EASYFIND_HPP__
#define __EASYFIND_HPP__

#include "colors.hpp"
#include <iostream>


template <class T, class Allocator = std::allocator<T>>
T &easyfind(T<int> v, int idx);

#include "easyfind.tpp"
#endif // __EASYFIND_HPP__