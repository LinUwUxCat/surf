#include "surf.h"

void surfsetseed(uint32_t seed){
	__surf_seed=seed;
}

uint32_t surf(){
	float f=__surf_seed;
	__surf_seed*=*(uint32_t *)&f;
	return __surf_seed++;
}

void dsurfsetseed(uint64_t seed){
	__dsurf_seed=seed;
}

uint64_t dsurf(){
	double d=__dsurf_seed;
	__dsurf_seed*=*(uint64_t *)&d;
	return __dsurf_seed++;
}