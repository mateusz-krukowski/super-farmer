#pragma once
#include <raylib.h>

class AssetManager
{
private:
	AssetManager();
public:
	~AssetManager();
	static AssetManager& getInstance();
	Font AtticAntique = { 0 };
	Font Helvetica = { 0 };
	Image Rabbit = { 0 };
	Image Sheep = { 0 };
	Image Pig = { 0 };
};

