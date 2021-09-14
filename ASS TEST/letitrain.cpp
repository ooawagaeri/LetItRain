// Programming 2D Games
// Copyright (c) 2011 by: 
// Charles Kelly
// Draw animated spaceships with collision and shield
// Chapter 6 spacewar.cpp v1.0
// This class is the core of the game

#include "letitrain.h"
#include "MainMenu.h"
#include "textManager.h"
#include "rayCasting.h"


//=============================================================================
// Constructor
//=============================================================================
textManager *text = NULL;

Letitrain::Letitrain()
{ 
	stage = 3;
	text = new textManager;
	timeModifier = 1;
	bulletshipHealth = bulletship.getHealth();
	lasershipHealth = lasership.getHealth();
	gameover = false;
}

//=============================================================================
// Destructor
//=============================================================================
Letitrain::~Letitrain()
{
    releaseAll();           // call onLostDevice() for every graphics item
	pwM.detachThread();
}

//=============================================================================
// Initializes the game
// Throws GameError on error
//=============================================================================
void Letitrain::initialize(Graphics *graphicsM, Input* inputM, Audio *audioM, HWND *hwndM, HRESULT *hrM, LARGE_INTEGER *timeStartM, LARGE_INTEGER *timeEndM,
	LARGE_INTEGER *timerFreqM, float *frameTimeM, float *fpsM,
	TextDX *dxFontM, bool *fpsOnM, DWORD *sleepTimeM, bool *pausedM, bool *initializedM) {
	graphics = graphicsM;
	input = inputM;
	audio = audioM;
	hwnd = *hwndM;
	hr = *hrM;
	timeStart = *timeStartM;
	timeEnd = *timeEndM;
	timerFreq = *timerFreqM;
	frameTime = *frameTimeM;
	dxFont = *dxFontM;
	sleepTime = *sleepTimeM;
	paused = *pausedM;
	initialized = *initializedM;

	// Heart Texture
	if (!heartTexture.initialize(graphics, HEART_IMAGE))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing Heart"));

	// Heart 1
	if (!heart1.initialize(graphics, 0, 0, 0, &heartTexture))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing Heart"));

	// Heart 2
	if (!heart2.initialize(graphics, 0, 0, 0, &heartTexture))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing Heart"));

	// Heart 3
	if (!heart3.initialize(graphics, 0, 0, 0, &heartTexture))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing Heart"));

	heart1.setX(1);
	heart1.setY(3);
	heart2.setX(heart1.getX() + heart1.getWidth() + 0.5);
	heart2.setY(heart1.getY());
	heart3.setX(heart2.getX() + heart2.getWidth() + 0.5);
	heart3.setY(heart2.getY());

	// GameOver Texture
	if (!gameOverTexture.initialize(graphics, GAMEOVER_IMAGE))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing GameOver"));

	if (!gameOver.initialize(graphics, 0, 0, 0, &gameOverTexture))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing GameOver"));

	// Congratulations Texture
	if (!congratulationsTexture.initialize(graphics, CONGRATULATIONS_IMAGE))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing Congratulations"));

	if (!congratulations.initialize(graphics, 0, 0, 0, &congratulationsTexture))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing Congratulations"));

    // nebula texture
    if (!mapTexture.initialize(graphics,MAP_IMAGE))
        throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing map texture"));

	// power up texture
	if (!pwTextures.initialize(graphics, PW_IMAGE))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing power up texture"));

	// weapon texture
	if (!weaponTextures.initialize(graphics, WEAPON_IMAGE))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing weaspon texture"));

  if (!map.initialize(this,0,0,mapNS::TEXTURE_COLS,&mapTexture, stage))
     throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing map"));

	// enemyShip textures
	if (!enemyTextures.initialize(graphics, ENEMY_IMAGE))
		 throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing game textures"));

    // playership textures
	if (!playershipTextures.initialize(graphics, PLAYERSHIP_IMAGE))
	 throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing game textures"));

	// playership2 textures
	if (!playership2Textures.initialize(graphics, PLAYERSHIP2_IMAGE))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing game textures"));

	// bulletship
	if (!bulletship.initialize(this, bulletshipNS::WIDTH, bulletshipNS::HEIGHT, bulletshipNS::TEXTURE_COLS, &playershipTextures, &pwTextures))
	 throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing bulletship"));
	
	 //lasership
	if (!lasership.initialize(this, lasershipNS::WIDTH, lasershipNS::HEIGHT, lasershipNS::TEXTURE_COLS, &playership2Textures, &pwTextures))
	 throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing ship1"));
	
	//explosion
	if (!explosion.initialize(graphics, explosionNS::WIDTH, explosionNS::HEIGHT, explosionNS::TEXTURE_COLS, &enemyTextures))
	 throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing explosion"));

	// enemyShip
	if (!enemyList.initialize(this, &enemyTextures, &stage, text, &bulletship, &lasership))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing small1"));

	// enemyBullets
	if (!em_BulletList.initialize(&enemyList, &bulletship, &lasership))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing small1"));

	if (!pwM.initialize(this, powerupNS::WIDTH, powerupNS::HEIGHT, powerupNS::TEXTURE_COLS, &pwTextures))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing power ups"));

	text->initialize(graphics);
	if (!map2.initialize(this, 0, 0, 1, &mapTexture, stage))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing second map"));

	map.setVelocity(VECTOR2(mapNS::SPEED, mapNS::SPEED));
	map2.setVelocity(VECTOR2(mapNS::SPEED, mapNS::SPEED));
	map.setY((float) GAME_HEIGHT - map.getHeight() + 369);
	map2.setY((float)GAME_HEIGHT - map.getHeight() - map.getHeight() + 369 + 184);
	pw1.setFrames(0, 1);
	pw1.setCurrentFrame(1);
	pw1.setVelocity(VECTOR2(30, 30));

	//bulletship
	bulletship.setX(GAME_WIDTH / 2);
	bulletship.setY(GAME_HEIGHT / 1.5);
	bulletship.setVelocity(VECTOR2(bulletshipNS::SPEED, bulletshipNS::SPEED)); // VECTOR2(X, Y)
	bulletship.setFrames(bulletshipNS::SHIP_START_FRAME, bulletshipNS::SHIP_END_FRAME);
	bulletship.setCurrentFrame(bulletshipNS::SHIP_START_FRAME);
	bulletship.setScale(0.6);
	
	//lasership
	lasership.setX(GAME_WIDTH / 3);
	lasership.setY(GAME_HEIGHT / 1.5);
	lasership.setVelocity(VECTOR2(lasershipNS::SPEED, lasershipNS::SPEED)); // VECTOR2(X, Y)
	lasership.setFrames(lasershipNS::SHIP_START_FRAME, lasershipNS::SHIP_END_FRAME);
	lasership.setCurrentFrame(lasershipNS::SHIP_START_FRAME);
	lasership.setScale(0.6);

	//explosion
	explosion.setFrames(explosionNS::START_FRAME, explosionNS::END_FRAME);
	explosion.setCurrentFrame(explosionNS::START_FRAME);
	explosion.setFrameDelay(explosionNS::ANIMATION_DELAY);
	explosion.setLoop(false);                  // do not loop animation

	text->initialize(graphics);

	//audio->playCue(INTRO);

    return;
}

