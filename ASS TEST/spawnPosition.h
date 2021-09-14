//  Module:             Gameplay Programming
//  Assignment1:        LET IT RAIN
//  Student Name:       Timothy Chua
//  Student Number:     10165581F

#pragma once

#define GRUNT_SPAWN_AXIS 2
#define HUNTER_SPAWN_AXIS 5
#define POWERUP_SPAWN_AXIS 3
#define GRUNT_MAX_SIZE 35 //40 is total
#define HUNTER_MAX_SIZE 8
#define POWERUP_MAX_SIZE 10
#include "enemyShip.h"
#include "gruntShip.h"
#include "powerup.h"

class SpawnPosition
{
private:
	float gruntSpawn[GRUNT_MAX_SIZE][24];
	float hunterSpawn[HUNTER_MAX_SIZE][HUNTER_SPAWN_AXIS];
	float powerupSpawn[POWERUP_MAX_SIZE][POWERUP_SPAWN_AXIS];
public:
	SpawnPosition();
	SpawnPosition(int type);

	void loadPowerUpValues(float p[][POWERUP_SPAWN_AXIS]);
	float getPowerUp(int no, int xy);
	void loadGrunts(float p[][GRUNT_SPAWN_AXIS]);
	void loadHunters(float p[][HUNTER_SPAWN_AXIS]);
	float getGrunt(int no, int xy);
	float getHunter(int no, int xy);
	void loadStage1(float p[][24]);
};
