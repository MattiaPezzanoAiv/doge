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