#include "draw.h"
#include "globals.h"
#include "utils.h"

#include "raylib.h"

namespace Draw
{
	void DrawText(Text::Text text)
	{
		DrawTextEx(text.font, text.text.c_str(), { (text.posX * Externs::screenWidth / 100.0f) - (MeasureText(text.text.c_str(), text.fontSize)) / 2.4f, (text.posY * Externs::screenHeight / 100.0f) - (text.fontSize / 2) }, static_cast<float>(text.fontSize), static_cast<float>(text.spacing), text.color);
	}

	void DrawSpriteEx(Texture texture, float posX, float posY, float width, float height, float rotation, Color tint)
	{
		posX = Utils::PercentToPixelsX(posX);
		posY = Utils::PercentToPixelsY(posY);
		texture.width = static_cast<int>(Utils::PercentToPixelsX(width)),
			texture.height = static_cast<int>(Utils::PercentToPixelsY(height));

		DrawTextureEx(texture, { posX, posY }, rotation, 1.0f, tint);
	}
}
