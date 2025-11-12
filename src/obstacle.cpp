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
	obstacle.height = 700.0f;

	float obstacleSpace = 200.0f;
	float offset = 15.0f;
	Vector2 gap = { static_cast<float>(externs::screenWidth) , static_cast<float>(GetRandomValue(static_cast<int>(offset), static_cast<int>(externs::screenHeight - offset - obstacleSpace))) };
	obstacle.bottom = { static_cast<float>(externs::screenWidth), gap.y - obstacle.height };
	obstacle.top = { obstacle.bottom.x, gap.y + obstacleSpace };

	obstacle.velocity = variables::velocity;
}

void obstacle::Update(Obstacle& obstacle)
{
	obstacle.bottom.x += -obstacle.velocity * externs::deltaT;
	obstacle.top.x = obstacle.bottom.x;

	if (obstacle::CheckOutOfBounds(obstacle))
	{
		float obstacleSpace = 200.0f;
		float offset = 15.0f;
		Vector2 gap = { static_cast<float>(externs::screenWidth) , static_cast<float>(GetRandomValue(static_cast<int>(offset), static_cast<int>(externs::screenHeight - offset - obstacleSpace)))};
		obstacle.bottom = { static_cast<float>(externs::screenWidth), gap.y - obstacle.height };
		obstacle.top = { obstacle.bottom.x, gap.y + obstacleSpace };
	}
}

void obstacle::Draw(Obstacle obstacle)
{
	DrawRectangle(static_cast<int>(obstacle.bottom.x), static_cast<int>(obstacle.bottom.y), static_cast<int>(obstacle.width), static_cast<int>(obstacle.height), RED);
	DrawRectangle(static_cast<int>(obstacle.top.x), static_cast<int>(obstacle.top.y), static_cast<int>(obstacle.width), static_cast<int>(obstacle.height), RED);
}

bool obstacle::CheckOutOfBounds(Obstacle& obstacle)
{
	return (obstacle.bottom.x + obstacle.width < 0.0f);		
}
