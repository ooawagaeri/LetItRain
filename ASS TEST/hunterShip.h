//  Module:             Gameplay Programming
//  Assignment1:        LET IT RAIN
//  Student Name:       Timothy Chua
//  Student Number:     10165581F

#ifndef _HUNTER_ENEMY_SHIP_H 
#define _HUNTER_ENEMY_SHIP_H
#define WIN32_LEAN_AND_MEAN

#include "enemyShip.h"

class HunterShip : public EnemyShip
{
public:
	// constructor
	HunterShip();

	// inherited member functions
	bool initialize(Game *gamePtr, int width, int height, int ncols,
		TextureManager *textureM);
	void update(float frameTime);
};
#endif
