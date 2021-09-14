//  Module:             Gameplay Programming
//  Assignment1:        LET IT RAIN
//  Student Name:       Zhuang Yuteng
//  Student Number:     10163964C
#ifndef _LASER_H                 // Prevent multiple definitions if this 
#define _LASER_H                 // file is included in more than one place
#define WIN32_LEAN_AND_MEAN

#include "entity.h"
#include "constants.h"

namespace laserNS
{
	const float WIDTH = 14;                   // image width
	const float HEIGHT = 24;                  // image height
	const int X = GAME_WIDTH / 2 - WIDTH / 2;   // location on screen
	const int Y = GAME_HEIGHT / 2 - HEIGHT / 2;
	const int   LASER_TEXTURE_COLS = 2;           // texture has 8 columns
	const float  LASER_START_FRAME = 2;      // ship1 starts at frame 0
	const float   LASER_END_FRAME = 2;        // ship1 end at frame 0
	const float LASER_ANIMATION_DELAY = 0.2f;    // time between frames
	const float LASER_SPEED = 100;
}

// inherits from Entity class
class Laser : public Entity
{


public:
	// constructor
	Laser();

	// inherited member functions
	virtual void draw();
	virtual bool initialize(Game *gamePtr, int width, int height, int ncols,
		TextureManager *textureM, int level);
	void update(float frameTime);
	void damage(WEAPON);

};
#endif

