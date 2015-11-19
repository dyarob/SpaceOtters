#include "data.hpp"
#include <stdlib.h> //atoi
#include <stdio.h>

int	main(int ac, char **av) {
	d::initiate();
	puts("INSERTION");
	for (unsigned i = 1; i < ac; i+=2) {
		//d::depth[i] = atoi(av[i]);
		d::depth.emplace(i, atoi(av[i]));
		//d::depth[i] = atoi(av[i+1]);
		d::depth.emplace(i, atoi(av[i+1]));
		printf("inserting %s with key %d\n", av[i], i);
		printf("inserting %s with key %d\n", av[i+1], i);
	}
	puts("SIMPLE ITERATION");
	d::multimap::iterator end = d::depth.end();
	for (d::multimap::iterator beg = d::depth.begin(); beg != end; ++beg) {
		printf("key= %d value= %d\n", beg->first, beg->second);
	}
	puts("UPPER/LOWER BOUND TEST");
	for (unsigned i = 0; i < ac; ++i) {
		end = d::depth.upper_bound(i);
		printf("key= %d\n", i);
		for (d::multimap::iterator beg = d::depth.lower_bound(i);
				beg != end; ++beg) {
			printf("value= %d\n", beg->second);
		}
		puts("-----");
	}
	return 0;
}
