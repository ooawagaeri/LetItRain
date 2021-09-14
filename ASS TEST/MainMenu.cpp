// Module			: Gameplay Programming
// Assignment1		: Let It Rain
// Student Number	: Png Yeow Li
// Student Number	: S10164245H

#include "MainMenu.h"
#include "textManager.h"
#include <fstream>
#include <string>

textManager *leaderboardText = NULL;
Ray *test = NULL;

MainMenu::MainMenu()
{
	letItRain = new Letitrain();
	leaderboardText = new textManager();
	start = false;
	credits = false;
	leaderboard = false;
}

MainMenu::~MainMenu()
{
	releaseAll();
}

void MainMenu::initialize(HWND hwnd)
{
	Game::initialize(hwnd);
	//audio->playCue(TITLE);

	if (!mmBackgroundTexture.initialize(graphics, MMBACKGROUND_IMAGE))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing Main Menu Background"));

	if (!mmBackground.initialize(graphics, 458, 610, 1, &mmBackgroundTexture))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing Main Menu Background"));

	mmBackground.setScale(1.345);

	if (!startButtonTexture.initialize(graphics, STARTBUTTON_IMAGE))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing Buttons"));

	if (!startButton.initialize(graphics, 203, 73, 1, &startButtonTexture))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing Buttons"));

	startButton.setX(GAME_WIDTH / 20);
	startButton.setY(5 * GAME_HEIGHT / 8);

	if (!exitButtonTexture.initialize(graphics, EXITBUTTON_IMAGE))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing exit button"));

	if (!exitButton.initialize(graphics, 203, 73 , 1, &exitButtonTexture))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing Buttons"));
	
	exitButton.setX(12 * GAME_WIDTH / 20);
	exitButton.setY(5 * GAME_HEIGHT / 8);

	// pause
	if (!pauseButtonTexture.initialize(graphics, PAUSEBUTTON_IMAGE))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing Pause"));

	if (!pauseButton.initialize(graphics, 0, 0, 0, &pauseButtonTexture))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing Pause"));

	pauseButton.setX(GAME_WIDTH - pauseButton.getWidth());
	pauseButton.setY(0);

	// Pause screen
	if (!pauseMenuTexture.initialize(graphics, PAUSEMENU_IMAGE))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing Pause Menu"));

	if (!pauseMenu.initialize(graphics, 0, 0, 0, &pauseMenuTexture))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing Pause Menu"));

	// Resume Button
	if (!resumeButtonTexture.initialize(graphics, RESUMEBUTTON_IMAGE))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing resume button"));

	if (!resumeButton.initialize(graphics, 0, 0, 0, &resumeButtonTexture))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing resume button"));

	resumeButton.setX((GAME_WIDTH / 2) - (resumeButton.getWidth() / 2));
	resumeButton.setY(3 * (GAME_HEIGHT / 8));

	// Pause Exit Button
	if (!pExitButton.initialize(graphics, 0, 0, 0, &exitButtonTexture))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing Pause Exit Button"));

	pExitButton.setX(resumeButton.getX());
	pExitButton.setY(GAME_HEIGHT / 2);

	// Credit Button 
	if (!creditsButtonTexture.initialize(graphics, CREDITSBUTTON_IMAGE))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing Credit Button"));

	if (!creditsButton.initialize(graphics, 0, 0, 0, &creditsButtonTexture))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing Credit Button"));

	creditsButton.setX(GAME_WIDTH / 20);
	creditsButton.setY(6 * GAME_HEIGHT / 8);

	// Leaderboard Button
	if (!leaderboardTexture.initialize(graphics, LEADERBOARDBUTTON_IMAGE))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing Leaderboard Button"));

	if (!leaderboardButton.initialize(graphics, 0, 0, 0, &leaderboardTexture))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing Leaderboard Button"));

	leaderboardButton.setX(12 * GAME_WIDTH / 20);
	leaderboardButton.setY(6 * GAME_HEIGHT / 8);

	// Grey background
	if (!backgroundTexture.initialize(graphics, GREYBACKGROUND_IMAGE))
		throw(GameError(gameErrorNS::FATAL_ERROR,"Error initializing Grey Background"));

	if (!greyBackground.initialize(graphics, 0, 0, 0, &backgroundTexture))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing Grey Background"));

	// Credit Page 
	if (!creditsPageTexture.initialize(graphics, CREDITSPAGE_IMAGE))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing Credit Page"));

	if (!creditsPage.initialize(graphics, 0, 0, 0, &creditsPageTexture))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing Credit Page"));

	// Main Menu Button 
	if (!mainMenuButtonTexture.initialize(graphics, MAINMENUBUTTON_IMAGE))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing Main Menu Button"));

	if (!mainMenuButton.initialize(graphics, 0, 0, 0, &mainMenuButtonTexture))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing Main Menu Button"));

	mainMenuButton.setX(GAME_WIDTH / 2 - mainMenuButton.getWidth() / 2);
	mainMenuButton.setY(3 * (GAME_HEIGHT / 4));

	test = new Ray(input);

	return;
}

