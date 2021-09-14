// Programming 2D Games
// Copyright (c) 2011 by: 
// Charles Kelly
// Chapter 8 threeCsDX.h v1.0

#ifndef _THREECS_H              // Prevent multiple definitions if this 
#define _THREECS_H              // file is included in more than one place
#define WIN32_LEAN_AND_MEAN

#include "textDX.h"
#include "constants.h"

namespace textNS
{
	const char FONT[] = "Courier New";						// Font
	const int POINT_SIZE = 20;									// Point size
	const COLOR_ARGB FONT_COLOR = SETCOLOR_ARGB(255, 255, 255, 255);	// White
}

class textManager
{
protected:
	TextDX	dxFont;
	float	fps;
	int		score;

private:
	// game items	
	TextDX  *dxFontSmall;       // DirectX fonts
	TextDX  *dxFontMedium;
	TextDX  *dxFontLarge;
	RECT	*textBox;

	// game variables

public:
	textManager();
	virtual ~textManager();
	void initialize(Graphics *graphics);
	void reset();
	void update();
	void render();
	void releaseAll();
	void resetAll();

	void incrementScore(int add) { score += add; }
};

#endif
