
#include "transform.c"
#include "actor.c"
#include "../include/test.h"
#include "engine.c"
#include "math.c"
#include "component.c"

#include <stdlib.h>
#include <string.h>



//VECTOR 2
int test_sum_vec2() //ok
{
    struct doge_vec2 a;
	a.x = 10;
	a.y = 10;
	struct doge_vec2 b;
	b.x = 10;
	b.y = 10;
	
	struct doge_vec2 result = sum_vec2(a,b);
    fprintf(stdout,"%f    %f  \n",result.x,result.y);
    int ret = 1;
    if(result.x == 20.0 && result.y == 20.0)
        ret = 0;
    return ret;
}
int test_sub_vec2() //ok
{
    struct doge_vec2 a;
	a.x = 15;
	a.y = 10;
	struct doge_vec2 b;
	b.x = 30;
	b.y = 5;
	
	struct doge_vec2 result = sub_vec2(a,b);
    fprintf(stdout,"%f    %f  \n",result.x,result.y);
    int ret = 1;
    if(result.x == -15.0 && result.y == 5.0)
        ret = 0;

    return  ret;
}
int test_scale_vec2() //ok
{
    struct doge_vec2 a;
	a.x = 5;
	a.y = 2;
	struct doge_vec2 b;
	b.x = 3;
	b.y = 9;
	
	struct doge_vec2 result = scale_vec2(a,b);
    int ret = 1;
    if(result.x == 15 && result.y == 18)
        ret = 0;

    return ret;
}
int test_slow_len_vec2() //ok
{
    struct doge_vec2 a;
    a.x = 10;
    a.y = 6;
    int ret = 1;
    float len = slow_len_vec2(a);
    if(len <= 11.662 && len >= 11.660) //error margin
        ret =    0;
    return ret;
}
int test_fast_len_vec2() //ok
{
    struct doge_vec2 a;
    a.x = 10;
    a.y = 6;
    int ret = 1;
    float len = fast_len_vec2(a);
    if(len <= 136.001 && len >= 135.999) //error margin
        ret =    0;
    return ret;
}
int test_distance_vec2() //ok
{
    struct doge_vec2 a;
    a.x = 18;
    a.y = 24;
    struct doge_vec2 b;
    b.x = -5;
    b.y = -87;
    int ret = 1;
    float dist = distance_vec2(a,b); //113.357
    if(dist >= 113.356 && dist <= 113.358)
        ret = 0;
    return ret;
}
int test_normalize_vec2()
{
    struct doge_vec2 a;
    a.x = 10;
    a.y = 6;
    int ret = 1;
    normalize_vec2(&a); //expected x = 0.857 y = 0.514
    if(a.x >= 0.856 && a.x <= 0.858 && a.y >= 0.513 && a.y <= 0.515)
        ret = 0;
    return ret;
}





//VECTOR 3
int test_sum_vec3() //ok
{
    struct doge_vec3 a;
	a.x = 10;
    a.y = 10;
    a.z = 30;
	struct doge_vec3 b;
	b.x = 10;
	b.y = 10;
	b.z = 9;
	struct doge_vec3 result = sum_vec3(a,b);
    int ret = 1;
    if(result.x == 20.0 && result.y == 20.0 && result.z == 39)
        ret = 0;

    return ret;
}
int test_sub_vec3() //ok
{
    struct doge_vec3 a;
	a.x = 15;
    a.y = 10;
    a.z = 5;
	struct doge_vec3 b;
	b.x = 30;
	b.y = 5;
	b.z = 5;
	struct doge_vec3 result = sub_vec3(a,b);
    int ret = 1;
    if(result.x == -15.0 && result.y == 5.0 && result.z == 0)
        ret = 0;

    return  ret;
}
int test_scale_vec3() //ok
{
    struct doge_vec3 a;
	a.x = 5;
    a.y = 2;
    a.z = 10;
	struct doge_vec3 b;
	b.x = 3;
	b.y = 9;
    b.z = 10;
    
	struct doge_vec3 result = scale_vec3(a,b);
    int ret = 1;
    if(result.x == 15 && result.y == 18 && result.z == 100)
        ret = 0;

    return ret;
}
int test_slow_len_vec3() //ok
{
    struct doge_vec3 a;
    a.x = 10;
    a.y = 6;
    a.z = 45;
    int ret = 1;
    float len = slow_len_vec3(a);
    if(len <= 46.487 && len >= 46.485) //error margin
        ret =    0;
    return ret;
}
int test_fast_len_vec3() //ok
{
    struct doge_vec3 a;
    a.x = 10;
    a.y = 6;
    a.z = 45;
    int ret = 1;
    float len = fast_len_vec3(a);
    if(len <= 2161.001 && len >= 2160.999) //error margin
        ret =    0;
    return ret;
}
int test_distance_vec3()
{
    struct doge_vec3 a;
    a.x = 18;
    a.y = 24;
    a.z = 9;
    struct doge_vec3 b;
    b.x = -5;
    b.y = -87;
    b.z = 11;
    int ret = 1;
    float dist = distance_vec3(a,b); //113.375
    if(dist >= 113.374 && dist <= 113.376)
        ret = 0;
    return ret;
}
int test_normalize_vec3()
{
    struct doge_vec3 a;
    a.x = 10;
    a.y = 6;
    a.z = 45;
    int ret = 1;
    normalize_vec3(&a); //expected x = 0.215 y = 0.129 z = 0.968
    if(a.x >= 0.214 && a.x <= 0.216 && a.y >= 0.128 && a.y <= 0.130 && a.z >= 0.967 && a.z <= 0.969)
        ret = 0;
    return ret;
}



