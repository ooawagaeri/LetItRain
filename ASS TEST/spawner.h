//  Module:             Gameplay Programming
//  Assignment1:        LET IT RAIN
//  Student Name:       Timothy Chua
//  Student Number:     10165581F

#pragma once
#include "enemyShip.h"
#include "gruntShip.h"
#include "powerup.h"
#include <queue>

struct d4Hunter {
	FLOAT x;
	FLOAT y;
	float rotation;
	float x_speed;
	float y_speed;
};
struct d4PowerUp {
	FLOAT x;
	FLOAT y;
};

class Spawner
{
private:
	std::queue<VECTOR2> gruntSpawn;
	std::queue<d4Hunter> hunterSpawn;
	std::queue<d4PowerUp> spawn;				// power ups list

public:
	Spawner();

	bool initialize(int stage);
	void loadStage1();
	void loadStage2();
	void loadStage3();

	d4PowerUp getValue();
	VECTOR2 getGrunt();
	d4Hunter getHunter();

	void clear();

	int gruntSize() { return gruntSpawn.size(); }
	int hunterSize() { return hunterSpawn.size(); }
	int spawnSize() { return spawn.size(); }

	bool gruntEmpty() {	return gruntSpawn.empty();	}
	bool hunterEmpty() { return hunterSpawn.empty(); }
	bool spawnEmpty() { return spawn.empty(); }
};