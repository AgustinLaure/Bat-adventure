#include "obstacle.h"

#include "globals.h"

namespace variables
{
	static float velocity = 500.0f;
	static float offSet = 250.0f;
}

void obstacle::Initialization(Obstacle& obstacle)
{
	obstacle.textureID = 0;

	obstacle.width = 50.0f;
	obstacle.height = 400.0f;

	obstacle.bottom = { static_cast<float>(externs::screenWidth) - obstacle.width,  static_cast<float>(externs::screenHeight) - obstacle.height };
	obstacle.top = { obstacle.bottom.x,  (-obstacle.bottom.y + obstacle.height) - variables::offSet};

	obstacle.velocity = variables::velocity;
}

void obstacle::Update(Obstacle& obstacle)
{
	obstacle.bottom.x += -obstacle.velocity * externs::deltaT;
	obstacle.top.x = obstacle.bottom.x;

	obstacle::CheckOutOfBounds(obstacle);
}

void obstacle::Draw(Obstacle obstacle)
{
	DrawRectangle(static_cast<int>(obstacle.bottom.x), static_cast<int>(obstacle.bottom.y), static_cast<int>(obstacle.width), static_cast<int>(obstacle.height), RED);
	DrawRectangle(static_cast<int>(obstacle.top.x), static_cast<int>(obstacle.top.y), static_cast<int>(obstacle.width), static_cast<int>(obstacle.height), RED);
}

void obstacle::CheckOutOfBounds(Obstacle& obstacle)
{
	if (obstacle.bottom.x + obstacle.width < 0.0f)
	{
		obstacle.bottom.x = externs::screenWidth + obstacle.width;
	}
}