//TRANSFORM
int test_transform_init2()
{
    struct doge_transform* t = malloc(sizeof(struct doge_transform));
    struct doge_vec2* pippo = malloc(sizeof(struct doge_vec2));
    pippo->x = 100;pippo->y=100;
    struct doge_vec2* pippo2 = malloc(sizeof(struct doge_vec2));
    pippo2->x = 25;
    
    transform_init_2(t,*pippo,*pippo2);
    int ret = 0;
    if(t->location.vec2.x != 100.00 || t->scale.vec2.x != 25.00)
        ret = -1;
    return ret;
}
int test_new_transform()
{
    struct doge_transform* t = new_transform();
    if(!t)
        return -1;
    return 0;
}

//ACTOR
int test_new_actor_name_default()
{
    struct doge_actor* actor = new_actor(NULL);
    int ret = 1;
    if(!strcmp(actor->name, "default"))  //remember 0 at the end
        ret = 0;
    free(actor);
    return ret;
}

//ENGINE
int test_engine_add_actor()
{
    int ret = 0;
    struct doge_engine* engine = doge_new_engine();
    if(!engine)
    ret = 1;

    struct doge_actor* actor = new_actor(NULL);
    if(!actor) ret = 1;
    actor->name = "cazzo";

    doge_spawn_actor(engine,actor);
    if(engine->actor_head != actor)
    ret = 1;

    free(engine);free(actor);
    return ret;
}
int test_engine_add_actor2()
{
    int ret = 0;
    struct doge_engine* engine = doge_new_engine();
    if(!engine)
    ret = 1;

    struct doge_actor* actor = new_actor(NULL);
    if(!actor) ret = 1;
    actor->name = "cazzo";

    struct doge_actor* actor2 = new_actor(NULL);
    if(!actor2) ret = 1;
    actor2->name = "cazzo2";

    doge_spawn_actor(engine,actor);
    doge_spawn_actor(engine,actor2);
    if(engine->actor_tail != actor2)
        ret = 1;
    if(actor->next != actor2)
        ret = 1;
    if(actor2->prev != actor)
        ret = 1;

    return ret;
}
int test_engine_components()
{
    int ret = 0;
    struct doge_engine* engine = doge_new_engine();
    if(!engine)
    ret = 1;

    struct doge_actor* actor = new_actor(NULL);
    if(!actor) ret = 1;
    actor->name = "cazzo";
    struct doge_component* c1 = doge_new_component(example_component_start,example_component_tick);
    add_component(actor,c1);
    doge_spawn_actor(engine,actor);
    doge_update_actors(engine);
    return 0;
}
#include <SDL.h>
int main(int argsCount, char* args[])
{
    

    //engine
    test(test_engine_add_actor);
    test(test_engine_add_actor2);
    test(test_engine_components);
    //actor
    test(test_new_actor_name_default);

    //transform
    test_transform_init2();
    test_new_transform();


    //vector2
    test(test_sum_vec2);
    test(test_sub_vec2);
    test(test_scale_vec2);
    test(test_slow_len_vec2);
    test(test_fast_len_vec2);
    test(test_distance_vec2);
    test(test_normalize_vec2);


    //vector3
    test(test_sum_vec3);
    test(test_sub_vec3);
    test(test_scale_vec3);
    test(test_slow_len_vec3);
    test(test_fast_len_vec3);


    fprintf(stdout,"All tests passed \n");
}