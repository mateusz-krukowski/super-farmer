#include "AssetManager.h"

AssetManager::AssetManager() {
	 AtticAntique = LoadFontEx("assets/AtticAntique.ttf",50,0, NULL);
}
AssetManager::~AssetManager() {
	UnloadFont(AtticAntique);    // Default font unloading
}

AssetManager& AssetManager::getInstance()
{
	static AssetManager instance;
	return instance;
}

void AssetManager::loadFont(Font* font, const char* fontName) {
	
}