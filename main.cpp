#include <raylib.h>
#include <iostream>

enum SPR {
	SPR_DANTEDOWN1,
	SPR_DANTEDOWN2,
	SPR_DANTEDOWN3,
	SPRCOUNT
};

class player {
	Vector2 pos = {170,120};
	Vector2 dir = {0, 0};
	Rectangle collider = { 170,120,21,29 };
	Rectangle checkCollider = { 170,120,20,24 };
	float speed = 2.5;
	int touchingWall = 0;
	int walkFrame = 0;
	public: void update(Rectangle* walls, int wallcount) {
		if(dir.x || dir.y) {
			if(walkFrame < 21) walkFrame++;
			else walkFrame = 0;
		} else walkFrame = 0;
		touchingWall = 0;
		if(IsKeyDown(KEY_LEFT)) { dir.x = -1; } 
		else if(IsKeyDown(KEY_RIGHT)) { dir.x = 1; }
		else { dir.x = 0; }
		if(IsKeyDown(KEY_UP)) { dir.y = -1; }
		else if(IsKeyDown(KEY_DOWN)) { dir.y = 1; }
		else { dir.y = 0; }
		collider = { pos.x, pos.y, collider.width,collider.height };
		checkCollider = { pos.x + dir.x * speed, pos.y + dir.y * speed, collider.width,collider.height };
		for(int i = 0; i < wallcount; i++) {
			if(CheckCollisionRecs(checkCollider,walls[i])) touchingWall = 1;
		}
		if(!touchingWall) {
			pos.y += dir.y * speed;
			pos.x += dir.x * speed;
		}
	}
	public: Vector2 getPos() { return pos; }
	public: Vector2 getDir() { return dir; }
	public: int getWFrame() { return walkFrame; }
};

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