
#include "../include/actor.h"
#include "../include/transform.h"

struct doge_actor* new_actor(int* err_code)
{
    struct doge_actor* actor = malloc(sizeof(struct doge_actor));
    if(!actor) //error
    {
        if(err_code != NULL)
            *err_code = -1;
        return NULL;
    }
    struct doge_transform t = *new_transform();
    actor->transform = t;

    actor->name = "default";
    actor->start = (void*)(struct doge_actor*)doge_actor_start;
    actor->tick = (void*)(struct doge_actor*)doge_actor_tick;
    return actor;
}

int doge_actor_start(struct doge_actor* actor)
{
    fprintf(stdout,"start \n");
    return 0;
}
int doge_actor_tick(struct doge_actor* actor)
{
    fprintf(stdout,"tick \n");
    return 0;
}