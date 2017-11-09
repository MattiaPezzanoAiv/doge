
#include "../include/actor.h"
#include "../include/transform.h"
#include "../include/component.h"

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
int add_component(struct doge_actor* actor,struct doge_component* comp)
{
    if(actor->component_head == NULL) //list is empty
    {
        actor->component_head = comp;
        actor->component_tail = comp;        
    }
    else
    {
        actor->component_tail->next = comp;
        comp->prev = actor->component_tail;
        actor->component_tail = comp;
    }
    return 0;
}