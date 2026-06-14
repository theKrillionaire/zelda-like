#ifndef PATHFINDING_H
#define PATHFINDING_H

#include <raylib.h>
#include "player.h"
//#include "basicEnemy.h"

class enemy;

class pathfinding {
private:
	Vector2 dirToPlayer(const player* p, const enemy* e);

public:
	void findPath(const player*, const enemy*);
	
};


#endif