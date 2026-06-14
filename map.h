#ifndef MAP_H
#define MAP_H

#include <raylib.h>
#include <vector>
#include <stdio.h>

class mapController {
public:
	std::vector<Rectangle> getMap(int map);

};

#endif