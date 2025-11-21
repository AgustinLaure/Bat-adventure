#pragma once
#include "raylib.h"

namespace Player
{
	struct Bird
	{
		Vector2 position;

		float velocity;

		bool isOn;

		KeyboardKey moveUpKey;

		//Texture texture;
	};

	void Initialization(Bird& bird, KeyboardKey moveUpKey, Vector2 pos);
	void Update(Bird& bird);
	void Draw(Bird bird);

	bool IsPlayerMoving(KeyboardKey moveUpKey);

	bool IsTouchingCeiling(Bird bird);
	bool HasLost(Bird bird);

	void CheckState(Bird& bird);
}