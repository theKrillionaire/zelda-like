#include <raylib.h>
#include "player.h"
#include <stdio.h>

void player::update(std::vector<Rectangle> walls, int wallcount, int curmap) {
	bool touchingWallX = 0;
	bool touchingWallY = 0;
	Vector2 dir = {0, 0};
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
	
	if(dir.x || dir.y) {
		if(walkFrame < 20) { walkFrame++; } 
		else { walkFrame = 0; }
	} else { walkFrame = 0; } 
	
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
Texture2D player::getFrame() const {
	if(walkFrame == 0) return images[SPR_DOWN1];
	else if(walkFrame < 6) return images[SPR_DOWN2];
	else if(walkFrame < 11) return images[SPR_DOWN1];
	else if(walkFrame < 16) return images[SPR_DOWN3];
	else if(walkFrame < 21) return images[SPR_DOWN1];
}

Vector2 player::getPos() const { return pos; }
int player::getWFrame() const { return walkFrame; }