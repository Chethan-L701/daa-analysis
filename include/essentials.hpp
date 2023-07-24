#pragma once

#include <iostream>
#include <vector>
using std::vector;

template<typename T> void swap(T &a, T &b);
vector<int> get_ranvec(int n);
template<typename T> void operator<<(std::ostream &out, vector<T> &vec);
