#ifndef PATHFINDING_H
#define PATHFINDING_H

#include <raylib.h>
#include "player.h"

class pathfinding {
private:
	Vector2 getVectorDir();

public:
	void findPath(const player* p);
	
};


#endif