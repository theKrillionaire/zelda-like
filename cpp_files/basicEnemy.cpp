#include "basicEnemy.h"
#include <math.h>
#include "player.h"
#include "pathfinding.h"

Vector2 enemy::getPos() const {
	return pos;
}


void enemy::update(const player* p, const pathfinding* pathfind) {
		if (timerMove > 0) {
			timerMove--;
		} else {
			if(timerMoving > 0) {
				Vector2 dir = pathfind->findPath(p, this);
				pos.x += dir.x;
				pos.y += dir.y;
				timerMoving--;
		} else {
			timerMove = 30;
			timerMoving = 10;
		}
	}
}