#include "map.h"
#include <raylib.h>
#include <stdio.h>

std::vector<Rectangle> mapController::getMap(int map) {
	const static std::vector<std::vector<Rectangle>> maps = {
		{
		{0,0,32,640},
		{640,0,32,640},
		{0,0,640,32},
		{0,610,640,32},
		}
	};
	return maps[map];
		
}