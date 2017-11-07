#include "../include/math.h"
#include <stdlib.h>
#include <math.h>

//VECTOR 2
struct doge_vec2* sum_vec2(struct doge_vec2* a,struct doge_vec2* b)
{
    struct doge_vec2* v = malloc(sizeof(struct doge_vec2));
    v->x = a->x+b->x;
    v->y = a->y+b->y;
    return v;
}

struct doge_vec2* sub_vec2(struct doge_vec2* a,struct doge_vec2* b)
{
    struct doge_vec2* v = malloc(sizeof(struct doge_vec2));
    v->x = a->x-b->x;
    v->y = a->y-b->y;
    return v;
}

struct doge_vec2* scale_vec2(struct doge_vec2* a, struct doge_vec2* b)
{
    struct doge_vec2* v = malloc(sizeof(struct doge_vec2));
    v->x = a->x*b->x;
    v->y = a->y*b->y;
    return v;
}
float slow_len_vec2(struct  doge_vec2* a)
{
   return (float)sqrt(pow(a->x,2)+pow(a->y,2));
}

// float distance_vec2(struct doge_vec2*, struct doge_vec2*);


//VECTOR 3
struct doge_vec3* sum_vec3(struct doge_vec3* a, struct doge_vec3* b)
{
    struct doge_vec3* v = malloc(sizeof(struct doge_vec3));
    v->x = a->x+b->x;
    v->y = a->y+b->y;
    v->z = a->z+b->z;
    return v;
}
struct doge_vec3* sub_vec3(struct doge_vec3* a, struct doge_vec3* b)
{
    struct doge_vec3* v = malloc(sizeof(struct doge_vec2));
    v->x = a->x-b->x;
    v->y = a->y-b->y;
    v->z = a->z-b->z;
    return v;
}
struct doge_vec3* scale_vec3(struct doge_vec3* a, struct doge_vec3* b)
{
    struct doge_vec3* v = malloc(sizeof(struct doge_vec3));
    v->x = a->x*b->x;
    v->y = a->y*b->y;
    v->z = a->z*b->z;
    return v;
}
float slow_len_vec3(struct  doge_vec3* a)
{
   return (float)sqrt(pow(a->x,2)+pow(a->y,2)+pow(a->z,2));
}
// float distance_vec3(struct doge_vec3* a, struct doge_vec3* b)
// {

// }