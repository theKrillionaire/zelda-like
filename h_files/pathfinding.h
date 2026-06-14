#ifndef PATHFINDING_H
#define PATHFINDING_H

#include <raylib.h>
#include "player.h"
//#include "basicEnemy.h"

class enemy;

class pathfinding {
private:
	Vector2 dirToPlayer(const player* p, const enemy* e) const;

public:
	Vector2 findPath(const player*, const enemy*) const;
	
};


#endif