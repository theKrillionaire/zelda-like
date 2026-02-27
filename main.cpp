#include <raylib.h>
#include "player.h"
#include <math.h>

enum SPR {
	MAP_TEST,
	SPRCOUNT
};

class player;

int main() {
	InitWindow(340,240, "gay");
	SetTargetFPS(30);
	player p;
	Vector2 playerPos = { 0, 0 };
	Vector2 playerDir = { 0, 0 };
	int playerWFrame = 0;
	Camera2D camera = { 0 };
	camera.offset = { 340 / 2, 240 / 2 };
	camera.zoom = 1.0f;
	Rectangle walls[4] = {
		{0,0,32,640},
		{640,0,32,640},
		{0,0,640,32},
		{0,610,640,32},
	};
	Texture2D images[SPRCOUNT] = {
		LoadTexture("mapimg/test.png")
	};
	while(!WindowShouldClose()) {
		p.update(walls, 4);
		camera.target = {floor(playerPos.x + 20), floor(playerPos.y + 16)};
		playerPos = p.getPos();
		//playerDir = p.getDir();
		BeginDrawing();
			BeginMode2D(camera);
				ClearBackground(BLACK);
				DrawTexture(images[MAP_TEST],0,0,WHITE);
				DrawTexture(p.getFrame(), playerPos.x, playerPos.y, WHITE);
			EndMode2D();
		EndDrawing();
	}
	return 0;
}