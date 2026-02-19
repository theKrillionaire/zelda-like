#include <raylib.h>
#include "player.h"
#include <math.h>

enum SPR {
	SPR_DANTEDOWN1,
	SPR_DANTEDOWN2,
	SPR_DANTEDOWN3,
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
		LoadTexture("sprites/D3Down1.png"),
		LoadTexture("sprites/D3Down2.png"),
		LoadTexture("sprites/D3Down3.png"),
		LoadTexture("mapimg/test.png")
	};
	while(!WindowShouldClose()) {
		p.update(walls, 4);
		camera.target = {floor(playerPos.x + 20), floor(playerPos.y + 16)};
		playerPos = p.getPos();
		playerDir = p.getDir();
		playerWFrame = p.getWFrame();
		BeginDrawing();
			BeginMode2D(camera);
				ClearBackground(BLACK);
				DrawTexture(images[MAP_TEST],0,0,WHITE);
				if(playerWFrame == 0) DrawTexture(images[SPR_DANTEDOWN1],playerPos.x - 4,playerPos.y - 2,WHITE);
				else if(playerWFrame < 6) DrawTexture(images[SPR_DANTEDOWN2],playerPos.x - 4,playerPos.y - 2,WHITE);
				else if(playerWFrame < 11) DrawTexture(images[SPR_DANTEDOWN1],playerPos.x - 4,playerPos.y - 2,WHITE);
				else if(playerWFrame < 16) DrawTexture(images[SPR_DANTEDOWN3],playerPos.x - 4,playerPos.y - 2,WHITE);
				else if(playerWFrame <= 21) DrawTexture(images[SPR_DANTEDOWN1],playerPos.x - 4,playerPos.y - 2,WHITE);
			EndMode2D();
		EndDrawing();
	}
	return 0;
}