void MainMenu::update()
{
	// Initializing Main game
	if (input->getMouseLButton() && start == false &&
		input->getMouseX() > startButton.getX() && input->getMouseX() < (startButton.getX() + startButton.getWidth()) &&
		input->getMouseY() > startButton.getY() && input->getMouseY() < (startButton.getY() + startButton.getHeight()))
	{
		letItRain->initialize(graphics, input, audio, &hwnd, &hr, &timeStart, &timeEnd, &timerFreq, &frameTime, &fps,
		  &dxFont, &fpsOn, &sleepTime, &paused, &initialized);
		start = true;
		audio->stopCue(TITLE);
		return;
	}
	if (start && !letItRain->getPause())
		letItRain->update();

	// Exiting the game
	if (input->getMouseLButton() && start == false &&
		input->getMouseX() > exitButton.getX() && input->getMouseX() < (exitButton.getX() + exitButton.getWidth()) &&
		input->getMouseY() > exitButton.getY() && input->getMouseY() < (exitButton.getY() + exitButton.getHeight()))
	{
		MainMenu::Game::exitGame();
		return;
	}

	// In-game pause
	if (input->getMouseLButton() && start == true &&
		input->getMouseX() > pauseButton.getX() && input->getMouseX() < (pauseButton.getX() + pauseButton.getWidth()) &&
		input->getMouseY() > pauseButton.getY() && input->getMouseY() < (pauseButton.getY() + pauseButton.getHeight()))
	{
		letItRain->setPause(true);
		audio->stopCue(BEATDOWN);
		audio->stopCue(INTRO);
		return;
	}

	// Pause Menu Resume Button 
	if (input->getMouseLButton() && letItRain->getPause() &&
		input->getMouseX() > resumeButton.getX() && input->getMouseX() < (resumeButton.getX() + resumeButton.getWidth()) &&
		input->getMouseY() > resumeButton.getY() && input->getMouseY() < (resumeButton.getY() + resumeButton.getHeight()))
	{
		letItRain->setPause(false);
		audio->stopCue(BEATDOWN);
		audio->stopCue(INTRO);
		audio->playCue(INTRO);
		return;
	}

	// Pause Menu Exit Button
	if (input->getMouseLButton() && letItRain->getPause() &&
		input->getMouseX() > pExitButton.getX() && input->getMouseX() < (pExitButton.getX() + pExitButton.getWidth()) &&
		input->getMouseY() > pExitButton.getY() && input->getMouseY() < (pExitButton.getY() + pExitButton.getHeight()))
	{
		letItRain->setPause(false);
		audio->stopCue(BEATDOWN);
		audio->stopCue(INTRO);
		audio->playCue(INTRO);
		letItRain->resetAll();
		start = false;
		return;
	}

	// Credits page
	if (input->getMouseLButton() && start == false && credits == false &&
		input->getMouseX() > creditsButton.getX() && input->getMouseX() < (creditsButton.getX() + creditsButton.getWidth()) &&
		input->getMouseY() > creditsButton.getY() && input->getMouseY() < (creditsButton.getY() + creditsButton.getHeight()))
	{
		credits = true;
		return;
	}

	// Credits page Menu Button
	if (input->getMouseLButton()  && credits == true &&
		input->getMouseX() > mainMenuButton.getX() && input->getMouseX() < (mainMenuButton.getX() + mainMenuButton.getWidth()) &&
		input->getMouseY() > mainMenuButton.getY() && input->getMouseY() < (mainMenuButton.getY() + mainMenuButton.getHeight()))
	{
		credits = false;
		return;
	}

	// Leaderboard page
	if (input->getMouseLButton() && start == false && leaderboard == false &&
		input->getMouseX() > leaderboardButton.getX() && input->getMouseX() < (leaderboardButton.getX() + leaderboardButton.getWidth()) &&
		input->getMouseY() > leaderboardButton.getY() && input->getMouseY() < (leaderboardButton.getY() + leaderboardButton.getHeight()))
	{
		leaderboard = true;
		return;
	}
	if (input->getMouseLButton() && leaderboard == true &&
		input->getMouseX() > mainMenuButton.getX() && input->getMouseX() < (mainMenuButton.getX() + mainMenuButton.getWidth()) &&
		input->getMouseY() > mainMenuButton.getY() && input->getMouseY() < (mainMenuButton.getY() + mainMenuButton.getHeight()))
	{
		leaderboard = false;
		return;
	}

	// Gameover/Congratulation screen
	if (input->getMouseLButton() && letItRain->getGameOver() == true &&
		input->getMouseX() > mainMenuButton.getX() && input->getMouseX() < (mainMenuButton.getX() + mainMenuButton.getWidth()) &&
		input->getMouseY() > mainMenuButton.getY() && input->getMouseY() < (mainMenuButton.getY() + mainMenuButton.getHeight()))
	{
		letItRain->resetAll();
		start = false;
		audio->stopCue(FINISH);
		audio->playCue(TITLE);
		letItRain->setGameOver(false);
		return;
	}
}

