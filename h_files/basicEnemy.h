#ifndef BASICENEMY_H
#define BASICENEMY_H

#include <raylib.h>
#include "player.h"
#include "pathfinding.h"

class enemy {
private:
	Vector2 pos = {200,200};

public:
	Vector2 setPos(Vector2 pos);
	Vector2 getPos() const;
	void update(const player* p, const pathfinding* pathfind);

};

#endif