//  Module:             Gameplay Programming
//  Assignment1:        LET IT RAIN
//  Student Name:       Timothy Chua
//  Student Number:     10165581F

#ifndef _CARRIER_ENEMY_SHIP_H 
#define _CARRIER_ENEMY_SHIP_H
#define WIN32_LEAN_AND_MEAN

#include "enemyShip.h"
#include "dashboard.h"

class CarrierShip : public EnemyShip
{
private:
	int		movementSet;
	DWORD	movementTimer;
	float	rotation;			// bullet spiral rotations
	bool	spiralOn;
	int		originalHealth;
	Bar		healthBar;
	Image	healthBoarder;
	bool	healthOn;

public:
	// constructor
	CarrierShip();

	// inherited member functions
	bool initialize(Game *gamePtr, int width, int height, int ncols,
		TextureManager *textureM);
	void ai(Entity *ship1, Entity *ship2);
	void draw();
	void damage(WEAPON weapon);
	float getRadian() { return (rotation * PI) / 180; }
	float getRotation() { return rotation; }
	void setRotation(float value) 
	{ 
		rotation = value;
		if (rotation > 360)
			rotation -= 360;
	}
	bool getSpiral() { return spiralOn; }
};
#endif
