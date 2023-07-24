#pragma once

#include "sortingalgo.hpp"
#include "searchingalgo.hpp"

template <typename T> 
int  Search::Linear::search(vector<T> &vec, T key){
	for(int i = 0; i < vec.size(); ++i){
		if(vec[i] == key)
			return i;
	}
	return -1;
}

template <typename T>
int Search::Binary::search(vector<T> &vec, T key){
	int low = 0;
	int high = vec.size();
	int mid;
	while(high >= low){
		mid = (low+high)/2;

		if(vec[mid] == key) return mid;
		else if(key < vec[mid]) high = mid - 1; 
		else low = mid + 1;
	}
	return -1;
}

