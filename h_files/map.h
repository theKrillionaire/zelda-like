#ifndef MAP_H
#define MAP_H

#include <raylib.h>
#include <vector>
#include <stdio.h>

class mapManager {
public:
	std::vector<Rectangle> getMap(char path[256]);
};

#endif