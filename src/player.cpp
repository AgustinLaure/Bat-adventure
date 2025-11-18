#include "player.h"
#include "globals.h"

#include <iostream>

namespace Player
{
	namespace Variables
	{
		static float velocity = 500.0f;
	}

	void Initialization(Bird& bird, KeyboardKey moveUpKey, Vector2 pos)
	{
		bird.textureID = 0;

		bird.position = pos;

		bird.velocity = 0.0f;

		bird.isOn = true;

		bird.moveUpKey = moveUpKey;
	}

	void Update(Bird& bird)
	{
		bird.velocity -= Globals::acceleration * Externs::deltaT;

		if (IsPlayerMoving(bird.moveUpKey))
		{
			bird.velocity = Variables::velocity;
		}

		bird.position.y -= bird.velocity * Externs::deltaT;

		CheckState(bird);
	}

	void Draw(Bird bird)
	{
		DrawCircleV(bird.position, 30.0f, BLUE);
	}

	bool IsPlayerMoving(KeyboardKey moveUpKey)
	{
		return IsKeyPressed(moveUpKey);
	}

	bool HasLost(Bird bird)
	{
		return bird.position.y - (30.0f / 2.0f) > (Externs::screenHeight + 30.0f);
	}

	bool IsTouchingCeiling(Bird bird)
	{
		return (bird.position.y - 30.0f) < 0;
	}

	void CheckState(Bird& bird)
	{
		if (HasLost(bird))
		{
			bird.isOn = false;
		}
		if (IsTouchingCeiling(bird))
		{
			bird.position.y = 30.0f;
			bird.velocity = 0.0f;
		}
	}
}

