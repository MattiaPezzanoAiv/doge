#pragma once
#include "transform.h"

struct doge_actor
{
	struct doge_transform transform;
	char *name;
	struct doge_actor *prev;
	struct doge_actor *next;

	void (*start)(struct doge_actor *);
	void (*tick)(struct doge_actor *);
};

struct doge_actor* new_actor(int* );

int doge_actor_tick(struct doge_actor*);
int doge_actor_start(struct doge_actor*);