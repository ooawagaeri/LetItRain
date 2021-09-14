//  Module:             Gameplay Programming
//  Assignment1:        LET IT RAIN
//  Student Name:       Daniel Lee
//  Student Number:     10162739H

#pragma once
#include "powerup.h"
#include "spawnPosition.h"
#include <vector>
#include <thread>

typedef std::vector<PowerUp *> POWERUPS;

class PowerupManager
{
private:
	POWERUPS powerupCollection;
	SpawnPosition *spawn;
	POWERUPS::iterator powerup;
	std::thread slowMo;
	bool slowMoThreadDone;
	std::thread bulletshipShield;
	bool bulletshipShieldDone;
	std::thread lasershipShield;
	bool lasershipShieldDone;
	float count;
public:
	PowerupManager();

	bool initialize(Game *gamePtr, int width, int height, int ncols,
		TextureManager *textureM);
	void update(float frameTime, Bulletship bship, Lasership lship);
	void ai();
	void powerupTimer(Game *gamePtr);
	void powerupBulletshipShield(Bulletship *bship);
	void powerupLasershipShield(Lasership *lship);
	void detachThread();
	void collisions(Bulletship *ship, Game *gamePtr, TextureManager *textureM);
	void collisions(Lasership *ship, Game *gamePtr);
	void render();
	bool getSlowMoThreadDone() { return slowMoThreadDone; }
	bool getBulletshipShield() { return bulletshipShieldDone; }
	bool getLasershipShield() { return lasershipShieldDone; }
};