#include "globals.h"

namespace Externs
{
	float deltaT;

	int screenWidth = 1250;
	int screenHeight = 768;

	bool retry = false;
	bool hasLost = false;

	std::string backgroundFrontTexture = "res/placeholder_front.png";
	int backgroundFrontTextureID = 0;

	std::string backgroundMiddleTexture = "res/placeholder_middle.png";
	int backgroundMiddleTextureID = 0;

	std::string backgroundBackTexture = "res/placeholder_back.png";
	int backgroundBackTextureID = 0;
}
