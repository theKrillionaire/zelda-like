#include "pathfinding.h"
#include <raylib.h>
#include "player.h"
#include <math.h>
#include <stdio.h>
#include <algorithm>

Vector2 pathfinding::dirToPlayer(const player* p, const enemy* e) {
	Vector2 playerPos = p->getPos();
	Vector2 enemyPos = e->getPos();
	Vector2 dir = {
		std::clamp(playerPos.x - enemyPos.x, -1.0f, 1.0f),
		std::clamp(playerPos.y - enemyPos.y, -1.0f, 1.0f)

	};
}

void pathfinding::findPath(const player* p, const enemy* e) {
	Vector2 clamped = dirToPlayer(p, e);
	printf("clamped dir: X %i, Y %i\n", clamped.x, clamped.y);
}