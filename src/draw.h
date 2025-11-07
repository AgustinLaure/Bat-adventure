#pragma once
#include "text.h"

namespace draw
{
	void DrawText(text::Text text);
	void DrawSpriteEx(float id, float posX, float posY, float width, float height, float rotation, Color tint);
}
