// Programming 2D Games
// Copyright (c) 2011 by: 
// Charles Kelly
// Chapter 6 spacewar.h v1.0

#ifndef _LETITRAIN_H             // Prevent multiple definitions if this 
#define _LETITRAIN_H             // file is included in more than one place
#define WIN32_LEAN_AND_MEAN

#pragma once
#include "game.h"
#include "textureManager.h"
#include "image.h"
#include "planet.h"
#include "ship.h"
#include "map.h"
#include "gruntShip.h"
#include "enemyManager.h"
#include "bulletship.h"
#include "lasership.h"
#include "powerupManager.h"
#include "bulletManager.h"
#include "laserManager.h"
#include "enemyBulletManager.h"


//=============================================================================
// This class is the core of the game
//=============================================================================
class Letitrain : public Game
{
private:
    // game items
    TextureManager mapTexture;   // nebula texture
    TextureManager pwTextures;
    TextureManager enemyTextures;
    TextureManager playershipTextures;
	TextureManager playership2Textures;
    TextureManager weaponTextures;
    TextureManager heartTexture;
    TextureManager pauseTexture;
	TextureManager gameOverTexture;
	TextureManager congratulationsTexture;

    Map     map;
    PowerUp pw1;
    PowerupManager pwM;
    Map		map2;

    BulletManager bulletList;
    LaserManager laserList;
    EnemyManager enemyList;
    EnemyBulletManager em_BulletList;
    Bulletship bulletship;
    Lasership lasership;
    int stage;
	bool gameover;
    Image explosion;
    Image heart1;
    Image heart2;
    Image heart3;
    Image pause;
	Image gameOver;
	Image congratulations;
	float bulletshipHealth;
	float lasershipHealth;



public:
    // Constructor
    Letitrain();

    // Destructor
    virtual ~Letitrain();

	// Initialize the game
	void initialize(Graphics *graphics, Input* input, Audio* audio, HWND *hwnd, HRESULT *hr, LARGE_INTEGER*timeStart, LARGE_INTEGER *timeEnd, LARGE_INTEGER *timerFreq, float *frameTime, float *fps,
		TextDX *dxFont, bool *fpsOn, DWORD *sleepTime, bool *paused, bool *initialized);
    // Initialize the game
    void update();      // must override pure virtual from Game
    void ai();          // "
    void collisions();  // "
    void render();      // "
    void releaseAll();
    void resetAll();
    int getTimeModifier() { return timeModifier; }
    void setTimeModifier(int a) { timeModifier = a; }
    void setPause(bool value) { paused = value; }
	void setGameOver(bool value) { gameover = value; }
    bool getPause() { return paused; }
	bool getGameOver() { return gameover; }

	EnemyManager getEMList() { return enemyList; }
};

#endif
