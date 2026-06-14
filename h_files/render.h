#ifndef RENDER_H
#define RENDER_H
	
#include <raylib.h>
#include "player.h"
#include <math.h>
#include "basicEnemy.h"

class renderer {
private:
	enum SPR {
	MAP_TEST,
	SLIME,
	SPRCOUNT
	};
	Vector2 playerPos = { 0, 0 };
	Vector2 playerDir = { 0, 0 };
	Vector2 enemyPos = { 0, 0 };
	Texture2D images[SPRCOUNT] = {
		LoadTexture("mapimg/test.png"),
		LoadTexture("sprites/fucking_slime.png")
	};
	Camera2D camera;

public:
	void drawScreen(int curMap, const player* p, bool debugCollision, const enemy* e);
};


#endif