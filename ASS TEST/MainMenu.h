// Module			: Gameplay Programming
// Assignment1		: Let It Rain
// Student Number	: Png Yeow Li
// Student Number	: S10164245H

#ifndef _MAINMENU_H
#define _MAINMENU_H
#define WIN32_LEAN_AND_MEAN

#include "game.h"
#include "textureManager.h"
#include "letitrain.h"
#include "image.h"
#include "textManager.h"
#include "rayCasting.h"

class MainMenu :public Game
{
private:
	TextureManager mmBackgroundTexture;
	TextureManager startButtonTexture;
	TextureManager exitButtonTexture;
	TextureManager pauseButtonTexture;
	TextureManager pauseMenuTexture;
	TextureManager resumeButtonTexture;
	TextureManager creditsButtonTexture;
	TextureManager leaderboardTexture;
	TextureManager backgroundTexture;
	TextureManager creditsPageTexture;
	TextureManager mainMenuButtonTexture;
	Image mmBackground;
	Image startButton;
	Image exitButton;
	Image pauseButton;
	Image pauseMenu;
	Image resumeButton;
	Image pExitButton;
	Image creditsButton;
	Image leaderboardButton;
	Image greyBackground;
	Image creditsPage;
	Image mainMenuButton;
	Letitrain *letItRain;
	bool start;
	bool credits;
	bool leaderboard;
	textManager *leaderboardText;

public:
	MainMenu();
	virtual ~MainMenu();

	void initialize(HWND hwnd);
	void update();
	void ai();
	void collisions();
	void render();
	void releaseAll();
	void resetAll();

};


#endif