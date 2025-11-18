#include "utils.h"

#include "globals.h"

namespace Utils
{
	float PercentToPixelsX(float percentX)
	{
		return (percentX / 100.0f) * Externs::screenWidth;
	}

	float PercentToPixelsY(float percentY)
	{
		return (percentY / 100.0f) * Externs::screenHeight;
	}

	float PixelsToPercentX(float px)
	{
		return (px / Externs::screenWidth) * 100.0f;
	}

	float PixelsToPercentY(float py)
	{
		return (py / Externs::screenHeight) * 100.0f;
	}
}
