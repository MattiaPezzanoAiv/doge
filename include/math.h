struct doge_vec2
{
	float x;
	float y;
}

struct doge_vec3
{
	float x;
	float y;
	float z;
}

union doge_vec
{
	struct doge_vec2 vec2;
	struct doge_vec3 vec3;
}
