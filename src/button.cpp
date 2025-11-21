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
		button.text.fontSize = 30;

		//button.currentTextureID = externs::buttonTextureID;
	}

	void Draw(Button& button)
	{
		
		Draw::DrawText(button.text);
	}
}

