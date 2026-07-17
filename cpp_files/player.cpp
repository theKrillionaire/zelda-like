#include <raylib.h>
#include "player.h"
#include <stdio.h>

void player::update(std::vector<Rectangle> walls, int curmap) {
	bool touchingWallX = 0;
	bool touchingWallY = 0;
	Vector2 dir = {0, 0};
	touchingWallX = 0;
	touchingWallY = 0;

	dir.x = IsKeyDown(KEY_RIGHT) - IsKeyDown(KEY_LEFT);
	dir.y = IsKeyDown(KEY_DOWN) - IsKeyDown(KEY_UP);
	
	(IsKeyDown(KEY_Z)) ? speed = RUNSPEED : speed = WALKSPEED;
	
	if(dir.x || dir.y) {
		if(walkFrame < 20) { walkFrame++; } 
		else { walkFrame = 0; }
	} else { walkFrame = 0; } 
	
	Rectangle checkColliderX = { pos.x + dir.x * speed,pos.y,playerSize.x,playerSize.y };
	Rectangle checkColliderY = { pos.x,pos.y + dir.y * speed,playerSize.x,playerSize.y };
	for(int i = 0; i < walls.size(); i++) {
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
