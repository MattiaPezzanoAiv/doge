#include "../include/transform.h"

#include <string.h>

int transform_init_2(struct doge_transform* t, struct doge_vec2 location, struct doge_vec2 scale)
{
    t->location.vec2 = location;
    t->scale.vec2 = scale;
    return 0;
}

struct doge_transform* new_transform()
{
    struct doge_transform* t = malloc(sizeof(struct doge_transform));
    memset(t,0,sizeof(struct doge_transform));
    return t;
}
