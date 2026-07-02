#ifndef PLAYER_H
#define PLAYER_H

#include <raylib.h>
#include <vector>

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
		Texture2D images[SPRCNT] = {
			LoadTexture("sprites/D3Down1.png"),
			LoadTexture("sprites/D3Down2.png"),
			LoadTexture("sprites/D3Down3.png")
		};
		
		Vector2 pos = {170,120};
		float speed = WALKSPEED;
		int walkFrame = 0;
	public: 
		const Vector2 playerSize = { 22, 30 };
		Texture2D getCurSprite() const;
		void update(std::vector<Rectangle> walls, int curmap);
		Vector2 getPos() const;
		int getWFrame() const;
		Texture2D getFrame() const;
};

#endif
