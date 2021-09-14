//  Module:             Gameplay Programming
//  Assignment1:        LET IT RAIN
//  Student Name:       Zhuang Yuteng
//  Student Number:     10163964C
#include "laser.h"

//=============================================================================
// default constructor
//=============================================================================
Laser::Laser() : Entity()
{
	spriteData.width = laserNS::WIDTH;           // size of Ship1
	spriteData.height = laserNS::HEIGHT;
	spriteData.x = laserNS::X;                   // location on screen
	spriteData.y = laserNS::Y;
	spriteData.rect.bottom = laserNS::HEIGHT;    // rectangle to select parts of an image
	spriteData.rect.right = laserNS::WIDTH;
	velocity.x = 0;                             // velocity X
	velocity.y = 0;                             // velocity Y
	frameDelay = laserNS::LASER_ANIMATION_DELAY;
	startFrame = laserNS::LASER_START_FRAME;     // first frame of ship animation
	endFrame = laserNS::LASER_END_FRAME;     // last frame of ship animation
	currentFrame = 1;
	radius = laserNS::WIDTH / 2.0;
	collisionType = entityNS::CIRCLE;
}

//=============================================================================
// Initialize the Ship.
// Post: returns true if successful, false if failed
//=============================================================================
bool Laser::initialize(Game *gamePtr, int width, int height, int ncols,
	TextureManager *textureM, int level)
{
	if (level == 2) {
		spriteData.scale = 2.0f;
		spriteData.width = laserNS::WIDTH* 2.0f;
		spriteData.height = laserNS::HEIGHT*2.0f;
	}
	else if (level == 3) {
		spriteData.scale = 3.0f;
		spriteData.width = laserNS::WIDTH* 3.0f;
		spriteData.height = laserNS::HEIGHT*3.0f;
	}

	return(Entity::initialize(gamePtr, width, height, ncols, textureM));
}

//=============================================================================
// draw the ship
//=============================================================================
void Laser::draw()
{
	Image::draw();              // draw ship

}

//=============================================================================
// update
// typically called once per frame
// frameTime is used to regulate the speed of movement and animation
//=============================================================================
void Laser::update(float frameTime)
{
	Entity::update(frameTime);


	spriteData.y += frameTime * (-velocity.y);         // move ship along y

}








