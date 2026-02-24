#ifndef PLAYER_H
#define PLAYER_H

#include <raylib.h>

class player {
	private:
		Vector2 pos = {170,120};
		Vector2 dir = {0, 0};
		Rectangle collider = { 170,120,21,29 };
		Rectangle checkColliderX = { 170,120,20,24 };
		Rectangle checkColliderY = { 170,120,20,24 };
		float speed = 2.5;
		int touchingWallX = 0;
		int touchingWallY = 0;
		int walkFrame = 0;
	public: 
		void update(Rectangle* walls, int wallcount);
		Vector2 getPos();
		Vector2 getDir();
		int getWFrame();
};

#endif
