#pragma once
#include "text.h"

namespace Draw
{
	void DrawText(Text::Text text);
	void DrawSpriteEx(Texture& texture, float posX, float posY, float width, float height, float rotation, Color tint);
}
