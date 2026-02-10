#pragma once
#ifndef __EASYFIND_HPP__
#define __EASYFIND_HPP__

#include "colors.hpp"
#include <iostream>

template <typename Container>
bool	easyfind(const Container &v, int value);

#include "easyfind.tpp"
#endif // __EASYFIND_HPP__