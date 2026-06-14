#ifndef RENDER_H
#define RENDER_H
	
#include <raylib.h>
#include "player.h"
#include <math.h>

class renderer {
private:
	enum SPR {
	MAP_TEST,
	SPRCOUNT
	};
	Vector2 playerPos = { 0, 0 };
	Vector2 playerDir = { 0, 0 };
	Texture2D images[SPRCOUNT] = {
		LoadTexture("mapimg/test.png")
	};
	Camera2D camera;

public:
	void drawScreen(int curMap, const player* p, bool debugCollision);
};


#endif