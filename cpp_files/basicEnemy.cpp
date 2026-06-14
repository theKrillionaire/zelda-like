#include "basicEnemy.h"
#include <math.h>
#include "player.h"
#include "pathfinding.h"

Vector2 enemy::getPos() const {
	return pos;
}


void enemy::update(const player* p, const pathfinding* pathfind) {
		pathfind->findPath(p, this);
	}