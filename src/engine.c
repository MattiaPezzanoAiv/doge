#include "../include/engine.h"
#include <stdlib.h>
#include "../include/actor.h"
#include "../include/component.h"

struct doge_engine* doge_new_engine()
{
    //return new doge engine and init it
    struct doge_engine* engine = malloc(sizeof(struct doge_engine));
    return engine;
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
    return 0;
}
int doge_update_actors(struct doge_engine* engine)
{
    struct doge_actor* actor = engine->actor_head;
    while(actor)
    {
        struct doge_component* c = actor->component_head;
        while(c)
        {
            if(c->active == 0) continue;
            if(c->started == 0) c->start(c);
            c->tick(c);
            c = c->next;
        }
        actor = actor->next;
    }
    return 0;
}