void MainMenu::ai()
{
	if (start)
		letItRain->ai();
}

void MainMenu::collisions()
{
	if (start)
		letItRain->collisions();
}

void MainMenu::render()
{
	graphics->spriteBegin();

	if (!start)
	{
		mmBackground.draw();
		startButton.draw();
		exitButton.draw();
		creditsButton.draw();
		//leaderboardButton.draw();
	}

	if (start)
	{
		letItRain->render();
		pauseButton.draw();
	}

	if (letItRain->getPause())
	{
		pauseMenu.draw();
		resumeButton.draw();
		pExitButton.draw();
	}

	if (credits)
	{
		creditsPage.draw();
		mainMenuButton.draw();
	}

	if (leaderboard)
	{
		greyBackground.draw();
		leaderboardText->render();
		mainMenuButton.draw();

	}

	if (letItRain->getGameOver())
	{
		mainMenuButton.draw();
	}

	test->UpdateVision(*letItRain->getEMList().getHunters());
	test->Render(graphics);
	
	graphics->spriteEnd();
/*
	CUSTOMVERTEX vertex[] =
	{
		{ 700.0f, 500.0f, 0.5f, 1.0f, graphicsNS::WHITE & D3DCOLOR_ARGB(255,255,255,255) },
		{ 100.0f, 250.0f, 0.5f, 1.0f, D3DCOLOR_ARGB(0,0,0,0) },
		{ 400.0f, 50.0f, 0.5f, 1.0f, D3DCOLOR_ARGB(0,0,0,0) },
		{ input->getMouseX(), input->getMouseY(), 0.5f, 1.0f, graphicsNS::WHITE & D3DCOLOR_ARGB(255,255,255,255) },
		{ 100.0f, 250.0f, 0.5f, 1.0f, D3DCOLOR_ARGB(0,0,0,0) },
		{ 400.0f, 50.0f, 0.5f, 1.0f, D3DCOLOR_ARGB(0,0,0,0) }
	};

	for each (CUSTOMVERTEX v in vertex)
		vecList.push(v);*/

	//int size = vecList.size() / 3;
	//for (int i = 0; i < size; i++)
	//	graphics->initGraphics(&vecList);

}

void MainMenu::releaseAll()
{
	mmBackgroundTexture.onLostDevice();
	startButtonTexture.onLostDevice();
	exitButtonTexture.onLostDevice();
	creditsButtonTexture.onLostDevice();
	leaderboardTexture.onLostDevice();
	mainMenuButtonTexture.onLostDevice();


	if (start)
	{
		letItRain->releaseAll();
		pauseButtonTexture.onLostDevice();
	}

	if (letItRain->getPause())
	{
		pauseMenuTexture.onLostDevice();
		resumeButtonTexture.onLostDevice();
	}

	if (credits)
	{
		creditsPageTexture.onLostDevice();
	}

	if (leaderboard)
	{
		leaderboardText->releaseAll();
	}
}

void MainMenu::resetAll()
{
	mmBackgroundTexture.onResetDevice();
	startButtonTexture.onResetDevice();
	exitButtonTexture.onResetDevice();
	creditsButtonTexture.onLostDevice();
	leaderboardTexture.onLostDevice();
	mainMenuButtonTexture.onResetDevice();


	if (start)
	{
		letItRain->resetAll();
		pauseButtonTexture.onLostDevice();
	}

	if (letItRain->getPause())
	{
		pauseMenuTexture.onResetDevice();
		resumeButtonTexture.onResetDevice();
	}

	if (credits)
	{
		creditsPageTexture.onResetDevice();
	}

	if (leaderboard)
	{
		leaderboardText->resetAll();
	}
}