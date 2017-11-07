#include "math.c"
#include "../include/test.h"
#include <stdlib.h>

//VECTOR 2
int test_sum_vec2() //ok
{
    struct doge_vec2* a = malloc(sizeof(struct doge_vec2));
	a->x = 10;
	a->y = 10;
	struct doge_vec2* b = malloc(sizeof(struct doge_vec2));
	b->x = 10;
	b->y = 10;
	
	struct doge_vec2* result = sum_vec2(a,b);
    fprintf(stdout,"%f    %f  \n",result->x,result->y);
    int ret = 1;
    if(result->x == 20.0 && result->y == 20.0)
        ret = 0;

        free(result);
    return ret;
}
int test_sub_vec2() //ok
{
    struct doge_vec2* a = malloc(sizeof(struct doge_vec2));
	a->x = 15;
	a->y = 10;
	struct doge_vec2* b = malloc(sizeof(struct doge_vec2));
	b->x = 30;
	b->y = 5;
	
	struct doge_vec2* result = sub_vec2(a,b);
    fprintf(stdout,"%f    %f  \n",result->x,result->y);
    int ret = 1;
    if(result->x == -15.0 && result->y == 5.0)
        ret = 0;

        free(result);
    return  ret;
}
int test_scale_vec2() //ok
{
    struct doge_vec2* a = malloc(sizeof(struct doge_vec2));
	a->x = 5;
	a->y = 2;
	struct doge_vec2* b = malloc(sizeof(struct doge_vec2));
	b->x = 3;
	b->y = 9;
	
	struct doge_vec2* result = scale_vec2(a,b);
    int ret = 1;
    if(result->x == 15 && result->y == 18)
        ret = 0;

        free(result);
    return ret;
}
int test_slow_len_vec2() //ok
{
    struct doge_vec2* a = malloc(sizeof(struct doge_vec2));
    a->x = 10;
    a->y = 6;
    int ret = 1;
    float len = slow_len_vec2(a);
    fprintf(stdout,"%f \n",len);
    if(len <= 11.662 && len >= 11.660) //error margin
        ret =    0;
    free(a);
    return ret;
}
int test_fast_len_vec2() //ok
{
    struct doge_vec2* a = malloc(sizeof(struct doge_vec2));
    a->x = 10;
    a->y = 6;
    int ret = 1;
    float len = fast_len_vec2(a);
    if(len <= 136.001 && len >= 135.999) //error margin
        ret =    0;
    free(a);
    return ret;
}
int test_distance_vec2() //ok
{
    struct doge_vec2* a = malloc(sizeof(struct doge_vec2));
    a->x = 18;
    a->y = 24;
    struct doge_vec2* b = malloc(sizeof(struct doge_vec2));
    b->x = -5;
    b->y = -87;
    int ret = 1;
    float dist = distance_vec2(a,b); //113.357
    if(dist >= 113.356 && dist <= 113.358)
        ret = 0;
    free(a);free(b);
    return ret;
}
//VECTOR 3
int test_sum_vec3() //ok
{
    struct doge_vec3* a = malloc(sizeof(struct doge_vec3));
	a->x = 10;
    a->y = 10;
    a->z = 30;
	struct doge_vec3* b = malloc(sizeof(struct doge_vec3));
	b->x = 10;
	b->y = 10;
	b->z = 9;
	struct doge_vec3* result = sum_vec3(a,b);
    int ret = 1;
    if(result->x == 20.0 && result->y == 20.0 && result->z == 39)
        ret = 0;

        free(result);
    return ret;
}
int test_sub_vec3() //ok
{
    struct doge_vec3* a = malloc(sizeof(struct doge_vec3));
	a->x = 15;
    a->y = 10;
    a->z = 5;
	struct doge_vec3* b = malloc(sizeof(struct doge_vec3));
	b->x = 30;
	b->y = 5;
	b->z = 5;
	struct doge_vec3* result = sub_vec3(a,b);
    int ret = 1;
    if(result->x == -15.0 && result->y == 5.0 && result->z == 0)
        ret = 0;

        free(result);
    return  ret;
}
int test_scale_vec3() //ok
{
    struct doge_vec3* a = malloc(sizeof(struct doge_vec3));
	a->x = 5;
    a->y = 2;
    a->z = 10;
	struct doge_vec3* b = malloc(sizeof(struct doge_vec3));
	b->x = 3;
	b->y = 9;
    b->z = 10;
    
	struct doge_vec3* result = scale_vec3(a,b);
    int ret = 1;
    if(result->x == 15 && result->y == 18 && result->z == 100)
        ret = 0;

        free(result);
    return ret;
}
int test_slow_len_vec3() //ok
{
    struct doge_vec3* a = malloc(sizeof(struct doge_vec3));
    a->x = 10;
    a->y = 6;
    a->z = 45;
    int ret = 1;
    float len = slow_len_vec3(a);
    if(len <= 46.487 && len >= 46.485) //error margin
        ret =    0;
    free(a);
    return ret;
}
int test_fast_len_vec3() //ok
{
    struct doge_vec3* a = malloc(sizeof(struct doge_vec3));
    a->x = 10;
    a->y = 6;
    a->z = 45;
    int ret = 1;
    float len = fast_len_vec3(a);
    if(len <= 2161.001 && len >= 2160.999) //error margin
        ret =    0;
    free(a);
    return ret;
}
int test_distance_vec3()
{
    struct doge_vec3* a = malloc(sizeof(struct doge_vec3));
    a->x = 18;
    a->y = 24;
    a->z = 9;
    struct doge_vec3* b = malloc(sizeof(struct doge_vec3));
    b->x = -5;
    b->y = -87;
    b->z = 11;
    int ret = 1;
    float dist = distance_vec3(a,b); //113.375
    if(dist >= 113.374 && dist <= 113.376)
        ret = 0;
    free(a);free(b);
    return ret;
}
int main(int argsCount, char* args[])
{
    //vector2
    test(test_sum_vec2);
    test(test_sub_vec2);
    test(test_scale_vec2);
    test(test_slow_len_vec2);
    test(test_fast_len_vec2);
    test(test_distance_vec2);


    //vector3
    test(test_sum_vec3);
    test(test_sub_vec3);
    test(test_scale_vec3);
    test(test_slow_len_vec3);
    test(test_fast_len_vec3);


    fprintf(stdout,"All tests passed \n");
}