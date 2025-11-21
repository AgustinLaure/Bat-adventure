#include "obstacle.h"

#include "globals.h"

namespace Obstacle
{
	namespace Assets
	{
		static Texture sprite;
	}

	namespace Variables
	{
	static float velocity = 500.0f;
	static float offSet = 250.0f;
	}

	void Initialization(Obstacle& obstacle)
	{
		Assets::sprite = LoadTexture(Externs::obstacleSprite.c_str());

		obstacle.width = 70.0f;
		obstacle.height = 700.0f;

		float obstacleSpace = 200.0f;
		float offset = 15.0f;
		Vector2 gap = { static_cast<float>(Externs::screenWidth) , static_cast<float>(GetRandomValue(static_cast<int>(offset), static_cast<int>(Externs::screenHeight - offset - obstacleSpace))) };
		obstacle.bottom = { static_cast<float>(Externs::screenWidth), gap.y - obstacle.height };
		obstacle.top = { obstacle.bottom.x, gap.y + obstacleSpace };

		obstacle.velocity = Variables::velocity;

		obstacle.passed = false;
	}

	void Update(Obstacle& obstacle)
	{
		obstacle.bottom.x += -obstacle.velocity * Externs::deltaT;
		obstacle.top.x = obstacle.bottom.x;

		if (CheckOutOfBounds(obstacle))
		{
			float obstacleSpace = 200.0f;
			float offset = 15.0f;
			Vector2 gap = { static_cast<float>(Externs::screenWidth) , static_cast<float>(GetRandomValue(static_cast<int>(offset), static_cast<int>(Externs::screenHeight - offset - obstacleSpace))) };
			obstacle.bottom = { static_cast<float>(Externs::screenWidth), gap.y - obstacle.height };
			obstacle.top = { obstacle.bottom.x, gap.y + obstacleSpace };
			obstacle.passed = false;
		}
	}

	void Draw(Obstacle obstacle)
	{
		DrawTextureEx(Assets::sprite, { obstacle.bottom.x -166, obstacle.top.y }, 0, 0.7f, WHITE);
		DrawTextureEx(Assets::sprite, { obstacle.bottom.x+ obstacle.width + 166, obstacle.top.y-700.0f/2 +150.0f}, 180, 0.7f, WHITE);
	}

	bool CheckOutOfBounds(Obstacle& obstacle)
	{
		return (obstacle.bottom.x + obstacle.width < 0.0f);
	}
}

