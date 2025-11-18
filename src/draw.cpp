#include "draw.h"
#include "globals.h"
#include "utils.h"

#include "raylib.h"

namespace Draw
{
	void DrawText(Text::Text text)
	{
		DrawTextEx(text.font, text.text.c_str(), { (text.posX * Externs::screenWidth / 100.0f) - (MeasureText(text.text.c_str(), text.fonstSize)) / 2.4f, (text.posY * Externs::screenHeight / 100.0f) - (text.fonstSize / 2) }, static_cast<float>(text.fonstSize), static_cast<float>(text.spacing), text.color);
	}

	void DrawSpriteEx(float id, float posX, float posY, float width, float height, float rotation, Color tint)
	{
		Texture texture;

		texture.id = static_cast<unsigned int>(id);

		posX = Utils::PercentToPixelsX(posX);
		posY = Utils::PercentToPixelsY(posY);
		texture.width = static_cast<int>(Utils::PercentToPixelsX(width)),
			texture.height = static_cast<int>(Utils::PercentToPixelsY(height));

		DrawTextureEx(texture, { posX, posY }, rotation, 1.0f, tint);
	}
}
