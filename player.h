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
		Texture2D images[SPRCNT] = {
			LoadTexture("sprites/D3Down1.png"),
			LoadTexture("sprites/D3Down2.png"),
			LoadTexture("sprites/D3Down3.png")
		};
		
		Vector2 pos = {170,120};
		float speed = WALKSPEED;
		int walkFrame = 0;
	public: 
		Texture2D getCurSprite();
		void update(Rectangle* walls, int wallcount);
		Vector2 getPos();
		int getWFrame();
		Texture2D getFrame();
};

#endif
