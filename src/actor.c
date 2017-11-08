
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
    return actor;
}