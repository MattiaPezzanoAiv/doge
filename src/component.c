#include "../include/component.h"
#include <stdlib.h>

struct doge_component* doge_new_component(void(*start)(struct doge_component*),void(*tick)(struct doge_component*))
{
    struct doge_component* comp = malloc(sizeof(struct doge_component));
    comp->active = 1; //true
    comp->started = 0; //false

    comp->start = start;
    comp->tick = tick;
    return comp;
}










//EXAMPLE BEHAVIOURS
void example_component_tick(struct doge_component* ex_c)
{
    static int counter;
    fprintf(stdout,"component updated\n");
    counter++;
}
void example_component_start(struct doge_component* ex_c)
{
    fprintf(stdout,"component started\n");
}