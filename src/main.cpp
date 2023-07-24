#include <iostream>
#include <string>
#include <vector>
#include "sortingalgo.hpp"
#include "sortingalgo.cpp"
#include "essentials.hpp"
#include "essentials.cpp"
#include "sortperformance.hpp"
#include "sortperformance.cpp"

int main(int argc, char *argv[]){	
	benchmark(std::stoi(argv[1]));
	return 0;
}
