#include <raylib.h>
#include <iostream>

class player {
	Vector2 pos = {170,120};
	Vector2 dir = {0, 0};
	Rectangle collider = { 170,120,40,40 };
	Rectangle checkCollider = { 170,120,40,40 };
	float speed = 2.5;
	int touchingWall = 0;
	public: void update(Rectangle* walls, int wallcount) {
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
};

int main() {
	InitWindow(340,240, "gay");
	SetTargetFPS(30);
	player p;
	Vector2 playerPos = { 0, 0 };
	Rectangle walls[4] = {
		{0,0,20,240},
		{320,0,20,240},
		{0,0,340,20},
		{0,220,340,20},
	};
	while(!WindowShouldClose()) {
		p.update(walls, 4);
		playerPos = p.getPos();
		BeginDrawing();
			ClearBackground(BLACK);
			for(int i = 0; i < 4; i++) {
				DrawRectangleLines(walls[i].x, walls[i].y , walls[i].width, walls[i].height, RED); 
			}
			DrawRectangleLines(playerPos.x, playerPos.y , 40, 40, WHITE); 
			//DrawText("test",playerPos.x, playerPos.y, 20, WHITE);
		EndDrawing();
	}
	return 0;
}