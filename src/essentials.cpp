#include "essentials.hpp"

template<typename T> void swap(T &a, T &b){
		T temp = a;
		a = b;
		b = temp;
}
vector<int> get_ranvec(int n){
	vector<int> vec;
	srand(time(0));

	for(int i = 0;i < n; ++i) vec.push_back((rand()%100000000));
	return vec;
}

template<typename T> void operator<<(std::ostream &out, vector<T> &vec){
	for(T v : vec)
		std::cout << v <<'\t';
	std::cout << std::endl;
}
