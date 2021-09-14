//  Module:             Gameplay Programming
//  Assignment1:        LET IT RAIN
//  Student Name:       Timothy Chua
//  Student Number:     10165581F

#pragma once
#include "gruntShip.h"
#include "hunterShip.h"
#include "carrierShip.h"
//#include "spawnPosition.h"
#include "spawner.h"
#include "textManager.h"
#include <vector>

typedef std::vector<GruntShip *> GRUNTSHIP;
typedef std::vector<HunterShip *> HUNTERSHIP;

class EnemyManager
{
private:
	GRUNTSHIP gruntCollection;
	HUNTERSHIP hunterCollection;
	CarrierShip *boss;
	//SpawnPosition *spawn;
	Spawner *spawner;

	GRUNTSHIP::iterator grunt;
	HUNTERSHIP::iterator hunter;

	Bulletship *bulletShip;
	Lasership *laserShip;

	textManager *scoring;

	int gruntSize;
	int hunterSize;
	int stage;

public:
	EnemyManager();

	bool initialize(Game *gamePtr, TextureManager *textureM, int *stage, textManager *score, Bulletship *ship1, Lasership *laserShip);
	void update(float frameTime, Game *gamePtr, TextureManager *textureM, int *stage);
	void ai();
	void collisions();
	void render();
	GRUNTSHIP *getGrunts() { return &gruntCollection; }
	HUNTERSHIP *getHunters() { return &hunterCollection; }
	CarrierShip *getCarrier() { return boss; }
};