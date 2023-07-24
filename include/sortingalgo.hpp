#pragma omce

#include <vector>
#include "essentials.hpp"

namespace Sort{
	template<typename T> bool sort_check(vector<T> &vec);
	namespace Selection{
		template<typename T> void sort(vector<T> &vec);
	}
	namespace Bubble{
		template<typename T> void sort(vector<T> &vec);
	}
	namespace Insertion{
		template<typename T> void sort(vector<T> &vec);
	}
	namespace Merge{
		template<typename T> vector<T> merge(vector<T> arr1,vector<T> arr2);
		template<typename T>vector<T> sort(vector<T> vec);
	}
	namespace Quick{
		template<typename T> int partition(vector<T> &vec, int low, int high);
		template<typename T> void sort(vector<T> &vec, int low , int high);
	}
}
