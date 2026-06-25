#include "render.h"
#include "player.h"
#include <raylib.h>
#include <stdio.h>
#include "basicEnemy.h"

void renderer::drawScreen(int curMap, const player* p, bool debugCollision, const enemy* e) {

	playerPos = p->getPos();
	playerSize = { p->playerSize.x, p->playerSize.y };
	enemyPos = e->getPos();

	camera = { 0 };
	camera.offset = { 340 / 2, 240 / 2 };
	camera.zoom = 1.0f;
	playerCollider = { playerSize.x, playerSize.y, playerPos.x, playerPos.y };
	region = { floor(playerPos.x / 340), floor(playerPos.y / 240) };
	regionRect = { region.x * 340, region.y * 240, 340, 240 };
	camera.target = { region.x * 340 + 170, region.y * 240 + 120 };


	BeginDrawing();
		BeginMode2D(camera);
			ClearBackground(BLACK);
			DrawTexture(images[MAP_TEST],0,0,WHITE);
			DrawTexture(p->getFrame(), playerPos.x - 4, playerPos.y, WHITE);
			DrawTexture(images[SLIME], enemyPos.x - 4, enemyPos.y, WHITE);

			if(debugCollision) {
				DrawRectangleLines(playerPos.x,playerPos.y,playerSize.x,playerSize.y, WHITE);
				DrawRectangleLines(enemyPos.x,enemyPos.y,32,32, WHITE);
				DrawRectangleLines(regionRect.x,regionRect.y,regionRect.width - 1,regionRect.height - 1 , WHITE);
			}
		EndMode2D();
	EndDrawing();
}

