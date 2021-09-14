//  Module:             Gameplay Programming
//  Assignment1:        LET IT RAIN
//  Student Name:       Timothy Chua
//  Student Number:     10165581F

#ifndef _ENEMY_SHIP_H 
#define _ENEMY_SHIP_H
#define WIN32_LEAN_AND_MEAN

#include "entity.h"
#include "constants.h"

namespace gruntShipNS
{
	const int	HEALTH = 16;
	const int	WIDTH = 86;
	const int	HEIGHT = 80;
	const double ROTATION = PI;
	const float SCALE = 0.8f;
	const int	X = GAME_WIDTH / 2 - WIDTH*SCALE / 2;
	const int	Y = 0 - HEIGHT*SCALE;
	const float SPEED = -100;
	const float MASS = 300.0f;
	const int   TEXTURE_COLS = 4;
	const int   START_FRAME = 0;
	const int   END_FRAME = 3;
	const float ANIMATION_DELAY = 0.2f;
	const float EXPLOSION_SCALE = 5.0f;

	const int   DAMAGE_TEXTURE_COLS = 8;
	const int   DAMAGE_START_FRAME = 4;
	const int   DAMAGE_END_FRAME = 7;
	const float DAMAGE_ANIMATION_DELAY = 0.03f;
}

namespace hunterShipNS
{
	const int	HEALTH = 50;
	const int	WIDTH = 168;
	const int	HEIGHT = 80;
	const double ROTATION = PI;
	const float SCALE = 1.1f;
	const int	X = GAME_WIDTH / 2 - WIDTH*SCALE / 2;
	const int	Y = 0 - HEIGHT*SCALE;
	const float SPEED = -30.0f;
	const float MASS = 400.0f;
	const int   TEXTURE_COLS = 4;
	const int   START_FRAME = 8;
	const int   END_FRAME = 11;
	const float ANIMATION_DELAY = 0.2f;
	const float EXPLOSION_SCALE = 10.0f;
	const int	FIRE_RATE = 3000;

	const int   DAMAGE_TEXTURE_COLS = 8;
	const int   DAMAGE_START_FRAME = 20;
	const int   DAMAGE_END_FRAME = 23;
	const float DAMAGE_ANIMATION_DELAY = 0.03f;
}

namespace carrierShipNS
{
	const int	HEALTH = 2000;
	const int	WIDTH = 273;
	const int	HEIGHT = 303;
	const double ROTATION = 0;
	const float SCALE = 1.8f;
	const int	X = GAME_WIDTH / 2 - WIDTH*SCALE /2;
	const int	Y = -2 * HEIGHT;
	const float SPEED = -20;
	const float	X_SPEED = 0;
	const float MASS = 1000.0f;
	const int   TEXTURE_COLS = 4;
	const int   START_FRAME = 4;
	const int   END_FRAME = 7;
	const float ANIMATION_DELAY = 0.2f;
	const float EXPLOSION_SCALE = 20.0f;
	const int	FIRE_RATE = 1000;

	const int   DAMAGE_TEXTURE_COLS = 8;
	const int   DAMAGE_START_FRAME = 12;
	const int   DAMAGE_END_FRAME = 15;
	const float DAMAGE_ANIMATION_DELAY = 0.05f;

	const int	HEALTHBAR_Y = GAME_HEIGHT / 16;
	const int	HEALTHBAR_X = GAME_WIDTH / 2;
}

namespace explosionNS
{
	const int	WIDTH = 86;
	const int	HEIGHT = 80;
	const int   TEXTURE_COLS = 12;
	const int   START_FRAME = 12;    // shield start frame
	const int   END_FRAME = 23;      // shield end frame
	const float ANIMATION_DELAY = 0.05f; // time between frames
}

namespace enemyBulletNS
{
	const float	WIDTH = 23;                   // image width
	const float	HEIGHT = 23;                  // image height
	const int	X = GAME_WIDTH / 2 - WIDTH / 2;   // location on screen
	const int	Y = GAME_HEIGHT / 2 - HEIGHT / 2;
	const int	TEXTURE_COLS = 31;           // texture has 8 columns
	const float	START_FRAME = 30;      // ship1 starts at frame 0
	const float	END_FRAME = 30;        // ship1 end at frame 0
	const float	ANIMATION_DELAY = 0.2f;    // time between frames
	const float	SPEED = 100;

}

namespace healthBoarderNS
{
	const int   WIDTH = 403;       // each texture size
	const int   HEIGHT = 32;       // each texture size
	const int   TEXTURE_COLS = 2;       // texture columns
	const int   FRAME = 17;     // the outer frame number of the bar
}

class EnemyShip : public Entity
{
protected:
	int		health;
	bool	alive;
	bool	outOfBound;
	bool	explosionOn;
	Image	explosion;
	bool	bulletOn;
	DWORD	timer;
	bool	missileOn;
	bool	damagedOn;
	Image	damaged;
	VECTOR2 nearestTarget;

public:
	// constructor
	EnemyShip();

	// inherited member functions
	virtual bool initialize(Game *gamePtr, int width, int height, int ncols,
		TextureManager *textureM);
	virtual void update(float frameTime);
	virtual void ai(Entity &ship1, Entity &ship2);
	void	draw();
	void	damage(WEAPON);
	void	setAlive(bool value) { alive = value; }
	bool	getAlive() { return alive; }
	bool	getOutOfBound() { return outOfBound; }
	VECTOR2	*getTarget() { return &nearestTarget; }
	bool	getBullet() { return bulletOn; }
	void	setTimer(DWORD value) { timer = value; }
	DWORD	getTimer() { return timer; }
};
#endif