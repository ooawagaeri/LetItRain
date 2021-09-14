//  Module:             Gameplay Programming
//  Assignment1:        LET IT RAIN
//  Student Name:       Timothy Chua
//  Student Number:     10165581F

#pragma once
#include "enemyBullet.h"
#include "enemyManager.h"
#include <vector>

typedef std::vector<EnemyBullet *> EM_BULLETLIST;

class EnemyBulletManager
{
private:
	EM_BULLETLIST hunterBullets;
	EM_BULLETLIST carrierBullets;

	HUNTERSHIP	*hunterCollection;
	CarrierShip *boss;
	Bulletship	*bulletShip;
	Lasership	*laserShip;

	HUNTERSHIP::iterator hunter;
	EM_BULLETLIST::iterator bullet;

public:
	EnemyBulletManager();

	bool initialize(EnemyManager *enemyList, Bulletship *ship1, Lasership *ship2);
	bool initialize(Game *gamePtr, TextureManager *textureM, EnemyShip *enemy);
	bool initialize(Game *gamePtr, TextureManager *textureM, EnemyShip *enemy, int x);
	void update(float, Game *gamePtr, TextureManager *textureM);
	void ai();
	void collisions();
	void render();
};