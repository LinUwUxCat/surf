# SURF
## Stupidly Unprecise Random Function
SURF is, as its name suggests, an unprecise pseudo-random function.
## How it works
SURF uses the same "floating point bit level hacking" used in [Fast InvSqrt()](https://en.wikipedia.org/wiki/Fast_inverse_square_root#Overview_of_the_code), except with an unsigned int.
Assuming `seed` the "seed" given by the user (or using the default int value, depending on compilers), SURF works as the following:
```c
uint32_t surf(){
	float f = seed; //cast uint32_t to float automatically (e.g. 3 becomes 3.0)
                         //3 in binary is 00000000000000000000000000000011
                         //3.0 as a float with IEEE754 representation is 01000000010000000000000000000000
	seed *= *(uint32_t *)&f; //said "floating point bit level hacking" to convert back the float to an uint32_t without casting
                                 //here we keep the bits as they are but the type is now an uint32_t
                                 //this means 01000000010000000000000000000000 is now 1077936128
	return seed++; //we return the value++ because if __surf_seed is somehow 0 at the beginning, it would return 0 without that ++
}
```
## Problems
While this may look like the float conversion will always give different results due to the "bit hacking", this is not always the case, as floats are actually not precise for big values and as such will round some of the values. as an example, 987654321 can not be stored as it is in a float and will become 987654336. in the event that the seed later is 987654322, 987654336 will also be stored in the float, thus giving the same result for 2 different values.\
This is *kinda* fixed by the *=, but you still lose some precision, hence the name. (987654336 to uint using the bit hack is 1315666339, and 987654321\*1315666339 is not the same as 987654322\*1315666339)\
For more information, i recommend checking out [the wikipedia page on IEEE754](https://en.wikipedia.org/wiki/IEEE_754).
## dSURF (double SURF)
dSURF works the same as regular SURF but with an uint64_t and a double instead of an uint32_t and a float. This gives more precision but takes up more space.