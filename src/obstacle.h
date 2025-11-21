#pragma once
#include "raylib.h"

namespace Obstacle
{
	struct Obstacle
	{
		Vector2 top;
		Vector2 bottom;
		
		float velocity;

		float width;
		float height;

		bool passed;
	};

	void Initialization(Obstacle& obstacle);
	void Update(Obstacle& obstacle);
	void Draw(Obstacle obstacle);

	bool CheckOutOfBounds(Obstacle& obstacle);
}
