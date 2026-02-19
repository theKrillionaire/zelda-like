#include <raylib.h>
#include "player.h"

enum SPR {
	SPR_DANTEDOWN1,
	SPR_DANTEDOWN2,
	SPR_DANTEDOWN3,
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
		{0,0,20,240},
		{320,0,20,240},
		{0,0,340,20},
		{0,220,340,20},
	};
	Texture2D images[SPRCOUNT] = {
		LoadTexture("sprites/D3Down1.png"),
		LoadTexture("sprites/D3Down2.png"),
		LoadTexture("sprites/D3Down3.png")
	};
	while(!WindowShouldClose()) {
		p.update(walls, 4);
		playerPos = p.getPos();
		playerDir = p.getDir();
		playerWFrame = p.getWFrame();
		camera.target = {playerPos.x + 20, playerPos.y + 16};
		BeginDrawing();
			BeginMode2D(camera);
				ClearBackground(BLACK);
				for(int i = 0; i < 4; i++) {
					DrawRectangleLines(walls[i].x, walls[i].y , walls[i].width, walls[i].height, RED); 
				}
				if(playerWFrame == 0) DrawTexture(images[SPR_DANTEDOWN1],playerPos.x - 4,playerPos.y - 2,WHITE);
				else if(playerWFrame < 6) DrawTexture(images[SPR_DANTEDOWN2],playerPos.x - 4,playerPos.y - 2,WHITE);
				else if(playerWFrame < 11) DrawTexture(images[SPR_DANTEDOWN1],playerPos.x - 4,playerPos.y - 2,WHITE);
				else if(playerWFrame < 16) DrawTexture(images[SPR_DANTEDOWN3],playerPos.x - 4,playerPos.y - 2,WHITE);
				else if(playerWFrame <= 21) DrawTexture(images[SPR_DANTEDOWN1],playerPos.x - 4,playerPos.y - 2,WHITE);
				//DrawRectangleLines(playerPos.x, playerPos.y , 40, 40, WHITE); 
				//DrawText("test",playerPos.x, playerPos.y, 20, WHITE);
			EndMode2D();
		EndDrawing();
	}
	return 0;
}