#include <cstddef>
#include "AssetManager.h"

AssetManager::AssetManager() {
	 AtticAntique = LoadFontEx("assets/AtticAntique.ttf",50,0, 0);
	 Helvetica = LoadFontEx("assets/Helvetica.ttf", 50, 0, 0);
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
