
#include <stdlib.h>

struct doge_transform
{
	union doge_vec location;
	union doge_vec scale;
};

int transform_init_2(struct doge_transform* t, struct doge_vec2 location, struct doge_vec2 scale); 
struct doge_transform* new_transform();