#include "surf.h"

void surfsetseed(int seed){
	__surf_seed=seed;
}

int surf(){
	float y=__surf_seed;;
	__surf_seed*=*(int *)&y;
	return __surf_seed++;
}
