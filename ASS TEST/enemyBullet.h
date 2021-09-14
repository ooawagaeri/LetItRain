//  Module:             Gameplay Programming
//  Assignment1:        LET IT RAIN
//  Student Name:       Timothy Chua
//  Student Number:     10165581F

#ifndef _ENEMY_BULLET_H                 // Prevent multiple definitions if this 
#define _ENEMY_BULLET_H                 // file is included in more than one place
#define WIN32_LEAN_AND_MEAN

#include "entity.h"
#include "constants.h"
#include "enemyShip.h"
#include "bullet.h"

// inherits from Entity class
class EnemyBullet : public Bullet
{
public:
	// constructor
	EnemyBullet();

	// inherited member functions
	//void update(float frameTime);
};
#endif

