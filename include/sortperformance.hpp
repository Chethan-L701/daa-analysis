#pragma once

#define INCLUDED_SORTPERFORMANCE
#include <cstdlib>
#include <ios>
#include <iostream>
#include <fstream>
#include <limits>
#include <ostream>
#include <iostream>
#include <chrono>
#include <vector>


#ifndef INCLUDED_SORTINGALGO
#include "sortingalgo.hpp"
#endif


template <typename T> auto ins_sort(vector<T> &vec);
template <typename T> auto bubble_sort(vector<T> &vec);
template <typename T> auto sel_sort(vector<int> &vec);
template <typename T> auto merge_sort(vector<int> &vec);
template <typename T> auto quick_sort(vector<int> &vec);

template <typename T> int benchmark(int range);


using namespace Sort;

template <typename T> auto ins_sort(vector<T> &vec){
	auto start = std::chrono::high_resolution_clock::now();
	Insertion::sort(vec);
	auto end = std::chrono::high_resolution_clock::now();
	auto dur = std::chrono::duration_cast<std::chrono::microseconds>(end-start).count();

	if(sort_check(vec)) return dur;
	else return std::numeric_limits<long>::max();
}

template <typename T>
auto bubble_sort(vector<T> &vec){
	auto start = std::chrono::high_resolution_clock::now();
	Bubble::sort(vec);
	auto end = std::chrono::high_resolution_clock::now();
	auto dur = std::chrono::duration_cast<std::chrono::microseconds>(end-start).count();

	if(sort_check(vec)) return dur;
	else return std::numeric_limits<long>::max();
}

template <typename T>
auto sel_sort(vector<T> &vec){
	auto start = std::chrono::high_resolution_clock::now();
	Selection::sort(vec);
	auto end = std::chrono::high_resolution_clock::now();
	auto dur = std::chrono::duration_cast<std::chrono::microseconds>(end-start).count();

	if(sort_check(vec)) return dur;
	else return std::numeric_limits<long>::max();
}

template <typename T>
auto merge_sort(vector<T> &vec){
	auto start = std::chrono::high_resolution_clock::now();
	vector<int> svec = Merge::sort(vec);
	auto end = std::chrono::high_resolution_clock::now();
	auto dur = std::chrono::duration_cast<std::chrono::microseconds>(end-start).count();

	if(sort_check(svec)) return dur;
	else return std::numeric_limits<long>::max();
}

template <typename T>
auto quick_sort(vector<T> &vec){
	auto start = std::chrono::high_resolution_clock::now();
	Quick::sort(vec, 0, vec.size() -1);
	auto end = std::chrono::high_resolution_clock::now();
	auto dur = std::chrono::duration_cast<std::chrono::microseconds>(end-start).count();

	if(sort_check(vec)) return dur;
	else return std::numeric_limits<long>::max();
}

template<typename T>
int benchmark(int range) {
	vector<T> uvec;
	std::ofstream file;
	file.open("sortperf.csv",std::ios::app);
	file << "SelectionSort," << "BubbleSort," << "InsertionSort," << "MergeSort," << "QuickSort\n";
	for (int i=1; i <= range;++i){
		std::cout << "\rSorting for array length : " << i;
		uvec.clear();
		uvec = get_ranvec<T>(i);
		vector<int> ssort(uvec), msort(uvec), isort(uvec), qsort(uvec), bsort(uvec); 
		file << sel_sort(ssort) << ',' << bubble_sort(bsort) << ',' << ins_sort(isort) << ',' << merge_sort(msort) << ',' << quick_sort(qsort) << '\n';
	}
	return 0;
}
