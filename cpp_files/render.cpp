#include "render.h"
#include "player.h"
#include <raylib.h>
#include <stdio.h>

void renderer::drawScreen(int curMap, const player* p, bool debugCollision) {

	playerPos = p->getPos();
	camera = { 0 };
	camera.offset = { 340 / 2, 240 / 2 };
	camera.zoom = 1.0f;
	camera.target = {floor(playerPos.x + 20), floor(playerPos.y + 16)};
	BeginDrawing();
		BeginMode2D(camera);
			ClearBackground(BLACK);
			DrawTexture(images[MAP_TEST],0,0,WHITE);
			DrawTexture(p->getFrame(), playerPos.x - 4, playerPos.y, WHITE);
			if(debugCollision) {
				DrawRectangleLines(playerPos.x,playerPos.y,p->playerSize.x,p->playerSize.y, WHITE);
			}
		EndMode2D();
	EndDrawing();
}

