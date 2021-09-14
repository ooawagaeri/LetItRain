// Programming 2D Games
// Copyright (c) 2011 by: 
// Charles Kelly
// Draw animated spaceships with collision and shield
// Chapter 6 spacewar.cpp v1.0
// This class is the core of the game

#include "letitrain.h"
#include "threeCsDX.h"

//=============================================================================
// Constructor
//=============================================================================
ThreeCsDX *text = NULL;

Letitrain::Letitrain()
{ 
	text = new ThreeCsDX;
}

//=============================================================================
// Destructor
//=============================================================================
Letitrain::~Letitrain()
{
    releaseAll();           // call onLostDevice() for every graphics item
}

//=============================================================================
// Initializes the game
// Throws GameError on error
//=============================================================================
void Letitrain::initialize(HWND hwnd)
{
    Game::initialize(hwnd); // throws GameError

    // nebula texture
    if (!mapTexture.initialize(graphics,MAP_IMAGE))
        throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing map texture"));

    // main game textures
    if (!gameTextures.initialize(graphics,TEXTURES_IMAGE))
        throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing game textures"));

	// power up texture
	if (!pwTextures.initialize(graphics, PW_IMAGE))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing power up texture"));

	// power up image
	//if (!pw1.initialize(this, 32, 32, 4, &pwTextures))
		//throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing pw1"));

  // map image
    if (!map.initialize(this,0,0,mapNS::TEXTURE_COLS,&mapTexture))
        throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing map"));
	// ship
	if (!ship1.initialize(this, shipNS::WIDTH, shipNS::HEIGHT, shipNS::TEXTURE_COLS, &gameTextures))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing ship1"));

	// enemyShip textures
	if (!gruntTexture.initialize(graphics, GRUNT_IMAGE))
		 throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing game textures"));

    // playership textures
	if (!playershipTextures.initialize(graphics, PLAYERSHIP_IMAGE))
	 throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing game textures"));

	// bulletship
	if (!bulletship.initialize(this, bulletshipNS::WIDTH, bulletshipNS::HEIGHT, bulletshipNS::TEXTURE_COLS, &playershipTextures))
	 throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing ship1"));
	
	 //lasership
	if (!lasership.initialize(this, lasershipNS::WIDTH, lasershipNS::HEIGHT, lasershipNS::TEXTURE_COLS, &playershipTextures))
	 throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing ship1"));

	ship1.setFrames(shipNS::SHIP1_START_FRAME, shipNS::SHIP1_END_FRAME);
	ship1.setCurrentFrame(shipNS::SHIP1_START_FRAME);

	// enemyShip
	if (!gruntList.initialize(this, &gruntTexture))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing small1"));

	ship1.setX(GAME_WIDTH / 4);
	ship1.setY(GAME_HEIGHT / 4);
	ship1.setVelocity(VECTOR2(shipNS::SPEED, -shipNS::SPEED)); // VECTOR2(X, Y)


	if (!pwM.initialize(this, 32, 32, 4, &pwTextures))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing power ups"));

	text->initialize(graphics);

	map.setVelocity(VECTOR2(mapNS::SPEED, mapNS::SPEED));
	map.setY((float) GAME_HEIGHT - map.getHeight());
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



    return;
}

//=============================================================================
// Update all game items
//=============================================================================
void Letitrain::update()
{
    ship1.update(frameTime);
	bulletship.update(frameTime);
	lasership.update(frameTime);
	map.update(frameTime);
	pw1.update(frameTime, bulletship, lasership);
	small1.update(frameTime);
	gruntList.update(frameTime);
  pwM.update(frameTime,bulletship, lasership);
}

//=============================================================================
// Artificial Intelligence
//=============================================================================
void Letitrain::ai()
{}

//=============================================================================
// Handle collisions
//=============================================================================
void Letitrain::collisions()
{
    VECTOR2 collisionVector;
    // if collision between ship and planet



	gruntList.collisions(&ship1);
	pwM.collisions(&bulletship);
	pwM.collisions(&lasership);
	//VECTOR2 collisionVector;
	//if collision between ship and planet
	//if(ship1.collidesWith(small1, collisionVector))
	//{
	//	small1.damage(SHIP);
	//}
}

//=============================================================================
// Render game items
//=============================================================================
void Letitrain::render()
{
    graphics->spriteBegin();                // begin drawing sprites

    map.draw();                          // add the orion nebula to the scene
    ship1.draw();                           // add the spaceship to the scene
	pw1.draw();
	bulletship.draw();
	lasership.draw();
	//if (small1.alive())
	//	small1.draw();
	gruntList.render();
	pwM.render();
	text->render();


    graphics->spriteEnd();                  // end drawing sprites
}

//=============================================================================
// The graphics device was lost.
// Release all reserved video memory so graphics device may be reset.
//=============================================================================
void Letitrain::releaseAll()
{
    mapTexture.onLostDevice();
    gameTextures.onLostDevice();
	pwTextures.onLostDevice();
	gruntTexture.onLostDevice();
	playershipTextures.onLostDevice();

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
    gameTextures.onResetDevice();
    mapTexture.onResetDevice();
	pwTextures.onResetDevice();
	gruntTexture.onResetDevice();
	playershipTextures.onResetDevice();
	text->resetAll();

    Game::resetAll();
    return;
}
