#pragma once

struct doge_engine
{
	float delta_time;
	struct doge_actor *actor_head;
	struct doge_actor *actor_tail;

	//add sdl window
};

struct doge_engine* doge_new_engine(); //return new doge engine and init it
int doge_spawn_actor(struct doge_engine*,struct doge_actor*); //manage head and tail
int doge_update_actors(struct doge_engine*);
//add function render actors, cycling actors checks if his bitmap is equal to null, else create renderer and draw it on screen
//based on transform