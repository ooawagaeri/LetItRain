//  Module:             Gameplay Programming
//  Assignment1:        LET IT RAIN
//  Student Name:       Zhuang Yuteng
//  Student Number:     10163964C
#pragma once
#include <vector>
#include "laser.h"
#include "lasership.h"
#include "enemyManager.h"
using std::vector;



class LaserManager
{

private:
	std::vector<Laser *> laser_collection;
	DWORD Tick;


public:
	LaserManager();

	bool initialize(Game *gamePtr, int width, int height, int ncols,
		TextureManager *textureM, float X, float Y, Lasership lship);
	void update(float frameTime, Input *input, Game *gamePtr, int width, int height, int ncols,
		TextureManager *textureM, float X, float Y, Lasership lship);
	void ai();
	void collisions(EnemyManager *enemyList);
	void render();

};