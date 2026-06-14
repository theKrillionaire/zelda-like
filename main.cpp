#include <raylib.h>
#include "player.h"
#include <math.h>
#include "map.h"
#include "render.h"
#include <cstring>

enum SPR {
	MAP_TEST,
	SPRCOUNT
};

class player;

int main(int argc, char** argv) {
	bool debugCollision = false;
	if (argc > 1) {
		if(!strcmp(argv[1], "-dc") || !strcmp(argv[1], "--debugCollisions")) {
			debugCollision = true;
		}

	}
	InitWindow(340,240, "gay");
	SetTargetFPS(30);
	player p;
	int playerWFrame = 0;
	mapController map;
	renderer r;

	while(!WindowShouldClose()) {
		p.update(map.getMap(0), 4,0);
		r.drawScreen(0,&p,debugCollision);
	}
	return 0;
}