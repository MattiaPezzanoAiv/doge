#include "../include/engine.h"
#include <stdlib.h>
#include "../include/actor.h"

struct doge_engine doge_new_engine()
{
    //return new doge engine and init it
    struct doge_engine* engine = malloc(sizeof(struct doge_engine));

} 

int doge_spawn_actor(struct doge_engine* engine,struct doge_actor* actor)  //like list append
{
    if(engine->actor_head == NULL) //list is empty
    {
        engine->actor_head = actor;
        engine->actor_tail = actor;        
    }
    else
    {
        engine->actor_tail->next = actor;
        actor->prev = engine->actor_tail;
        engine->actor_tail = actor;
    }
}