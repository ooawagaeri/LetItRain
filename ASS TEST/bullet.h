//  Module:             Gameplay Programming
//  Assignment1:        LET IT RAIN
//  Student Name:       Zhuang Yuteng
//  Student Number:     10163964C
#ifndef _BULLET_H                 // Prevent multiple definitions if this 
#define _BULLET_H                 // file is included in more than one place
#define WIN32_LEAN_AND_MEAN

#include "entity.h"
#include "constants.h"

namespace bulletNS
{
	const float WIDTH = 15;                   // image width
	const float HEIGHT = 17;                  // image height
	const int X = GAME_WIDTH / 2 - WIDTH / 2;   // location on screen
	const int Y = GAME_HEIGHT / 2 - HEIGHT / 2;
	const int   BULLET_TEXTURE_COLS = 5;           // texture has 8 columns
	const float   BULLET_START_FRAME = 2;      // ship1 starts at frame 0
	const float   BULLET_END_FRAME = 2;        // ship1 end at frame 0
	const float BULLET_ANIMATION_DELAY = 0.2f;    // time between frames
	const float BULLET_SPEED = 100;
	const float BULLET_X_SPEED = 30;
	const float BULLET_P1_LEFT = 1.0;
	const float BULLET_P1_RIGHT = -1.0;
	const float BULLET_P2_LEFT = 2;
	const float BULLET_P2_RIGHT = -2;
	const float BULLET_FRAME_STRAIGHT = 2;
	const float BULLET_FRAME_P1_LEFT = 1;
	const float BULLET_FRAME_P1_RIGHT = 3;
	const float BULLET_FRAME_P2_LEFT = 0;
	const float BULLET_FRAME_P2_RIGHT = 4;
}

// inherits from Entity class
class Bullet : public Entity
{
public:
	// constructor
	Bullet();

	// inherited member functions
	virtual void draw();
	virtual bool initialize(Game *gamePtr, int width, int height, int ncols,
		TextureManager *textureM);
	virtual void update(float frameTime);
	void damage(WEAPON);

};
#endif

