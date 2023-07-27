#pragma once

#define INCLUDED_ESSENTIALS
#include <iostream>
#include <vector>
using std::vector;

template <typename T> void swap(T &a, T &b);
template <typename T> vector<T> get_ranvec(int n);
template <typename T> void operator<<(std::ostream &out, vector<T> &vec);

template <typename T> void swap(T &a, T &b) {
    T temp = a;
    a = b;
    b = temp;
}

template <typename T> vector<int> get_ranvec(T n) {
    vector<T> vec;
    srand(time(0));
    for (int i = 0; i < n; ++i)
        vec.push_back((rand() % 100000000));
    return vec;
}

template <typename T> void operator<<(std::ostream &out, vector<T> &vec) {
    for (T v : vec)
        std::cout << v << '\t';
    std::cout << std::endl;
}
