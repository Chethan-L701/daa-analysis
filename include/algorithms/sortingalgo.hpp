#pragma omce

#define INCLUDED_SORTINGALGO
#include <vector>

#ifndef INCLUDED_ESSENTIALS
#include "essentials.hpp"
#endif

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

template<typename T> 
bool Sort::sort_check(vector<T> &vec){
	for(int i=0;i < vec.size()-1; ++i){
		if(vec[i] > vec[i+1])
			return false;
	}
	return true;
}

template<typename T> void
Sort::Selection::sort(vector<T> &vec){
	for(int i = 0;i < vec.size(); ++i){
		T min=i;
		for(int j = i+1;j < vec.size(); ++j)
			if(vec[j] < vec[min])
				min = j;
		swap(vec[i],vec[min]);
	}
}

template<typename T>
void Sort::Bubble::sort(vector<T> &vec){
	for(int i = 0;i < vec.size(); ++i){
		for(int j = 0;j < vec.size() -i -1; ++j){
			if(vec[j] > vec[j+1])
				swap(vec[j], vec[j+1]);
		}
	}
}

template<typename T> 
vector<T> Sort::Merge:: merge(vector<T> arr1, vector<T> arr2){
	vector<T> merged;
	int i = 0,j = 0;
	while(i < arr1.size() && j < arr2.size()){
		if(arr1[i] < arr2[j]){
			merged.push_back(arr1[i]);
			i++;
		}
		else if(arr1[i] > arr2[j]){
			merged.push_back(arr2[j]);
			j++;
		}
		else {
			merged.push_back(arr1[i]);
			merged.push_back(arr2[j]);
			i++;j++;
		}
	}
	if(i < arr1.size()) merged.insert(merged.end(), arr1.begin()+i, arr1.end());
	if(j < arr2.size()) merged.insert(merged.end(), arr2.begin()+j, arr2.end());

	return merged;
}

template<typename T>
vector<T> Sort::Merge::sort(vector<T> vec){
	if(vec.size() <= 1)
		return vec;
	int mid = vec.size()/2;
	return ( 
		merge(
			sort(vector<T>(vec.begin(),vec.begin()+mid)),
			sort(vector<T>(vec.begin()+mid+1,vec.end()))
	));
}

template<typename T> 
int Sort::Quick::partition(vector<T> &vec, int low, int high){
	int p_index = low;
	int pivot = vec[p_index];
	int i = low;
	int j = high;

	while (i  < j){
		while(vec[i] <= pivot && i <= high) i++;
		while(vec[j] > pivot && j >= low) j--;
		if(i < j) swap(vec[i], vec[j]);
	}
	swap(vec[p_index], vec[j]);
	return j;
}

template<typename T> 
void Sort::Quick::sort(vector<T> &vec, int low , int high){
	if(low < high){
		int part_index = partition(vec, low, high);
		sort(vec, low, part_index-1);
		sort(vec, part_index+1, high);
	}
}

template<typename T> 
void Sort::Insertion::sort(vector<T> &vec){
	for(int i = 1; i < vec.size(); ++i){
		T key = vec[i];
		int j = i-1;
		while(j>=0 && vec[j]>key){
			vec[j+1] = vec[j];
			j--;
		}
		vec[j+1] = key;
	}
}
