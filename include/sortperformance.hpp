#pragma once
#include <cstdlib>
#include <ios>
#include <iostream>
#include <fstream>
#include <limits>
#include <ostream>
#include <iostream>
#include <chrono>
#include <vector>
#include "sortingalgo.hpp"

template <typename T> auto ins_sort(vector<T> &vec);
template <typename T> auto bubble_sort(vector<T> &vec);
template <typename T> auto sel_sort(vector<int> &vec);
template <typename T> auto merge_sort(vector<int> &vec);
template <typename T> auto quick_sort(vector<int> &vec);

int benchmark(int range);
