#ifndef PLAYER_H
#define PLAYER_H

#include <raylib.h>

enum DANTE_SPR {
	SPR_DOWN1,
	SPR_DOWN2,
	SPR_DOWN3,
	SPRCNT
};

class player {
	private:
		const float WALKSPEED = 2.5;
		const float RUNSPEED = 5.0;
		const Vector2 playerSize = { 20, 24 };
		const Texture2D images[SPRCNT] = {
			LoadTexture("sprites/D3Down1.png"),
			LoadTexture("sprites/D3Down2.png"),
			LoadTexture("sprites/D3Down3.png")
		};
		
		Vector2 pos = {170,120};
		Vector2 dir = {0, 0};
		float speed = WALKSPEED;
		int touchingWallX = 0;
		int touchingWallY = 0;
		int walkFrame = 0;
	public: 
		Texture2D getCurSprite();
		void update(Rectangle* walls, int wallcount);
		Vector2 getPos();
		Vector2 getDir();
		int getWFrame();
};

#endif
