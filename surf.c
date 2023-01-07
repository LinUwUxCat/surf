#include "surf.h"

void surfsetseed(int32_t seed){
	__surf_seed=seed;
}

int32_t surf(){
	float f=__surf_seed;
	__surf_seed*=*(int32_t *)&f;
	return __surf_seed++;
}

void dsurfsetseed(int64_t seed){
	__dsurf_seed=seed;
}

int64_t dsurf(){
	double d=__dsurf_seed;
	__dsurf_seed*=*(int64_t *)&d;
	return __dsurf_seed++;
}