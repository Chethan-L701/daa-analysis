#include <iostream>
#include <string>
#include <vector>

#ifndef INCLUDED_ESSENTIALS
#include "essentials.hpp"
#endif

#ifndef INCLUDED_SORTINGALGO
#include "sortingalgo.hpp"
#endif

#ifndef INCLUDED_SORTPERFORMANCE
#include "sortperformance.hpp"
#endif



int main(int argc, char *argv[]){	
	benchmark<int>(std::stoi(argv[1]));
	return 0;
}
