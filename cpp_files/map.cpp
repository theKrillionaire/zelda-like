#include "map.h"
#include <raylib.h>
#include <string>
#include <fstream>
#include <iostream>

std::vector<Rectangle> mapManager::getMap(char path[256]) {
	std::ifstream file(path);
	
	std::vector<Rectangle> map;
	
	if(!file.is_open()) {
		printf("error!!! error loading file %s!!! fuck you!!", path);
	} else {
		char* buffer;

		file.seekg(0, std::ios::end);
		int length = file.tellg();
		file.seekg(0,std::ios::beg);
		buffer = new char[length];
		file.read(buffer,length);
		file.close();
		printf(buffer);
	}
	return map;
		
}
