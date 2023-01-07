#include <stdint.h>
//The seed used in SURF. Its type is int32_t, which is a signed integer of size 32 bits.
int32_t __surf_seed;

//The method to set the seed used in SURF. Takes in an int of size 32 bits, used as that seed.
void surfsetseed(int32_t seed);

//SURF's main function. Returns a pseudorandom int of size 32 bits.
int32_t surf();

//the seed used for double SURF (dSURF). Its type is int64_t, which is a signed integer of size 64 bits.
int64_t __dsurf_seed;

//The method to set the seed used in dSURF. Takes in an int of size 64 bits, used as that seed.
void dsurfsetseed(int64_t seed);

//dSURF's main function. Returns a pseudorandom int of size 64 bits.
int64_t dsurf();