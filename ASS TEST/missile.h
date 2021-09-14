//  Module:             Gameplay Programming
//  Assignment1:        LET IT RAIN
//  Student Name:       Zhuang Yuteng
//  Student Number:     10163964C
#ifndef _MISSILE_H                 // Prevent multiple definitions if this 
#define _MISSILE_H                 // file is included in more than one place
#define WIN32_LEAN_AND_MEAN

#include "entity.h"
#include "constants.h"


namespace missileNS
{
	const float WIDTH = 11;                   // image width
	const float HEIGHT = 16;                  // image height
	const int X = GAME_WIDTH / 2 - WIDTH / 2;   // location on screen
	const int Y = GAME_HEIGHT / 2 - HEIGHT / 2;
	const int   MISSILE_TEXTURE_COLS = 1;           // texture has 8 columns
	const float   MISSILE_START_FRAME = 4;      // ship1 starts at frame 0
	const float   MISSILE_END_FRAME = 4;        // ship1 end at frame 0
	const float MISSILE_ANIMATION_DELAY = 0.2f;    // time between frames
	const float MISSILE_SPEED = 2;
	const float ROTATION_RATE =180.0f; // radians per second
}

// inherits from Entity class
class Missile : public Entity
{

private:
	VECTOR2 direction;
	VECTOR2 current;
	float angle;
public:
	// constructor
	Missile();

	// inherited member functions
	virtual void draw();
	virtual bool initialize(Game *gamePtr, int width, int height, int ncols,
		TextureManager *textureM);
	void update(float frameTime,float xPosition, float yPosition);
	void damage(WEAPON);

};
#endif

