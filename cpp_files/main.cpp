#include <raylib.h>
#include "player.h"
#include <math.h>
#include "map.h"
#include "render.h"
#include <cstring>
#include "basicEnemy.h"
#include "pathfinding.h"
#include <vector>

// TODO:
//   mapManager :
// 	    make renderer->std::vector maps pull from json files or something. for modularity
//      make mapController control the renderers' map image from the json
//
//   pathfinding :
//      make it actually fucking find paths around collision (far future.)
//
//	 enemy :
//	    make the enemy collide and shit


enum SPR {
	MAP_TEST,
	SPRCOUNT
};

class player;

int main(int argc, char** argv) {
	bool loading = true;
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
	mapManager map;
	renderer r;
	enemy e;
	pathfinding pathfinder;
	std::vector<Rectangle> curMap = map.getMap("maps/map1.map");

	while(!WindowShouldClose()) {
		e.update(&p, &pathfinder);
		p.update(curMap,0);
		r.drawScreen(0,&p,debugCollision,&e);
	}
	return 0;
}
