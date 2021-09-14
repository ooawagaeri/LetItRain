// Programming 2D Games
// Copyright (c) 2011 by: 
// Charles Kelly
// Draw animated spaceships with collision and shield
// Chapter 6 spacewar.cpp v1.0
// This class is the core of the game

#include "spaceWar.h"
#include "threeCsDX.h"

//=============================================================================
// Constructor
//=============================================================================
ThreeCsDX *text = NULL;

Spacewar::Spacewar()
{ 
	text = new ThreeCsDX;
}

//=============================================================================
// Destructor
//=============================================================================
Spacewar::~Spacewar()
{
    releaseAll();           // call onLostDevice() for every graphics item
}

//=============================================================================
// Initializes the game
// Throws GameError on error
//=============================================================================
void Spacewar::initialize(HWND hwnd)
{
    Game::initialize(hwnd); // throws GameError

    // nebula texture
    if (!nebulaTexture.initialize(graphics,NEBULA_IMAGE))
        throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing nebula texture"));

    // main game textures
    if (!gameTextures.initialize(graphics,TEXTURES_IMAGE))
        throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing game textures"));
	
    // playership textures
    if (!playershipTextures.initialize(graphics, PLAYERSHIP_IMAGE))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing game textures"));

    // nebula image
    if (!nebula.initialize(graphics,0,0,0,&nebulaTexture))
        throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing nebula"));

    // planet
    if (!planet.initialize(this, planetNS::WIDTH, planetNS::HEIGHT, 2, &gameTextures))
        throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing planet"));
	
	
    // bulletship
    if (!bulletship.initialize(this, bulletshipNS::WIDTH, bulletshipNS::HEIGHT, bulletshipNS::TEXTURE_COLS, &playershipTextures))
	throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing ship1"));

    //lasership
    if (!lasership.initialize(this, lasershipNS::WIDTH, lasershipNS::HEIGHT, lasershipNS::TEXTURE_COLS, &playershipTextures))
	throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing ship1"));


    // ship
    if (!ship1.initialize(this, shipNS::WIDTH, shipNS::HEIGHT, shipNS::TEXTURE_COLS, &gameTextures))
        throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing ship1"));
    ship1.setFrames(shipNS::SHIP1_START_FRAME, shipNS::SHIP1_END_FRAME);
    ship1.setCurrentFrame(shipNS::SHIP1_START_FRAME);
    ship1.setX(GAME_WIDTH/4);
    ship1.setY(GAME_HEIGHT/4);
    ship1.setVelocity(VECTOR2(shipNS::SPEED,-shipNS::SPEED)); // VECTOR2(X, Y)
    // ship2
    if (!ship2.initialize(this, shipNS::WIDTH, shipNS::HEIGHT, shipNS::TEXTURE_COLS, &gameTextures))
        throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing ship2"));
    ship2.setFrames(shipNS::SHIP2_START_FRAME, shipNS::SHIP2_END_FRAME);
    ship2.setCurrentFrame(shipNS::SHIP2_START_FRAME);
    ship2.setX(GAME_WIDTH - GAME_WIDTH/4);
    ship2.setY(GAME_HEIGHT/4);
    ship2.setVelocity(VECTOR2(-shipNS::SPEED,-shipNS::SPEED)); // VECTOR2(X, Y)
	
	
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

	text->initialize(graphics);

    return;
}

//=============================================================================
// Update all game items
//=============================================================================
void Spacewar::update()
{
    planet.update(frameTime);
    ship1.update(frameTime);
	bulletship.update(frameTime);
	lasership.update(frameTime);
    //ship2.update(frameTime);
}

//=============================================================================
// Artificial Intelligence
//=============================================================================
void Spacewar::ai()
{}

//=============================================================================
// Handle collisions
//=============================================================================
void Spacewar::collisions()
{
    VECTOR2 collisionVector;
    // if collision between ship and planet
    if(ship1.collidesWith(planet, collisionVector))
    {
        // bounce off planet
        ship1.bounce(collisionVector, planet);
        ship1.damage(PLANET);
    }
    if(ship2.collidesWith(planet, collisionVector))
    {
        // bounce off planet
        ship2.bounce(collisionVector, planet);
        ship2.damage(PLANET);
    }
    // if collision between ships
    if(ship1.collidesWith(ship2, collisionVector))
    {
        // bounce off ship
        ship1.bounce(collisionVector, ship2);
        ship1.damage(SHIP);
        // change the direction of the collisionVector for ship2
        ship2.bounce(collisionVector*-1, ship1);
        ship2.damage(SHIP);
    }
}

//=============================================================================
// Render game items
//=============================================================================
void Spacewar::render()
{
    graphics->spriteBegin();                // begin drawing sprites

    nebula.draw();                          // add the orion nebula to the scene
    planet.draw();                          // add the planet to the scene
    ship1.draw();                           // add the spaceship to the scene
    bulletship.draw();
    lasership.draw();
    //ship2.draw();                           // add the spaceship to the scene

	text->render();

    graphics->spriteEnd();                  // end drawing sprites
}

//=============================================================================
// The graphics device was lost.
// Release all reserved video memory so graphics device may be reset.
//=============================================================================
void Spacewar::releaseAll()
{
    nebulaTexture.onLostDevice();
    gameTextures.onLostDevice();
	playershipTextures.onLostDevice();

	text->releaseAll();

    Game::releaseAll();
    return;
}

//=============================================================================
// The grahics device has been reset.
// Recreate all surfaces.
//=============================================================================
void Spacewar::resetAll()
{
    gameTextures.onResetDevice();
    nebulaTexture.onResetDevice();
	playershipTextures.onResetDevice();

	text->resetAll();

    Game::resetAll();
    return;
}
