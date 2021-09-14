//  Module:             Gameplay Programming
//  Assignment1:        LET IT RAIN
//  Student Name:       Zhuang Yuteng
//  Student Number:     10163964C
#pragma once
#include <vector>
#include "bullet.h"
#include "enemyManager.h"
using std::vector;

typedef std::vector<Bullet *> BULLETLIST;

class BulletManager
{
private:
	std::vector<Bullet *> bullet_collection;
	DWORD Tick;

public:
	BulletManager();

	bool initialize(Game *gamePtr, int width, int height, int ncols,
		TextureManager *textureM, float X, float Y, float xVelocity, int frame);
	void update(float frameTime, Input *input, Game *gamePtr, int width, int height, int ncols,
		TextureManager *textureM, float X, float Y, Bulletship bship);
	void ai();
	void collisions(EnemyManager *enemyList);
	void render();

};