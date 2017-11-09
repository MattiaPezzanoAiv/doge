#pragma once
#include "transform.h"

struct doge_actor
{
	struct doge_transform transform;
	char *name;
	struct doge_actor *prev;
	struct doge_actor *next;

	struct doge_component* component_head;
	struct doge_component* component_tail;

};

struct doge_actor* new_actor(int* );
int add_component(struct doge_actor*,struct doge_component*);