//  Module:             Gameplay Programming
//  Assignment1:        LET IT RAIN
//  Student Name:       Zhuang Yuteng
//  Student Number:     10163964C
#include "bullet.h"

//=============================================================================
// default constructor
//=============================================================================
Bullet::Bullet() : Entity()
{
	spriteData.width = bulletNS::WIDTH;           // size of Ship1
	spriteData.height = bulletNS::HEIGHT;
	spriteData.x = bulletNS::X;                   // location on screen
	spriteData.y = bulletNS::Y;
	spriteData.rect.bottom = bulletNS::HEIGHT;    // rectangle to select parts of an image
	spriteData.rect.right = bulletNS::WIDTH;
	velocity.x = 0;                             // velocity X
	velocity.y = 0;                             // velocity Y
	frameDelay = bulletNS::BULLET_ANIMATION_DELAY;
	startFrame = bulletNS::BULLET_START_FRAME;     // first frame of ship animation
	endFrame = bulletNS::BULLET_END_FRAME;     // last frame of ship animation
	currentFrame = startFrame;
	radius = bulletNS::WIDTH / 2.0;	
	collisionType = entityNS::CIRCLE;
	
}

//=============================================================================
// Initialize the Ship.
// Post: returns true if successful, false if failed
//=============================================================================
bool Bullet::initialize(Game *gamePtr, int width, int height, int ncols,
	TextureManager *textureM)
{
	return(Entity::initialize(gamePtr, width, height, ncols, textureM));
}

//=============================================================================
// draw the ship
//=============================================================================
void Bullet::draw()
{
	Image::draw();              // draw ship

}

//=============================================================================
// update
// typically called once per frame
// frameTime is used to regulate the speed of movement and animation
//=============================================================================
void Bullet::update(float frameTime)
{
	if (spriteData.x < 0 || spriteData.x + spriteData.width > GAME_WIDTH || spriteData.y > GAME_HEIGHT || spriteData.y + spriteData.height < 0)
		active = false;
	
	Entity::update(frameTime);

	spriteData.y += frameTime * (-velocity.y);         // move ship along y
	spriteData.x += frameTime * (-velocity.x);
	
}