//=============================================================================
// Update all game items
//=============================================================================
void Letitrain::update()
{
	bulletship.update(frameTime, explosion);
	lasership.update(frameTime, explosion);
	map.update(frameTime*timeModifier, this, stage);
	map2.update(frameTime*timeModifier, this, stage);
	enemyList.update(frameTime*timeModifier, this, &enemyTextures, &stage);
	em_BulletList.update(frameTime*timeModifier, this, &enemyTextures);
    pwM.update(frameTime*timeModifier,bulletship, lasership);
	//missileList.bulletship_update(frameTime, input, this, missileNS::WIDTH, missileNS::HEIGHT, missileNS::MISSILE_TEXTURE_COLS, &weaponTextures, bulletship.getX() + 20, bulletship.getY());
    bulletList.update(frameTime, input, this, bulletNS::WIDTH, bulletNS::HEIGHT, bulletNS::BULLET_TEXTURE_COLS, &weaponTextures,bulletship.getX() + bulletship.getWidth() / 4, bulletship.getY(), bulletship);
	laserList.update(frameTime, input, this, laserNS::WIDTH, laserNS::HEIGHT, laserNS::LASER_TEXTURE_COLS, &weaponTextures, lasership.getX()+lasership.getWidth()/4, lasership.getY(), lasership);

	bulletshipHealth = bulletship.getHealth();
	lasershipHealth = lasership.getHealth();

}


