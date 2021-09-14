//  Module:             Gameplay Programming
//  Assignment1:        LET IT RAIN
//  Student Name:       Daniel Lee
//  Student Number:     10162739H

#ifndef _POWERUP_H                 // Prevent multiple definitions if this 
#define _POWERUP_H                 // file is included in more than one place
#define WIN32_LEAN_AND_MEAN

#include "entity.h"
#include "constants.h"
#include "ship.h"
#include "bulletship.h"
#include "lasership.h"

namespace powerupNS
{
	const int WIDTH = 32;
	const int HEIGHT = 32;
	//const int X = GAME_WIDTH / 2 - WIDTH / 2;
	//const int Y = 0 - HEIGHT;
	const float VELOCITY = 100;
	const int   TEXTURE_COLS = 5;
	const int   POWERUP_START_FRAME = 0;
	const int   POWERUP_END_FRAME = 4;
	const int	MAGNET_RADIUS = 100;
	const int	POWERUP_ATT = 0;
	const int	POWERUP_SPE = 1;
	const int	POWERUP_HP = 2;
	const int	POWERUP_SHIELD = 3;
	const int	POWERUP_SLOW = 4;
}

// inherits from Entity class
class PowerUp : public Entity
{
private:
	int type;
	Image text;
public:
	PowerUp();

	//virtual void draw();
	virtual bool initialize(Game *gamePtr, int width, int height, int ncols,
		TextureManager *textureM);
	//void update(float frameTime, Bulletship bship);
	void update(float frameTime, Bulletship bship, Lasership lship );
	int getType() { return type; }
	void setType(int s) { type = s; }
	void displayText(int type, Game *gamePtr, TextureManager *textureM);
	void hideIcon();

};
#endif
