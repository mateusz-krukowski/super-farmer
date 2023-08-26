#include "AssetManager.h"

AssetManager::AssetManager() {
	 AtticAntique = LoadFontEx("assets/AtticAntique.ttf",50,0, NULL);
	 Helvetica = LoadFontEx("assets/Helvetica.ttf", 50, 0, NULL);
}
AssetManager::~AssetManager() {
	UnloadFont(AtticAntique);    // Default font unloading
	UnloadFont(Helvetica);    // Default font unloading
}

AssetManager& AssetManager::getInstance()
{
	static AssetManager instance;
	return instance;
}