//=============================================================================
// Artificial Intelligence
//=============================================================================
void Letitrain::ai()
{
	enemyList.ai();
}

//=============================================================================
// Handle collisions
//=============================================================================
void Letitrain::collisions()
{
    VECTOR2 collisionVector;
	if (bulletship.collidesWith(lasership, collisionVector))
	{
		VECTOR2 direction = VECTOR2(bulletship.getX() - lasership.getX(), bulletship.getY() - lasership.getY());
		VECTOR2 direction2 = VECTOR2(lasership.getX() - bulletship.getX(), lasership.getY() - bulletship.getY());
		bulletship.setX(bulletship.getX() + frameTime*direction.x * 70);
		bulletship.setY(bulletship.getY() + frameTime*direction.y * 70);
		lasership.setX(lasership.getX() + frameTime*direction2.x * 70);
		lasership.setY(lasership.getY() + frameTime*direction2.y * 70);
	}

	enemyList.collisions();
	em_BulletList.collisions();
	pwM.collisions(&bulletship, this, &pwTextures);
	pwM.collisions(&lasership, this);
	bulletList.collisions(&enemyList);
	laserList.collisions(&enemyList);

}

//=============================================================================
// Render game items
//=============================================================================
void Letitrain::render()
{
    //graphics->spriteBegin();                // begin drawing sprites


	//map.draw();
	//map2.draw();

	pw1.draw();
	pwM.render();

	bulletList.render();
	laserList.render();

  
	bulletship.draw(explosion);
	lasership.draw(explosion);
	enemyList.render();
	em_BulletList.render();

	if (bulletshipHealth > 0)
	{
		heart1.draw();
		if (bulletshipHealth > 1)
		{
			heart2.draw();
			if (bulletshipHealth > 2)
				heart3.draw();
		}
	}
	pause.draw();

	if (bulletshipHealth == 0)
	{
		gameOver.draw();
		audio->stopCue(BEATDOWN);
		audio->stopCue(INTRO);
		audio->playCue(PIANO);
		gameover = true;
	}

	bool check = enemyList.getCarrier()->getAlive();
	bool check2 = (enemyList.getCarrier()->getHealth() <= 0);
	//if (&CarrierShip::EnemyShip::getAlive == false && &CarrierShip::EnemyShip::getActive == false
	if (!enemyList.getCarrier()->getAlive() && !(enemyList.getCarrier()->getHealth() <= 0) && stage == 3)
	{
		DWORD timer = GetTickCount();
		congratulations.draw();
		audio->stopCue(BEATDOWN);
		audio->stopCue(INTRO);
		while (!gameover)
		{
			if (GetTickCount() - timer > 50)
			{
				audio->playCue(FINISH);
				gameover = true;
			}
		}
	}


	text->render();

    //graphics->spriteEnd();                  // end drawing sprites
}

//=============================================================================
// The graphics device was lost.
// Release all reserved video memory so graphics device may be reset.
//=============================================================================
void Letitrain::releaseAll()
{
	mapTexture.onLostDevice();
	enemyTextures.onLostDevice();
	pwTextures.onLostDevice();
	playershipTextures.onLostDevice();
	heartTexture.onLostDevice();
	pauseTexture.onLostDevice();
	gameOverTexture.onLostDevice();
	congratulationsTexture.onLostDevice();

	text->releaseAll();

    Game::releaseAll();
    return;
}

//=============================================================================
// The grahics device has been reset.
// Recreate all surfaces.
//=============================================================================
void Letitrain::resetAll()
{
    mapTexture.onResetDevice();
	enemyTextures.onResetDevice();
	pwTextures.onResetDevice();
	playershipTextures.onResetDevice();
	heartTexture.onResetDevice();
	pauseTexture.onResetDevice();
	gameOverTexture.onResetDevice();
	congratulationsTexture.onResetDevice();
	text->resetAll();

    Game::resetAll();
    return;
}