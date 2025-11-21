#pragma once
#include <string>

namespace Externs
{
	extern float deltaT;

	extern int screenWidth;
	extern int screenHeight;

	extern std::string backgroundFrontTexture;

	extern std::string backgroundMiddleTexture;

	extern std::string backgroundBackTexture;

	extern std::string playingSong;

	extern std::string menuSong;

	extern std::string selectSound;

	extern std::string pauseSound;

	extern std::string flapSound;

	extern std::string birdHitSound;

	extern std::string birdFallSound;

	extern std::string batSprite;

	extern std::string obstacleSprite;
}

namespace Globals
{
	const float acceleration = 981.0f;
}