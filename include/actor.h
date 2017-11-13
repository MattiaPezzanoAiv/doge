#pragma once
#include "transform.h"

#ifdef _WIN32
#include <SDL.h>
#else
#include <SDL2/SDL.h>
#endif

struct doge_actor
{
	struct doge_transform transform;
	char *name;
	struct doge_actor *prev;
	struct doge_actor *next;

	SDL_Surface* surface_bitmap;

	struct doge_component* component_head;
	struct doge_component* component_tail;

};

struct doge_actor* new_actor(int* );
struct doge_actor* new_actor_bitmap(int*, char*); //string is the path of bitmap
int add_component(struct doge_actor*,struct doge_component*);