#pragma once
#include <string>

namespace Externs
{
	extern float deltaT;

	extern int screenWidth;
	extern int screenHeight;

	extern bool retry;
	extern bool hasLost;

	extern std::string backgroundFrontTexture;
	extern int backgroundFrontTextureID;

	extern std::string backgroundMiddleTexture;
	extern int backgroundMiddleTextureID;

	extern std::string backgroundBackTexture;
	extern int backgroundBackTextureID;
}

namespace Globals
{
	const float acceleration = 981.0f;
}