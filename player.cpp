#include <raylib.h>
#include "player.h"

void player::update(Rectangle* walls, int wallcount) {
	if(dir.x || dir.y) {
		if(walkFrame < 21) walkFrame++;
		else walkFrame = 0;
	} else walkFrame = 0;
	touchingWallX = 0;
	touchingWallY = 0;
	if(IsKeyDown(KEY_LEFT)) { dir.x = -1; } 
	else if(IsKeyDown(KEY_RIGHT)) { dir.x = 1; }
	else { dir.x = 0; }
	if(IsKeyDown(KEY_UP)) { dir.y = -1; }
	else if(IsKeyDown(KEY_DOWN)) { dir.y = 1; }
	else { dir.y = 0; }
	if(IsKeyDown(KEY_Z)) speed = RUNSPEED;
	else speed = WALKSPEED;
	Rectangle checkColliderX = { pos.x + dir.x * speed,pos.y,playerSize.x,playerSize.y };
	Rectangle checkColliderY = { pos.x,pos.y + dir.y * speed,playerSize.x,playerSize.y };
	for(int i = 0; i < wallcount; i++) {
		if(CheckCollisionRecs(checkColliderX,walls[i])) touchingWallX = 1;
		if(CheckCollisionRecs(checkColliderY,walls[i])) touchingWallY = 1;
	}
	if(!touchingWallX) {
		pos.x += dir.x * speed;
	}
	if (!touchingWallY) {
		pos.y += dir.y * speed;
	}
}
Vector2 player::getPos() { return pos; }
Vector2 player::getDir() { return dir; }
int player::getWFrame() { return walkFrame; }