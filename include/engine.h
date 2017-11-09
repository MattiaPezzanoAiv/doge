#pragma once

struct doge_engine
{
	float delta_time;
	struct doge_actor *actor_head;
	struct doge_actor *actor_tail;
};

struct doge_engine* doge_new_engine(); //return new doge engine and init it
int doge_spawn_actor(struct doge_engine*,struct doge_actor*); //manage head and tail
