#pragma once
#include <vector>
using std::vector;

namespace Search{
	namespace Linear{
		template <typename T> int search(vector<T> &vec, T key);
	}
	namespace Binary{
		template <typename T> int search(vector<T> &vec, T key);
	}
}
