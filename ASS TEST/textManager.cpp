// Programming 2D Games
// Copyright (c) 2011 by: 
// Charles Kelly
// Chapter 8 threeCsDX.cpp v1.0

#include "textManager.h"

//=============================================================================
// Constructor
//=============================================================================
textManager::textManager()
{
	dxFontSmall = new TextDX();     // DirectX fonts
	dxFontMedium = new TextDX();
	dxFontLarge = new TextDX();
	textBox = new RECT();
	score = 0;
}

//=============================================================================
// Destructor
//=============================================================================
textManager::~textManager()
{
	releaseAll();               // call deviceLost() for every graphics item
	SAFE_DELETE(dxFontSmall);
	SAFE_DELETE(dxFontMedium);
	SAFE_DELETE(dxFontLarge);
}

//=============================================================================
// initializes the game
// Throws GameError on error
//=============================================================================
void textManager::initialize(Graphics *graphics)
{
	// initialize DirectX fonts
	// 15 pixel high Arial
	if (dxFontSmall->initialize(graphics, 15, true, false, "Arial") == false)
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing DirectX font"));

	// 62 pixel high Arial
	if (dxFontMedium->initialize(graphics, 30, true, false, "Arial") == false)
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing DirectX font"));

	// 124 pixel high Arial
	if (dxFontLarge->initialize(graphics, 124, true, false, "Arial") == false)
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing DirectX font"));

	if (dxFont.initialize(graphics, textNS::POINT_SIZE, false, false, textNS::FONT) == false)
		throw(GameError(gameErrorNS::FATAL_ERROR, "Failed to initialize DirectX font."));

	reset();            // reset all game variables
	return;
}


//=============================================================================
// Reset the game to begin play and after a score
//=============================================================================
void textManager::reset()
{
	return;
}

//=============================================================================
// move all game items
// frameTime is used to regulate the speed of movement
//=============================================================================
void textManager::update()
{
}

//=============================================================================
// render game items
//=============================================================================
void textManager::render()
{
	const int BUF_SIZE = 20;
	static char buffer[BUF_SIZE];

	_snprintf_s(buffer, BUF_SIZE, "Score: %d", (int)score);

	dxFontMedium->setFontColor(graphicsNS::WHITE);

	dxFontMedium->print(buffer, GAME_WIDTH / 3, 0);
	dxFont.setFontColor(textNS::FONT_COLOR);
}

//=============================================================================
// The graphics device was lost.
// Release all reserved video memory so graphics device may be reset.
//=============================================================================
void textManager::releaseAll()
{
	dxFontSmall->onLostDevice();
	dxFontMedium->onLostDevice();
	dxFontLarge->onLostDevice();
	return;
}

//=============================================================================
// The grahics device has been reset.
// Recreate all surfaces and reset all entities.
//=============================================================================
void textManager::resetAll()
{
	dxFontSmall->onResetDevice();
	dxFontMedium->onResetDevice();
	dxFontLarge->onResetDevice();
	return;
}
