#include <stdlib.h>
#pragma once

struct doge_component
{
    void (*start)(struct doge_component*);
    void (*tick)(struct doge_component*);
    void (*destory)(struct doge_component*);

    char started;
    char active;

    struct doge_component* next;
    struct doge_component* prev;
};

// int doge_component_destroy();
struct doge_component* doge_new_component(void(*)(struct doge_component*),void(*)(struct doge_component*));

