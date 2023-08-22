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
	void loadFont(Font* font, const char* fontName);

};

