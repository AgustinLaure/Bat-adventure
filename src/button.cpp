#include "button.h"
#include "globals.h"
#include "draw.h"
#include "utils.h"

namespace Buttons
{
	void Initialize(Button& button, float width, float height, float posX, float posY)
	{
		button.position = { posX, posY };
		button.width = width;
		button.height = height;

		//button.text.font = externs::defaultText.font;
		button.text.posX = posX;
		button.text.posY = posY;
		button.text.fonstSize = 30;

		//button.currentTextureID = externs::buttonTextureID;
	}

	void Draw(Button& button)
	{
		//draw::DrawSprite(static_cast<float>(button.currentTextureID), static_cast<float>(button.position.x) - 0.5f, static_cast<float>(button.position.y) + 3.5f, 2 * button.width, 6 * button.height, button.color);
		Draw::DrawText(button.text);
	}
}

